# <h1 align="center">Laporan Praktikum Modul Queue</h1>

<p align="center">Hizkia Kevin Octaviano - 2311102185</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

Antrean atau queue (baca: qyu) adalah salah satu konsep
struktur data yang memiliki sistem kerja, di mana yang
pertama masuk maka akan menjadi yang pertama keluar
(FIFO = first in first out), seperti halnya antrean yang terjadi
dalam dunia nyata. Namun, hal ini tidak berlaku pada antrean
berprioritas. Sebab, pada antrean berprioritas, urutan keluar
dari sebuah antrean ditentukan berdasarkan prioritas masing-masing elemen dalam antrean untuk diproses terlebih dahulu.
Pada sebuah antrean, elemen hanya dapat ditambahkan
melalui sisi belakang queue dan hanya dapat diambil dari sisi
bagian depan queue. Oleh karena itu, ada dua buah elemen
pada sebuah queue, yaitu belakang (last atau rear) sebagai
penunjuk paling belakang dan depan (first atau front) sebagai penunjuk elemen bagian depan. Seperti halnya stack dan list,
queue juga merupakan pemikiran struktur data yang dapat
direpresentasikan secara statis menggunakan array atau secara
dinamis menggunakan pointer. Begitu pun dengan elemen
sebuah queue dapat diisi dengan data sesuai kebutuhan[1].

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/cf0aab3e-8dcf-492b-98f9-d8690fd87681)

### Karakteristik Queue

**Karakteristik penting antrian sebagai berikut :**

1. Elemen antrian yaitu item-item data yang terdapat di elemen antrian[2].

2. Head/front (elemen terdepan dari antrian)[2].

3. Tail/rear (elemen terakhir dari antrian)[2].

4. Jumlah elemen pada antrian (count)[2].

5. Status/kondisi antrian[2].

**Kondisi antrian yang menjadi perhatian adalah :**

- **Penuh**
  
Bila elemen di antrian mencapai kapasitas
maksimum antrian. Pada kondisi ini, tidak
mungkin dilakukan penambahan ke antrian.
Penambahan elemen menyebabkan kondisi
kesalahan Overflow[2].

- **Kosong**
  
Bila tidak ada elemen di antrian. Pada kondisi ini,
tidak mungkin dilakukan pengambilan elemen dari
antrian. Pengambilan elemen menyebabkan kondisi
kesalahan Underflow[2].


### Operasi-operasi pokok queue sebagai berikut :

1. **createQueue (Q)**, atau constructor menciptakan antrian kosong Q[2].

2. **addQueue (Q, X)** memasukkan elemen X sebagai elemen akhir di Q[2].

3. **removeQueue (Q, X)** atau mengambil elemen depan di antrian Q ke elemen X[2].


### Operasi-operasi pengaksesan tambahan yang dapat dilakukan adalah :

1. **headQueue (Q)**, atau Front (Q, X) mengirim elemen terdepan tanpa menghapus[2].

2. **tailQueue (Q)**, mengirim elemen tanpa menghapusnya[2].


### Operasi-operasi Query tambahan yang dapat dilakukan adalah :

1. **isEmptyQueue (Q)**, mengirim apakah antrian Q adalah kosong[2].

2. **isFullQueue (Q)**, mengirim apakah antrian Q adalah penuh bila kapasitas antrian Q didefinisikan[2].

3. **isOverflowQueue (Q)**, mengirim apakah antrian Q telah mengalamioverflow[2].

4. **isUnderflowQueue (Q)**, mengirim apakah antrian Q mengalami underflow[2].


### Operasi-operasi terhadap seluruh antrian Q antara lain adalah :

1. **sizeQueue (Q)**, mengetahui jumlah elemen di antrian Q[2].

2. **isEqualQueue (Q1, Q2)**, mengirim apakah antrian Q1 dan Q2 sama isinya[2].
  

## Guided

### 1. Program Pertama Queue

```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0;               // Penanda antrian
int back = 0;                // Penanda
string queueTeller[5];       // Fungsi pengecekan

bool isFull()
{ // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue)
    {
        return true; // =1
    }
    else
    {
        return false;
    }
}
bool isEmpty()
{ // Antriannya kosong atau tidak
    if (back == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void enqueueAntrian(string data)
{ // Fungsi menambahkan antrian
    if (isFull())
    {
        cout << "Antrian penuh" << endl;
    }
    else
    {
        if (isEmpty())
        { // Kondisi ketika queue kosong
            queueTeller[0] = data;
            front++;
            back++;
        }
        else
        { // Antrianya ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}
void dequeueAntrian()
{ // Fungsi mengurangi antrian
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}
int countQueue()
{ // Fungsi menghitung banyak antrian
    return back;
}
void clearQueue()
{ // Fungsi menghapus semua antrian
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}
void viewQueue()
{ // Fungsi melihat antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++)
    {
        if (queueTeller[i] != "")
        {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        }
        else
        {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main()
{
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
``` 

Program mendefinisikan sebuah antrian dengan kapasitas maksimum lima elemen (`maksimalQueue = 5`) dan menggunakan dua variabel, `front` dan `back`, untuk melacak posisi depan dan belakang antrian. Elemen antrian disimpan dalam array `queueTeller` yang berukuran lima.

Program ini menyediakan beberapa fungsi utama untuk mengelola antrian:

1. **isFull()**: Mengecek apakah antrian penuh dengan membandingkan `back` dengan `maksimalQueue`.
2. **isEmpty()**: Mengecek apakah antrian kosong dengan memeriksa apakah `back` bernilai nol.
3. **enqueueAntrian(string data)**: Menambahkan elemen baru ke antrian jika tidak penuh. Jika antrian kosong, elemen baru ditempatkan di posisi pertama dan kedua penanda, `front` dan `back`, diupdate. Jika tidak, elemen baru ditambahkan di posisi `back` dan `back` diinkrementasikan.
4. **dequeueAntrian()**: Menghapus elemen dari antrian dengan menggeser semua elemen satu posisi ke depan dan mengurangi nilai `back`.
5. **countQueue()**: Menghitung jumlah elemen dalam antrian dengan mengembalikan nilai `back`.
6. **clearQueue()**: Menghapus semua elemen dari antrian dengan mengosongkan array dan mengatur ulang `front` dan `back` ke nol.
7. **viewQueue()**: Menampilkan semua elemen dalam antrian. Elemen yang kosong ditampilkan sebagai "(kosong)".

Pada fungsi `main()`, program ini melakukan beberapa operasi dasar: menambahkan elemen ke antrian (`enqueueAntrian`), menampilkan isi antrian (`viewQueue`), menghitung jumlah elemen dalam antrian (`countQueue`), menghapus elemen dari antrian (`dequeueAntrian`), dan menghapus semua elemen dalam antrian (`clearQueue`).

## Unguided

### 1. Soal mengenai Queue
Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list

```C++
#include <iostream>
using namespace std;

struct Node
{
    string data; // Data yang disimpan dalam node
    Node *next;  // Pointer ke node berikutnya dalam antrian
};

// Pointer global untuk mengelola bagian depan dan belakang antrian
Node *front = NULL;
Node *back = NULL;

// Fungsi untuk memeriksa apakah antrian kosong
bool isEmpty()
{
    return front == NULL; // Antrian kosong jika front adalah NULL
}

// Fungsi untuk menambahkan elemen ke belakang antrian
void enqueueAntrian(string data)
{
    Node *newNode = new Node; // Membuat node baru
    newNode->data = data;     // Mengatur data untuk node baru
    newNode->next = NULL;     // Node baru akan menjadi node terakhir, jadi next adalah NULL

    if (isEmpty()) // Jika antrian kosong
    {
        front = back = newNode; // front dan back mengarah ke node baru
    }
    else // Jika antrian tidak kosong
    {
        back->next = newNode; // Menautkan node baru setelah node belakang saat ini
        back = newNode;       // Memperbarui pointer back ke node baru
    }
}

// Fungsi untuk menghapus elemen dari depan antrian
void dequeueAntrian()
{
    if (isEmpty()) // Jika antrian kosong
    {
        cout << "Antrian kosong" << endl;
    }
    else // Jika antrian tidak kosong
    {
        Node *temp = front;  // Simpan sementara node depan
        front = front->next; // Pindahkan pointer front ke node berikutnya
        delete temp;         // Hapus node depan lama

        if (front == NULL) // Jika antrian sekarang kosong
        {
            back = NULL; // Perbarui pointer back ke NULL
        }
    }
}

// Fungsi untuk menghitung jumlah elemen dalam antrian
int countQueue()
{
    int count = 0;       // Inisialisasi hitungan ke nol
    Node *curr = front;  // Mulai dari depan antrian
    while (curr != NULL) // Traversal hingga akhir antrian
    {
        count++;           // Menambah hitungan untuk setiap node
        curr = curr->next; // Pindah ke node berikutnya
    }
    return count; // Kembalikan jumlah node
}

// Fungsi untuk mengosongkan antrian
void clearQueue()
{
    while (!isEmpty()) // Selama antrian tidak kosong
    {
        dequeueAntrian(); // Hapus elemen dari depan antrian
    }
}

// Fungsi untuk menampilkan elemen-elemen dalam antrian
void viewQueue()
{
    cout << "====== Data antrian teller ======" << endl;
    if (isEmpty()) // Jika antrian kosong
    {
        cout << "Data kosong !" << endl;
        return;
    }

    int posisi = 1;      // Inisialisasi posisi
    Node *curr = front;  // Mulai dari depan antrian
    while (curr != NULL) // Traversal hingga akhir antrian
    {
        cout << posisi << ". " << curr->data << endl; // Cetak posisi dan data node
        curr = curr->next;                            // Pindah ke node berikutnya
        posisi++;                                     // Tambah posisi
    }
}

int main()
{
    enqueueAntrian("Kepin");
    enqueueAntrian("Toyo");
    viewQueue();                                             // Menampilkan antrian
    cout << "\nJumlah antrian = " << countQueue() << "\n\n"; // Menampilkan jumlah antrian
    dequeueAntrian();                                        // Menghapus elemen dari depan antrian
    viewQueue();                                             // Menampilkan antrian
    cout << "\nJumlah antrian = " << countQueue() << "\n\n"; // Menampilkan jumlah antrian
    clearQueue();                                            // Mengosongkan antrian
    viewQueue();                                             // Menampilkan antrian
    cout << "\nJumlah antrian = " << countQueue() << "\n\n"; // Menampilkan jumlah antrian

    return 0;
}
```
Output Program :

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/11ecd778-24d3-4e7f-b85b-d21b2ae3dd6d)

Program Antrian ini menggunakan struktur `Node` yang memiliki dua anggota: `data` untuk menyimpan nilai string dan `next` untuk menunjuk ke node berikutnya. Antrian dikelola dengan dua pointer global, `front` dan `back`, yang masing-masing menunjuk ke elemen pertama dan terakhir antrian.

Program ini memiliki beberapa fungsi untuk mengelola antrian. Fungsi `isEmpty` memeriksa apakah antrian kosong dengan melihat apakah pointer `front` bernilai NULL. Fungsi `enqueueAntrian` menambahkan elemen baru ke belakang antrian dengan membuat node baru dan memperbarui pointer `back`. Fungsi `dequeueAntrian` menghapus elemen dari depan antrian dengan memperbarui pointer `front` dan menghapus node lama. Fungsi `countQueue` menghitung jumlah elemen dalam antrian dengan traversal dari depan hingga belakang antrian. Fungsi `clearQueue` mengosongkan antrian dengan terus menghapus elemen dari depan hingga antrian kosong. Terakhir, fungsi `viewQueue` menampilkan semua elemen dalam antrian beserta posisinya.

Dalam fungsi `main`, beberapa operasi pada antrian dilakukan: menambahkan elemen ke antrian dengan `enqueueAntrian`, menampilkan antrian dengan `viewQueue`, menghitung dan menampilkan jumlah elemen dalam antrian dengan `countQueue`, menghapus elemen dari antrian dengan `dequeueAntrian`, dan mengosongkan antrian dengan `clearQueue`. Hasil dari operasi-operasi ini ditampilkan untuk memverifikasi fungsi antrian.

### 2. Soal mengenai Queue
Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa

```C++
#include <iostream>
#include <iomanip>
using namespace std;

struct Mahasiswa
{
    string nama;   // Nama mahasiswa
    long long nim; // NIM mahasiswa
};

struct Node
{
    Mahasiswa data; // Data mahasiswa disimpan dalam node
    Node *next;     // Pointer ke node berikutnya dalam antrian
};

// Pointer global untuk mengelola bagian depan dan belakang antrian
Node *front = NULL;
Node *back = NULL;

// Fungsi untuk memeriksa apakah antrian kosong
bool isEmpty()
{
    return front == NULL; // Antrian kosong jika front adalah NULL
}

// Fungsi untuk menambahkan elemen ke belakang antrian
void enqueueAntrian(string nama, long long nim)
{
    Node *newNode = new Node;  // Membuat node baru
    newNode->data.nama = nama; // Mengatur nama mahasiswa untuk node baru
    newNode->data.nim = nim;   // Mengatur NIM mahasiswa untuk node baru
    newNode->next = NULL;      // Node baru akan menjadi node terakhir, jadi next adalah NULL

    if (isEmpty()) // Jika antrian kosong
    {
        front = back = newNode; // front dan back mengarah ke node baru
    }
    else // Jika antrian tidak kosong
    {
        back->next = newNode; // Menautkan node baru setelah node belakang saat ini
        back = newNode;       // Memperbarui pointer back ke node baru
    }
}

// Fungsi untuk menghapus elemen dari depan antrian
void dequeueAntrian()
{
    if (isEmpty()) // Jika antrian kosong
    {
        cout << "Antrian kosong" << endl;
    }
    else // Jika antrian tidak kosong
    {
        Node *temp = front;  // Simpan sementara node depan
        front = front->next; // Pindahkan pointer front ke node berikutnya
        delete temp;         // Hapus node depan lama

        if (front == NULL) // Jika antrian sekarang kosong
        {
            back = NULL; // Perbarui pointer back ke NULL
        }
    }
}

// Fungsi untuk menghitung jumlah elemen dalam antrian
int countQueue()
{
    int count = 0;       // Inisialisasi hitungan ke nol
    Node *curr = front;  // Mulai dari depan antrian
    while (curr != NULL) // Traversal hingga akhir antrian
    {
        count++;           // Menambah hitungan untuk setiap node
        curr = curr->next; // Pindah ke node berikutnya
    }
    return count; // Kembalikan jumlah node
}

// Fungsi untuk mengosongkan antrian
void clearQueue()
{
    while (!isEmpty()) // Selama antrian tidak kosong
    {
        dequeueAntrian(); // Hapus elemen dari depan antrian
    }
}

// Fungsi untuk menampilkan elemen-elemen dalam antrian
void viewQueue()
{
    cout << "====== Data antrian mahasiswa ======" << endl;
    if (isEmpty()) // Jika antrian kosong
    {
        cout << "Data kosong !" << endl;
        return;
    }

    cout << "-----------------------------------------" << endl;
    cout << "|       Nama         |       NIM        |" << endl;
    cout << "-----------------------------------------" << endl;

    Node *curr = front;  // Mulai dari depan antrian
    while (curr != NULL) // Traversal hingga akhir antrian
    {
        cout << "| " << setw(18) << left << curr->data.nama << " | " << setw(17) << left << curr->data.nim << "|" << endl; // Cetak nama dan NIM node
        curr = curr->next;                                                                                                 // Pindah ke node berikutnya
    }
    cout << "-----------------------------------------" << endl;
}

int main()
{
    enqueueAntrian("Kepin", 123456789);
    enqueueAntrian("Hizkia", 2311102185);
    viewQueue(); // Menampilkan antrian
    cout << "\nJumlah antrian = " << countQueue() << "\n\n";
    dequeueAntrian(); // Menghapus elemen dari depan antrian
    viewQueue();      // Menampilkan antrian
    cout << "\nJumlah antrian = " << countQueue() << "\n\n";
    clearQueue(); // Mengosongkan antrian
    viewQueue();  // Menampilkan antrian
    cout << "\nJumlah antrian = " << countQueue() << "\n\n";

    return 0;
}
```

Output Program :

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/822db8ce-b619-43aa-92bb-dce84707d9f6)

Program ini terdiri dari dua struktur utama: `Mahasiswa`, yang menyimpan data mahasiswa berupa nama dan NIM, dan `Node`, yang menyimpan data mahasiswa dalam antrian serta pointer ke node berikutnya. Antrian dikelola menggunakan dua pointer global, `front` dan `back`, yang mengacu pada node pertama dan terakhir dalam antrian. Fungsi `isEmpty()` memeriksa apakah antrian kosong. Fungsi `enqueueAntrian()` menambahkan elemen baru ke belakang antrian, sementara `dequeueAntrian()` menghapus elemen dari depan antrian. Fungsi `countQueue()` menghitung jumlah elemen dalam antrian, dan `clearQueue()` mengosongkan seluruh antrian dengan menghapus semua elemennya. Fungsi `viewQueue()` menampilkan semua elemen dalam antrian dalam format tabel. Fungsi-fungsi ini digunakan dalam fungsi `main()` untuk menambahkan beberapa elemen ke antrian, menampilkan isi antrian, menghapus elemen dari antrian, dan mengosongkan antrian, sambil menampilkan jumlah elemen yang tersisa setelah setiap operasi.

## Kesimpulan

Queue adalah struktur data yang beroperasi berdasarkan prinsip FIFO (First In, First Out), di mana data yang pertama kali dimasukkan akan menjadi data pertama yang dikeluarkan. Queue terdiri dari dua operasi dasar: enQueue, yang menambahkan elemen ke belakang antrian, dan deQueue, yang menghapus elemen dari depan antrian. Ada beberapa jenis queue, termasuk simple queue, circular queue, priority queue, dan double-ended queue (deque), masing-masing dengan karakteristik dan kegunaannya sendiri dalam pemrograman dan pengembangan sistem.

## Referensi

[1] Mulyana, A., et al., Cara Mudah Mempelajari Algoritma dan Struktur Data. Edisi Pertama. Yogyakarta : DIVA Press, 2021

[2] Adlaimi, N. (2019, March 30). STRUKTUR DATA MAJEMUK  (QUEUE). https://doi.org/10.31219/osf.io/cs53p
