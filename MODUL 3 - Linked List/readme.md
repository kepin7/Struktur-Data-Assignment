# <h1 align="center">Laporan Praktikum Modul Linked List</h1>

<p align="center">Hizkia Kevin Octaviano - 2311102185</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

Linked list adalah sekumpulan elemen bertipe sama yang mempunyai keterurutan tertentu, yang setiap elemennya terdiri dari dua bagian. Linked list menggunakan satu variabel pointer untuk menyimpan banyak data. Tipe data pointer
bersifat dinamis, di mana variabel akan dialokasikan hanya saat dibutuhkan dan dapat direlokasikan kembali setelah tidak dibutuhkan[1]. 

Biasanya di dalam suatu linked list, terdapat istilah head dan tail.
- **Head** adalah elemen yang berada pada posisi pertama dalam suatu linked list[2].
- **Tail** adalah elemen yang berada pada posisi terakhir dalam suatu linked list[2].

### 1. Single Linked List:

Tempat yang disediakan pada
satu area memori tertentu untuk menyimpan data dikenal dengan sebutan node atau simpul. Setiap node memiliki pointer
yang menunjuk ke simpul berikutnya sehingga terbentuk satu
untaian, dengan demikian hanya diperlukan sebuah variabel pointer. Susunan berupa untaian semacam ini disebut single
linked list (NULL memiliki nilai khusus yang artinya tidak
menunjuk ke mana-mana. Biasanya, linked list pada titik akhirnya akan menunjuk ke NULL)[1].

Pembuatansingle linked listdapat dilakukan menggunakan dua jenis metode, yaitu:

- **LIFO** (last in first out), aplikasinya: stack (tumpukan)

adalah suatu metode pembuatan linked list, dimana data yang masuk paling akhir adalah data yang keluar paling awal[1].

- **FIFO** (first in first out), aplikasinya: queue (antrean)

adalah suatu metode pembuatan linked list, di mana data yang masuk paling awal adalah data yang keluar paling awal juga[1].

### 2. Double Linked List

Salah satu kelemahan single linked list adalah pointer
(penunjuk) hanya dapat bergerak satu arah, yaitu maju/mundur
atau kanan/kiri sehingga pencarian data pada single linked
list hanya dapat bergerak dalam satu arah. Untuk mengatasi
kelemahan ini, kita bisa menggunakan metode double linked
list. Linked list ini dikenal dengan nama linked list berpointer
ganda atau double linked list[1].

### 3. Circular Linked List

Circular Linked List merupakan suatu linked list dimana tail (node terakhir) menunjukan ke head (node pertama). jadi tidak ada pointer yang menunjukan NULL[1]. Ada 2 jenis circular linked list:

- Circular Single Linked List
- Circular Double Linked List

### 4. Multiple Linked List

Multiple linked list merupakan suatu linked list yang memiliki lebih dari 2 buah variable pointer[2].

### Perbedaan Karakteristik Array dan Linked List

|                   Array                  |                           Linked List                         |       
| :--------------------------------------: | :-----------------------------------------------------------: | 
|                  Statis                  |                             Dinamis                           | 
| Penambatan / penghapusan data terbatas   |          Penambatan / penghapusan data tidak terbatas         |    
|               Random Access              |                        Sequential Access                      |  
|     Penghapusan array  tidak mungkin     |                  Penghapusan linked list mudah                |

## Guided

### 1. Program Single Linked List NON-CIRCULAR

```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
    // komponen/member
    int data;
    Node *next;
};
Node *head;
Node *tail;
// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}
// Tambah Depan
void insertDepan(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}
// Tambah Belakang
void insertBelakang(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}
// Hitung Jumlah List
int hitungList()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
// Tambah Tengah
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;

        // tranversing
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
// Hapus Depan
void hapusDepan()
{
    Node *hapus;
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Tengah
void hapusTengah(int posisi)
{
    Node *hapus, *bantu, *bantu2;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                bantu2 = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
        delete hapus;
    }
}
// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == false)
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Tengah
void ubahTengah(int data, int posisi)
{
    Node *bantu;
    if (isEmpty() == false)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Belakang
void ubahBelakang(int data)
{
    if (isEmpty() == false)
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus List
void clearList()
{
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
// Tampilkan List
void tampil()
{
    Node *bantu;
    bantu = head;
    if (isEmpty() == false)
    {
        while (bantu != NULL)
        {
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
int main()
{
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7, 2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}
```

Program Linked list yang dibuat adalah single linked list non-circular, di mana setiap node memiliki data integer dan pointer yang menunjuk ke node berikutnya. Kode dimulai dengan deklarasi struct `Node` yang memiliki dua anggota, `data` untuk nilai data dan `next` untuk pointer ke node berikutnya. Selanjutnya, terdapat inisialisasi dua pointer `head` dan `tail` yang awalnya menunjuk ke NULL, menandakan linked list kosong.

Fungsi-fungsi yang disediakan meliputi inisialisasi linked list, pengecekan apakah linked list kosong, penambahan node di depan dan belakang, penghitungan jumlah node, penambahan node pada posisi tertentu, penghapusan node dari depan, belakang, atau posisi tertentu, pengubahan nilai data pada node tertentu, penghapusan seluruh isi linked list, dan menampilkan isi linked list.

Di dalam `main()` function, dilakukan serangkaian operasi seperti penambahan, penghapusan, dan pengubahan nilai data pada linked list yang telah dibuat untuk memperlihatkan fungsionalitas dari implementasi linked list tersebut.

### 2. Program Latihan Double Linked List 

```C++
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};
class DoublyLinkedList
{

public:
    Node *head;
    Node *tail;
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    void push(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr)
        {
            head->prev = newNode;
        }
        else
        {
            tail = newNode;
        }
        head = newNode;
    }
    void pop()
    {
        if (head == nullptr)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == oldData)
            {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList list;
    while (true)
    {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2:
            {
                list.pop();
                break;
            }
            case 3:
            {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);

                if (!updated)
                {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4:
            {
                list.deleteAll();
                break;
            }
            case 5:
            {
                list.display();
                break;
            }
            case 6:
            {
                return 0;
            }
            default:
            {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```

Doubly Linked List adalah jenis linked list di mana setiap node memiliki dua pointer, yaitu `prev` yang menunjuk ke node sebelumnya dan `next` yang menunjuk ke node berikutnya. Kelas `Node` digunakan untuk mendefinisikan struktur dari setiap node dalam linked list, yang memiliki tiga anggota: `data` untuk menyimpan nilai data, `prev` untuk menunjuk ke node sebelumnya, dan `next` untuk menunjuk ke node berikutnya.

Kelas `DoublyLinkedList` merupakan implementasi dari Doubly Linked List yang memiliki dua pointer, yaitu `head` yang menunjuk ke node pertama dalam linked list, dan `tail` yang menunjuk ke node terakhir. Dalam konstruktor kelas `DoublyLinkedList`, kedua pointer diinisialisasi sebagai `nullptr` untuk menandakan linked list kosong. 

Fungsi-fungsi yang disediakan dalam kelas `DoublyLinkedList` meliputi:
- `push(int data)`: Menambahkan node baru ke depan linked list dengan nilai data yang ditentukan. Jika linked list tidak kosong, node baru akan menjadi node pertama, jika tidak, node baru akan menjadi node terakhir.
- `pop()`: Menghapus node pertama dari linked list.
- `update(int oldData, int newData)`: Mengubah nilai data dari node yang memiliki nilai data tertentu.
- `deleteAll()`: Menghapus seluruh isi dari linked list.
- `display()`: Menampilkan seluruh nilai data dalam linked list.

Dalam fungsi `main()`, terdapat sebuah loop tak terbatas yang memungkinkan pengguna untuk memilih berbagai operasi yang ingin dilakukan pada linked list, seperti menambah, menghapus, mengubah nilai data, menghapus seluruh isi, atau menampilkan isi linked list. Input dari pengguna digunakan untuk memilih operasi yang diinginkan, dan hasil operasi ditampilkan sesuai dengan pilihan yang dibuat.

## Unguided

### 1. Soal mengenai Single Linked List
Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:

a. Masukkan data sesuai urutan berikut. (Gunakan insert depan, belakang atau tengah). Data pertama yang dimasukkan adalah nama dan usia anda.

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/5dcd9460-f74e-4be1-a5e8-052c99e16e80)

b. Hapus data Akechi

c. Tambahkan data berikut diantara John dan Jane : Futaba 18

d. Tambahkan data berikut diawal : Igor 20

e. Ubah data Michael menjadi : Reyn 18

f. Tampilkan seluruh data

```C++
#include <iostream>
#include <string>
using namespace std;

// Deklarasi Struct Node
struct Node
{
    string nama;
    int usia;
    Node *next;
};

Node *head = NULL; // Pointer yang menunjuk ke node pertama (head) dari linked list
Node *tail = NULL; // Pointer yang menunjuk ke node terakhir (tail) dari linked list

// Fungsi untuk menambah node baru di depan
void insertDepan(string nama, int usia)
{
    Node *baru = new Node; // Membuat node baru
    baru->nama = nama;     // Mengisi data nama pada node baru
    baru->usia = usia;     // Mengisi data usia pada node baru

    // Menambahkan node baru di depan head
    baru->next = head; // Node baru menunjuk ke node yang ditunjuk oleh head
    head = baru;       // Head menunjuk ke node baru

    // Jika linked list sebelumnya kosong, tail juga perlu diubah
    if (tail == NULL)
    {
        tail = baru;
    }
}

// Fungsi untuk menambah node baru di belakang
void insertBelakang(string nama, int usia)
{
    Node *baru = new Node; // Membuat node baru
    baru->nama = nama;     // Mengisi data nama pada node baru
    baru->usia = usia;     // Mengisi data usia pada node baru
    baru->next = NULL;     // Mengatur pointer next node baru menjadi NULL

    if (head == NULL) // Jika linked list kosong
    {
        head = baru; // Head menunjuk ke node baru
        tail = baru; // Tail juga menunjuk ke node baru karena hanya ada satu node dalam linked list
    }
    else // Jika linked list tidak kosong
    {
        tail->next = baru; // Menambahkan node baru setelah tail
        tail = baru;       // Mengubah tail untuk menunjuk ke node baru yang merupakan node terakhir
    }
}

// Fungsi untuk menambah node baru di tengah
void insertTengah(string nama, int usia, string namaSebelumnya)
{
    Node *baru = new Node; // Membuat node baru
    baru->nama = nama;     // Mengisi data nama pada node baru
    baru->usia = usia;     // Mengisi data usia pada node baru

    Node *bantu = head;
    while (bantu != NULL && bantu->nama != namaSebelumnya) // Mencari node dengan namaSebelumnya
    {
        bantu = bantu->next;
    }

    if (bantu == NULL) // Jika node dengan namaSebelumnya tidak ditemukan
    {
        cout << "Data tidak ditemukan" << endl;
        return;
    }

    baru->next = bantu->next; // Mengatur pointer next node baru
    bantu->next = baru;       // Menambahkan node baru setelah node dengan namaSebelumnya
}

// Fungsi untuk menampilkan semua data
void tampil()
{
    Node *bantu = head;
    if (bantu == NULL) // Jika linked list kosong
    {
        cout << "List kosong!" << endl;
        return;
    }

    while (bantu != NULL) // Menampilkan data setiap node dalam linked list
    {
        cout << bantu->nama << "\t" << bantu->usia << endl;
        bantu = bantu->next;
    }
}

// Fungsi untuk menghapus node dengan nama tertentu
void hapus(string nama)
{
    Node *hapus = head;
    Node *sebelum = NULL;

    while (hapus != NULL && hapus->nama != nama) // Mencari node dengan nama yang akan dihapus
    {
        sebelum = hapus;
        hapus = hapus->next;
    }

    if (hapus == NULL) // Jika node dengan nama yang akan dihapus tidak ditemukan
    {
        cout << "Data tidak ditemukan" << endl;
        return;
    }

    if (sebelum == NULL) // Jika node yang akan dihapus adalah head
    {
        head = hapus->next; // Mengubah head menjadi node setelah node yang dihapus
    }
    else
    {
        sebelum->next = hapus->next; // Mengubah pointer next node sebelumnya untuk menghapus node yang dituju
    }

    delete hapus; // Menghapus node yang dihapus dari memory
}

// Fungsi untuk mengubah data mahasiswa dengan nama tertentu
void ubahData(string nama, string namaBaru, int usiaBaru)
{
    Node *ubah = head;

    while (ubah != NULL && ubah->nama != nama) // Mencari node dengan nama yang akan diubah
    {
        ubah = ubah->next;
    }

    if (ubah == NULL) // Jika node dengan nama yang akan diubah tidak ditemukan
    {
        cout << "Data tidak ditemukan" << endl;
        return;
    }

    ubah->nama = namaBaru; // Mengubah data nama pada node yang ditemukan
    ubah->usia = usiaBaru; // Mengubah data usia pada node yang ditemukan
}

int main()
{
    // Menambahkan data
    insertBelakang("John", 19);
    insertBelakang("Jane", 20);
    insertBelakang("Michael", 18);
    insertBelakang("Yusuke", 19);
    insertBelakang("Akechi", 20);
    insertBelakang("Hoshino", 18);
    insertBelakang("Karin", 18);

    char menu;
    string nama, namaBaru;
    int usia, usiaBaru;

    // Menampilkan menu
    do
    {
        cout << "\nMenu:\n";
        cout << "a. Masukkan data\n";
        cout << "b. Hapus data Akechi\n";
        cout << "c. Tambahkan data di antara John dan Jane\n";
        cout << "d. Tambahkan data di awal\n";
        cout << "e. Ubah data Michael\n";
        cout << "f. Tampilkan seluruh data\n";
        cout << "g. Keluar\n";
        cout << "Pilih menu: ";
        cin >> menu;

        switch (menu)
        {
            // Input nama dan usia saya
        case 'a':
            cout << "Masukkan nama dan usia: ";
            cin >> nama >> usia;
            insertDepan(nama, usia);
            cout << "Data berhasil di tambahkan" << endl;
            break;
            // Hapus data akechi
        case 'b':
            hapus("Akechi");
            cout << "Data Akechi telah di hapus" << endl;
            break;
            // Tambahkan data berikut diantara John dan Jane : Futaba 18
        case 'c':
            cout << "Masukkan nama dan usia: ";
            cin >> nama >> usia;
            insertTengah("Futaba", 18, "John");
            cout << "Data futaba telah di tambahkan" << endl;
            break;
            // Tambahkan data berikut diawal : Igor 20
        case 'd':
            cout << "Masukkan nama dan usia: ";
            cin >> nama >> usia;
            insertDepan(nama, usia);
            cout << "Data telah di tambahkan" << endl;
            break;
            // Ubah data Michael menjadi : Reyn 18
        case 'e':
            cout << "Masukkan nama baru, usia baru: ";
            cin >> namaBaru >> usiaBaru;
            ubahData("Michael", namaBaru, usiaBaru);
            cout << "Data berhasil diubah" << endl;
            break;
            // Menampilkan data
        case 'f':
            tampil();
            break;
            // Keluar program
        case 'g':
            cout << "Keluar dari program." << endl;
            break;
            // Jika menu tidak valid
        default:
            cout << "Menu tidak valid!" << endl;
        }
    } while (menu != 'g');

    return 0;
}
```

#### Output menu a:

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/ee51d982-3c50-4f1c-a728-590451f01000)

#### Output menu b:

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/521dd845-5ee0-478a-8888-42e8302e3688)

#### Output menu c:

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/f3d9ebdf-1d99-4ae5-9c5a-02874ad0110e)

#### Output menu d:

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/cb4a6b82-36e2-426f-af88-6a938a347062)

#### Output menu e:

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/3d9560af-12b4-46d3-8f11-9709f399ac0f)

#### Output menu f:

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/48c07f2e-dbf0-4f32-8475-1494b415993d)

Program Linked list ini menggunakan struktur data `Node` yang memiliki dua atribut, yaitu `nama` dan `usia`, serta pointer `next` yang menunjuk ke node selanjutnya dalam linked list. Dua pointer global, `head` dan `tail`, digunakan untuk menandai node pertama dan terakhir dalam linked list.

Berbagai fungsi operasi dilengkapi untuk memanipulasi linked list, antara lain:
1. `insertDepan(string nama, int usia)`: Menambahkan node baru di depan linked list dengan data `nama` dan `usia` yang ditentukan.
2. `insertBelakang(string nama, int usia)`: Menambahkan node baru di belakang linked list dengan data `nama` dan `usia` yang ditentukan.
3. `insertTengah(string nama, int usia, string namaSebelumnya)`: Menambahkan node baru di antara dua node dengan nama tertentu dalam linked list.
4. `tampil()`: Menampilkan seluruh data dari linked list.
5. `hapus(string nama)`: Menghapus node dengan nama tertentu dari linked list.
6. `ubahData(string nama, string namaBaru, int usiaBaru)`: Mengubah data node dengan nama tertentu dalam linked list.

Dalam fungsi `main()`, program memberikan pilihan menu kepada pengguna untuk melakukan operasi-operasi tersebut. Pengguna dapat memilih untuk memasukkan data baru di depan atau di tengah linked list, menghapus data, mengubah data, menampilkan seluruh data, atau keluar dari program. Program akan terus berjalan hingga pengguna memilih untuk keluar dengan memasukkan opsi menu 'g'.

Program tersebut memberikan pengguna kemampuan untuk memasukkan sejumlah angka, menyimpannya dalam array, dan menampilkan kembali angka-angka tersebut bersama dengan pemisahan antara angka genap dan ganjil.

### 2. Soal mengenai Double Linked List
Modifikasi Guided Double Linked List dilakukan dengan penambahan
operasi untuk menambah data, menghapus, dan update di tengah / di
urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya
menampilkan Nama produk dan harga.

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/b687dc56-c9b2-4356-9d9b-676c2817d44a)

Case:
1. Tambahkan produk Azarine dengan harga 65000 diantara
Somethinc dan Skintific
2. Hapus produk wardah
3. Update produk Hanasui menjadi Cleora dengan harga 55.000
4. Tampilkan menu seperti dibawah ini

Toko Skincare Purwokerto
1. Tambah Data
2. Hapus Data
3. Update Data
4. Tambah Data Urutan Tertentu
5. Hapus Data Urutan Tertentu
6. Hapus Seluruh Data
7. Tampilkan Data
8. Exit
   
Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah ini :

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/a1dd87b2-0463-4113-96a6-487a2466429d)

```C++
#include <iostream>
#include <iomanip> // Untuk setw
#include <string>
using namespace std;

// Node untuk menyimpan informasi produk
class Node
{
public:
    string namaProduk;
    int harga;
    Node *prev;
    Node *next;
};

// Doubly Linked List untuk menyimpan daftar produk
class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;

    // Konstruktor untuk inisialisasi linked list
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Fungsi untuk menambahkan produk di awal linked list
    void push(string namaProduk, int harga)
    {
        Node *newNode = new Node;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr)
        {
            head->prev = newNode;
        }
        else
        {
            tail = newNode;
        }
        head = newNode;
    }

    // Fungsi untuk menghapus produk berdasarkan nama
    void deleteNode(string namaProduk)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->namaProduk == namaProduk)
            {
                if (current->prev != nullptr)
                {
                    current->prev->next = current->next;
                }
                else
                {
                    head = current->next;
                }

                if (current->next != nullptr)
                {
                    current->next->prev = current->prev;
                }
                else
                {
                    tail = current->prev;
                }

                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Data dengan nama produk '" << namaProduk << "' tidak ditemukan" << endl;
    }

    // Fungsi untuk memasukkan produk setelah produk tertentu
    void insertAfter(string namaProduk, int harga, string afterProduk, int afterHarga)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->namaProduk == afterProduk && current->harga == afterHarga)
            {
                Node *newNode = new Node;
                newNode->namaProduk = namaProduk;
                newNode->harga = harga;
                newNode->prev = current;
                newNode->next = current->next;

                if (current->next != nullptr)
                {
                    current->next->prev = newNode;
                }
                else
                {
                    tail = newNode;
                }
                current->next = newNode;
                return;
            }
            current = current->next;
        }
        cout << "Data not found" << endl;
    }

    // Fungsi untuk memperbarui nama dan harga produk
    bool update(string oldNamaProduk, int oldHarga, string newNamaProduk, int newHarga)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->namaProduk == oldNamaProduk && current->harga == oldHarga)
            {
                current->namaProduk = newNamaProduk;
                current->harga = newHarga;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Fungsi untuk menghapus semua data dari linked list
    void deleteAll()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    // Fungsi untuk menampilkan semua produk dari belakang ke depan
    void tampilkanData()
    {
        Node *current = tail; // Mulai dari tail
        cout << "-----------------------------------------" << endl;
        cout << "|       Nama Produk     |     Harga     |" << endl;
        cout << "-----------------------------------------" << endl;
        while (current != nullptr)
        {
            cout << "|\t" << setw(12) << left << current->namaProduk << " \t| " << setw(6) << current->harga << " \t|" << endl;
            current = current->prev; // Bergerak ke node sebelumnya
        }
        cout << "-----------------------------------------" << endl;
    }
};

int main()
{
    DoublyLinkedList list;

    // Inisialisasi awal data
    list.push("Originote", 60000);
    list.push("Somethinc", 150000);
    list.push("Skintific", 100000);
    list.push("Wardah", 50000);
    list.push("Hanasui", 30000);

    int pilihan;
    do
    {
        // Menampilkan menu
        cout << "Toko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;

        cout << "Masukan pilihan [1-8]: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
        {
            string namaProduk;
            int harga;
            cout << "Masukan nama produk: ";
            cin >> namaProduk;
            cout << "Masukan harga: ";
            cin >> harga;
            list.push(namaProduk, harga);
            break;
        }
        case 2:
        {
            string namaProduk;
            cout << "Masukan nama produk: ";
            cin >> namaProduk;
            list.deleteNode(namaProduk);
            break;
        }
        case 3:
        {
            string oldNamaProduk, newNamaProduk;
            int oldHarga, newHarga;
            cout << "Masukkan nama produk yang lama: ";
            cin >> oldNamaProduk;
            cout << "Masukkan harga produk yang lama: ";
            cin >> oldHarga;
            cout << "Masukkan nama produk yang baru: ";
            cin >> newNamaProduk;
            cout << "Masukkan harga produk yang baru: ";
            cin >> newHarga;
            bool updated = list.update(oldNamaProduk, oldHarga, newNamaProduk, newHarga);
            if (updated)
            {
                cout << "Data berhasil diperbarui" << endl;
            }
            else
            {
                cout << "Data tidak ditemukan" << endl;
            }
            break;
        }
        case 4:
        {
            string namaProduk, afterProduk;
            int harga, afterHarga;
            cout << "Masukkan nama produk yang akan ditambahkan: ";
            cin >> namaProduk;
            cout << "Masukkan harga produk yang akan ditambahkan: ";
            cin >> harga;
            cout << "Masukkan nama produk setelah produk baru: ";
            cin >> afterProduk;
            cout << "Masukkan harga produk setelah produk baru: ";
            cin >> afterHarga;
            list.insertAfter(namaProduk, harga, afterProduk, afterHarga);
            break;
        }
        case 5:
        {
            string namaProduk;
            cout << "Masukkan nama produk yang akan dihapus: ";
            cin >> namaProduk;
            list.deleteNode(namaProduk);
            break;
        }
        case 6:
        {
            list.deleteAll();
            cout << "Semua data berhasil dihapus" << endl;
            break;
        }
        case 7:
        {
            list.tampilkanData();
            break;
        }
        case 8:
        {
            cout << "Terima kasih code By kevin." << endl;
            break;
        }
        default:
        {
            cout << "Pilihan tidak valid" << endl;
            break;
        }
        }
    } while (pilihan != 8);

    return 0;
}
```

#### Output 1:

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/62ff6811-fa34-48cc-b79c-4292f10e5fad)

#### Output 2:

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/61d645d6-d4ef-4868-a770-d9fe138da5ef)

#### Output 3:

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/aa866b3e-486a-4747-bfbc-73c58a3f7316)

#### Output 4:

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/d9918620-f528-4574-8560-5c3c2155a3f0)

Kelas `Node` digunakan untuk merepresentasikan setiap elemen dalam linked list dengan atribut-atribut seperti `namaProduk` untuk menyimpan nama produk, `harga` untuk menyimpan harga produk, serta pointer `prev` dan `next` yang mengarah ke node sebelumnya dan node selanjutnya dalam linked list.

Kelas `DoublyLinkedList` merupakan representasi dari Doubly Linked List itu sendiri, yang memiliki pointer `head` untuk menunjukkan node pertama dalam linked list, dan pointer `tail` untuk menunjukkan node terakhir. Kelas ini memiliki berbagai fungsi operasi, seperti:
- `push(string namaProduk, int harga)`: Menambahkan sebuah produk baru ke awal linked list dengan nama dan harga yang ditentukan.
- `deleteNode(string namaProduk)`: Menghapus produk dari linked list berdasarkan nama produk yang diberikan.
- `insertAfter(string namaProduk, int harga, string afterProduk, int afterHarga)`: Menambahkan sebuah produk baru setelah produk tertentu dalam linked list.
- `update(string oldNamaProduk, int oldHarga, string newNamaProduk, int newHarga)`: Memperbarui nama dan harga dari produk tertentu dalam linked list.
- `deleteAll()`: Menghapus semua produk dari linked list.
- `tampilkanData()`: Menampilkan semua produk dari belakang ke depan dengan format yang ditentukan.

Dalam fungsi `main()`, program memberikan menu interaktif kepada pengguna untuk melakukan berbagai operasi seperti menambah, menghapus, memperbarui, atau menampilkan produk, serta keluar dari program. Pengguna dapat memilih menu yang diinginkan dengan memasukkan nomor menu yang sesuai, dan program akan menjalankan fungsi yang sesuai dengan pilihan pengguna. Program akan terus berjalan hingga pengguna memilih untuk keluar dengan memilih opsi menu '8'.

## Kesimpulan

Linked list merupakan struktur data linear yang dinamis dan fleksibel, di mana elemen-elemen datanya terhubung secara berurutan melalui pointer (penunjuk) yang mengarah ke simpul berikutnya, bukan berdasarkan lokasi memori. Setiap elemen data dalam linked list, yang disebut simpul (node), terdiri dari dua bagian utama: data itu sendiri dan pointer yang menunjuk ke simpul berikutnya dalam daftar. Keuntungan utama linked list adalah kemudahan dalam penyisipan dan penghapusan data di mana pun dalam daftar, tanpa perlu memindahkan elemen lain, serta penggunaan memori yang lebih efisien dibandingkan array. Namun, linked list memiliki kelemahan dalam hal akses data yang relatif lebih lambat dibandingkan array, karena membutuhkan waktu untuk mengikuti pointer untuk mencapai elemen yang diinginkan.

## Referensi

[1] Mulyana, A., et al., Cara Mudah Mempelajari Algoritma dan Struktur Data. Edisi Pertama. Yogyakarta : DIVA Press, 2021

[2] Randa, Z., "Pengertian Linked List," Scribd. [Online]. Available : https://id.scribd.com/document/490260142/PENGERTIAN-LINKED-LIST [Diakses 25 Maret 2024].

[3] "geeksforgeeks", [Online]. Available: https://www.geeksforgeeks.org/. [Accessed: March 25, 2024].
