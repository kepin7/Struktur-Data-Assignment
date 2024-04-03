# <h1 align="center">Laporan Praktikum Modul Linked List Circular dan Non Circular</h1>

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

### 1. Program Latihan Linked List NON-CIRCULAR

```C++
#include <iostream>
using namespace std;
/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
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
    Node *bantu, *hapus, *sebelum;
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
                sebelum = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        sebelum->next = bantu;
        delete hapus;
    }
}

// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == 0)
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
    if (isEmpty() == 0)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
        }
        else
        {
            cout << "Posisi bukan posisi tengah" << endl;

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
    if (isEmpty() == 0)
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

Pada program ini, terdapat beberapa fungsi, antara lain untuk menambahkan node di depan (`insertDepan()`), di belakang (`insertBelakang()`), atau di tengah (`insertTengah()`). Fungsi-fungsi lainnya juga disediakan untuk menghapus node (`hapusDepan()`, `hapusBelakang()`, `hapusTengah()`), mengubah nilai data node (`ubahDepan()`, `ubahBelakang()`, `ubahTengah()`), serta untuk menampilkan isi linked list (`tampil()`). 
Setiap operasi dilakukan setelah inisialisasi linked list (`init()`) di dalam fungsi `main()`. Program ini memberikan pengguna kemampuan untuk memanipulasi linked list sesuai kebutuhan, seperti menambah, menghapus, dan mengubah nilai data node, serta menampilkan isi linked list setelah setiap operasi.

### 2. Program Latihan Linked List Circular

```C++
#include <iostream>

using namespace std;

/// PROGRAM SINGLE LINKED LIST CIRCULAR

// Deklarasi Struct Node
struct Node
{
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init()
{
    head = NULL;
    tail = head;
}

// Pengecekan
int isEmpty()
{
    if (head == NULL)
        return 1; // true
    else
        return 0; // false
}

// Buat Node Baru
void buatNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList()
{
    bantu = head;
    int jumlah = 0;

    while (bantu != NULL)
    {
        jumlah++;
        bantu = bantu->next;
    }

    return jumlah;
}

// Tambah Depan
void insertDepan(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah Belakang
void insertBelakang(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }

        tail->next = baru;
        baru->next = head;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi)
{
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        baru->data = data;
        // transversing
        int nomor = 1;
        bantu = head;
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
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;

        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            delete hapus;

            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            hapus->next = NULL;

            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus Belakang
void hapusBelakang()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            delete hapus;
            while (hapus->next != head)
            {
                hapus = hapus->next;
            }
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            tail->next = head;
            hapus->next = NULL;

            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi)
{
    if (isEmpty() == 0)
    {
        // transversing
        int nomor = 1;
        bantu = head;

        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;

        delete hapus;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearList()
{
    if (head != NULL)
    {
        hapus = head->next;

        while (hapus != head)
        {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil()
{
    if (isEmpty() == 0)
    {
        tail = head;
        do
        {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);
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
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();

    return 0;
}
```

Program mendeklarasikan sebuah struct `Node` yang memiliki dua anggota, yaitu `data` untuk menyimpan informasi dan `next` untuk menunjuk ke node selanjutnya dalam list. Program juga mendeklarasikan beberapa variabel pointer seperti `head`, `tail`, `baru`, `bantu`, dan `hapus` yang akan digunakan dalam operasi-operasi pada linked list.

Fungsi `init()` digunakan untuk menginisialisasi linked list dengan mengatur `head` dan `tail` menjadi `NULL`, menandakan bahwa list masih kosong. Fungsi `isEmpty()` memeriksa apakah list kosong atau tidak.

Fungsi `buatNode(string data)` digunakan untuk membuat node baru dengan data yang diberikan.

Fungsi `hitungList()` mengembalikan jumlah elemen dalam list.

Fungsi-fungsi `insertDepan(string data)`, `insertBelakang(string data)`, dan `insertTengah(string data, int posisi)` digunakan untuk menyisipkan node baru di depan, belakang, atau di tengah list sesuai dengan posisi yang ditentukan.

Fungsi-fungsi `hapusDepan()`, `hapusBelakang()`, dan `hapusTengah(int posisi)` digunakan untuk menghapus node di depan, belakang, atau di tengah list sesuai dengan posisi yang ditentukan.

Fungsi `clearList()` digunakan untuk menghapus seluruh elemen dalam list.

Fungsi `tampil()` digunakan untuk menampilkan isi dari list.

Pada fungsi `main()`, dilakukan inisialisasi list dengan `init()`, kemudian dilakukan serangkaian operasi seperti penambahan elemen di depan, belakang, dan tengah list, penghapusan elemen di depan, belakang, dan tengah list, serta menampilkan isi list setelah setiap operasi dilakukan.

## Unguided

### 1. Soal Linked List Circular
Buatlah program menu Linked List Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user.

1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa

```C++
#include <iostream>
#include <string>
#include <iomanip> // Untuk setw()

using namespace std;

/// PROGRAM SINGLE LINKED LIST CIRCULAR

// Deklarasi Struct Node
struct Node
{
    string list_nama;
    long long list_nim;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init()
{
    head = NULL;
    tail = head;
}

// Pengecekan
bool isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Hitung List
int hitungList()
{
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
        if (hitung == head)
            break;
    }
    return jumlah;
}

// Buat Node Baru
void buatNode(string nama, long long nim)
{
    baru = new Node;
    baru->list_nama = nama;
    baru->list_nim = nim;
    baru->next = NULL;
}

// Tambah Depan
void insertDepan(string nama, long long nim)
{
    buatNode(nama, nim);

    if (isEmpty())
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah Belakang
void insertBelakang(string nama, long long nim)
{
    buatNode(nama, nim);

    if (isEmpty())
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }
}

// Tambah Tengah
void insertTengah(string nama, long long nim, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else
    {
        baru = new Node();
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->list_nama = nama;
        baru->list_nim = nim;
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Ubah Depan
void ubahDepan(string nama, long long nim)
{
    if (!isEmpty())
    {
        // Menyimpan nama dan nim lama sebelum diubah
        string namaLama = head->list_nama;
        long long nimLama = head->list_nim;

        // Mengubah nilai nama dan nim dengan nilai baru
        head->list_nama = nama;
        head->list_nim = nim;

        // Menampilkan pesan
        cout << "Data " << namaLama << " telah diganti dengan data " << nama << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Belakang
void ubahBelakang(string nama, long long nim)
{
    if (!isEmpty())
    {
        // Simpan data lama
        string namaLama = tail->list_nama;
        long long nimLama = tail->list_nim;

        // Mengubah data di bagian belakang
        tail->list_nama = nama;
        tail->list_nim = nim;

        // Menampilkan pesan
        cout << "Data " << namaLama << " telah diganti dengan data " << nama << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Tengah
void ubahTengah(string nama, long long nim, int posisi)
{
    if (!isEmpty())
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
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

            // Simpan data lama
            string namaLama = bantu->list_nama;
            long long nimLama = bantu->list_nim;

            // Mengubah data di posisi tertentu
            bantu->list_nama = nama;
            bantu->list_nim = nim;

            // Menampilkan pesan
            cout << "Data " << namaLama << " di posisi " << posisi << " telah diganti dengan data " << nama << "" << endl;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Depan
void hapusDepan()
{
    if (!isEmpty())
    {
        hapus = head;
        // Menampilkan nama mahasiswa yang dihapus
        cout << "Data " << hapus->list_nama << " berhasil dihapus" << endl;
        if (head->next != head)
        {
            head = head->next;
            tail->next = head;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang()
{
    if (!isEmpty())
    {
        if (head != tail)
        {
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            hapus = tail;
            // Menampilkan nama mahasiswa yang dihapus
            cout << "Data " << hapus->list_nama << " berhasil dihapus" << endl;
            tail = bantu;
            tail->next = head;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi)
{
    if (!isEmpty())
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else
        {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi - 1)
            {
                bantu = bantu->next;
                nomor++;
            }
            hapus = bantu->next;
            bantu->next = hapus->next;
            // Menampilkan nama mahasiswa yang dihapus
            cout << "Data " << hapus->list_nama << " berhasil dihapus" << endl;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearList()
{
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
        if (bantu == head)
            break;
    }
    head = tail = NULL;
}

// Tampilkan List
void tampil()
{
    bantu = head;

    if (!isEmpty())
    {
        cout << "-----------------------------------------" << endl;
        cout << "|       Nama         |       NIM        |" << endl;
        cout << "-----------------------------------------" << endl;
        do
        {
            cout << "| " << setw(18) << left << bantu->list_nama << " | " << setw(16) << left << bantu->list_nim << " |" << endl;
            bantu = bantu->next;
        } while (bantu != head);
        cout << "-----------------------------------------" << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

int main()
{
    int pilih;
    string nama;
    long long nim;
    init();

    do
    {
        // Tampilan Menu
        cout << "PROGRAM SINGLE LINKED LIST CIRCULAR" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
        cout << "11. Tampilkan" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih Operasi : ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            // Tambah Depan
            cout << "Masukkan Nama : ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan NIM : ";
            cin >> nim;
            insertDepan(nama, nim);
            cout << "Data telah ditambahkan" << endl;
            break;
        case 2:
            // Tambah Belakang
            cout << "Masukkan Nama : ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan NIM : ";
            cin >> nim;
            insertBelakang(nama, nim);
            cout << "Data telah ditambahkan" << endl;
            break;
        case 3:
            // Tambah Tengah
            int posisi;
            cout << "Masukkan Nama : ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan NIM : ";
            cin >> nim;
            cout << "Masukkan Posisi : ";
            cin >> posisi;
            insertTengah(nama, nim, posisi);
            cout << "Data telah ditambahkan di posisi " << posisi << endl;
            break;
        case 4:
            // Ubah Depan
            cout << "Masukkan Nama Baru: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan NIM Baru: ";
            cin >> nim;
            ubahDepan(nama, nim);
            break;
        case 5:
            // Ubah Belakang
            cout << "Masukkan Nama Baru: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan NIM Baru: ";
            cin >> nim;
            ubahBelakang(nama, nim);
            break;
        case 6:
            // Ubah Tengah
            cout << "Masukkan Nama Baru: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan NIM Baru: ";
            cin >> nim;
            cout << "Masukkan Posisi [update]: ";
            cin >> posisi;
            ubahTengah(nama, nim, posisi);
            break;
        case 7:
            hapusDepan();
            break;
        case 8:
            // Hapus Belakang
            hapusBelakang();
            break;
        case 9:
            // Hapus Tengah
            cout << "Masukkan Posisi: ";
            cin >> posisi;
            hapusTengah(posisi);
            break;
        case 10:
            // Hapus List
            clearList();
            cout << "Semua data list sudah terhapus" << endl;
            break;
        case 11:
            // Tampilkan List
            tampil();
            break;
            // jika pilihan tidak
        default:
            cout << "Pilihan invalid!" << endl;
            break;
        }
    } while (pilih != 0);

    return 0;
}
```

Program merupakan implementasi dari sebuah program untuk mengelola data menggunakan struktur data Linked List Circular. Berikut adalah penjelasan kode tersebut:

1. **Struktur Node**:
   - Ada sebuah struct yang disebut `Node`, yang berisi data mahasiswa (nama dan NIM) serta pointer `next` yang menunjuk ke node berikutnya.

2. **Deklarasi Variabel Global**:
   - Ada beberapa variabel global seperti `head`, `tail`, `baru`, `bantu`, dan `hapus` yang digunakan untuk mengelola operasi-operasi pada linked list.

3. **Inisialisasi**:
   - Fungsi `init()` digunakan untuk menginisialisasi linked list dengan mengatur `head` dan `tail` menjadi `NULL`.

4. **Operasi Dasar Linked List**:
   - Ada fungsi-fungsi untuk operasi dasar seperti pengecekan apakah linked list kosong (`isEmpty()`), menghitung jumlah node dalam linked list (`hitungList()`), membuat node baru (`buatNode()`), dan menambahkan node baru di depan, belakang, atau di tengah linked list (`insertDepan()`, `insertBelakang()`, `insertTengah()`).
   
5. **Operasi Ubah Data**:
   - Fungsi-fungsi untuk mengubah data di node tertentu, baik di bagian depan, belakang, maupun tengah linked list (`ubahDepan()`, `ubahBelakang()`, `ubahTengah()`).

6. **Operasi Hapus Data**:
   - Terdapat fungsi-fungsi untuk menghapus node, baik di bagian depan, belakang, maupun tengah linked list (`hapusDepan()`, `hapusBelakang()`, `hapusTengah()`).

7. **Operasi Hapus Semua Data**:
   - Fungsi `clearList()` digunakan untuk menghapus seluruh isi linked list.

8. **Tampilkan Data**:
   - Fungsi `tampil()` digunakan untuk menampilkan seluruh data dalam linked list.

9. **Fungsi Utama (main)**:
   - Di dalam fungsi utama (`main()`), terdapat loop `do-while` yang berisi menu operasi yang bisa dipilih oleh pengguna. Setiap operasi memiliki pemanggilan fungsi-fungsi yang telah didefinisikan sebelumnya. Pengguna diminta untuk memasukkan pilihan operasi, dan sesuai dengan pilihan tersebut, program akan melakukan tindakan yang sesuai.

#### Tampilan Menu:

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/52d52194-d300-4674-8429-0721f43e41c0)

#### Tampilan Operasi Insert:

2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah)

#### Output Insert Data:

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/131778bc-3f68-4125-9edd-62a927cf8dac)

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/1f04abc3-54f5-419f-95ef-09e95a1d8d6d)

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/bf2fcf4f-776e-483e-9749-4c91f91b5700)

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/5e508b09-646d-4f17-a186-69dab9a88947)

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/c3945892-f09b-4895-a036-67f5ed2b8045)

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/fbe3ea64-8aa7-4e2e-9561-f1ff39ff72e2)

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/98f9c171-b5d6-4d0c-ba7b-4733ed40520d)

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/978c9bde-a0ad-4c34-a2d5-1986aac53653)

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/3ec17425-3bf9-475f-8d80-10f52b11607a)

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/3cf4ef8b-4897-4c85-9ffd-6789af720538)

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/9bc9cd96-3eaf-46fa-8482-a16f810227a7)

3. Lakukan perintah berikut:
   a) Tambahkan data berikut diantara Farrel dan Denis:
      Wati  2330004

   ![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/4d05d870-2a34-4140-93cf-266623ba7d9b)

   b) Hapus data Denis

   ![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/01b17b58-8e67-474d-ac8d-6942773bb3b5)

   c) Tambahkan data berikut di awal:
      Owi  2330000

   ![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/f107f10e-a073-4a02-849a-d87cf58fc1d2)

   d) Tambahkan data berikut di akhir:
      David  23300100

   ![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/ded96d8a-a5a2-41f8-b0aa-ee842d0c5273)

   e) Ubah data Udin menjadi data berikut:
      Idin  23300045

   ![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/a4b4be00-345d-422c-989c-d7b1c47e8bd6)

   f) Ubah data terkahir menjadi berikut:
      Lucy  23300101

   ![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/ba63beb4-c022-41bd-a5e4-31f1fe08a771)

   g) Hapus data awal

   ![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/196ea483-684f-4933-8a7b-36d35dff14c6)

   h) Ubah data awal menjadi berikut:
      Bagas  2330002

   ![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/570553ea-ae82-4737-97a8-cc9c953e4cf6)

   i) Hapus data akhir

   ![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/1c5da250-5b4e-4654-bf91-3fbea668b968)

   j) Tampilkan seluruh data

   ![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/4db08994-8a4f-4c66-ae58-bbeab8f7144c)

## Kesimpulan

Linked list non-circular memiliki pointer pada node terakhir yang menunjuk ke nilai khusus, biasanya NULL, menandakan akhir list. Penambahan dan penghapusan data pada linked list non-circular umumnya dilakukan di awal (head) atau akhir (tail). Ini membuatnya efisien untuk operasi yang sering terjadi di kedua ujung list, seperti pada implementasi stack dan queue.

Di sisi lain, linked list circular memiliki pointer pada node terakhir yang justru menunjuk kembali ke node pertama, membentuk lingkaran. Hal ini memungkinkan penambahan dan penghapusan data di sembarang tempat dalam list. Linked list circular cocok untuk operasi yang sering terjadi di bagian tengah list, seperti pada implementasi circular buffer.

Singkatnya, linked list non-circular lebih sederhana dan efisien untuk operasi di awal atau akhir list, sedangkan linked list circular menawarkan fleksibilitas untuk operasi di seluruh bagian list. Pemilihan jenis linked list yang tepat bergantung pada kebutuhan operasi yang akan dilakukan dalam program.

## Referensi

[1] Mulyana, A., et al., Cara Mudah Mempelajari Algoritma dan Struktur Data. Edisi Pertama. Yogyakarta : DIVA Press, 2021

[2] Randa, Z., "Pengertian Linked List," Scribd. [Online]. Available : https://id.scribd.com/document/490260142/PENGERTIAN-LINKED-LIST [Diakses 25 Maret 2024].

[3] "geeksforgeeks", [Online]. Available: https://www.geeksforgeeks.org/. [Accessed: April 01, 2024].
