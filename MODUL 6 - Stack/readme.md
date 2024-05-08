# <h1 align="center">Laporan Praktikum Modul Stack</h1>

<p align="center">Hizkia Kevin Octaviano - 2311102185</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

Stack adalah suatu tumpukan dari benda. Konsep utamanya adalah LIFO (last in first out), yaitu benda yang terakhir masuk dalam stack akan menjadi benda pertama yang dikeluarkan dari stack[1].
Karakteristik khas dari stack adalah penggunaan aturan LIFO (Last In, First Out) [2]. Data yang terakhir dimasukkan ke dalam stack akan menjadi data pertama yang diambil atau dikeluarkan. Konsep ini mirip dengan tumpukan buku, di mana buku yang terakhir diletakkan di atas tumpukan harus diambil terlebih dahulu sebelum bisa mengakses buku yang berada di bagian bawah tumpukan[2].

Stack harus memiliki operasi-operasi sebagai berikut:

- Push -> digunakan untuk menambahkan (push) suatu item ke dalam stack.
- Pop -> digunakan untuk menghapus (pops) suatu item dari dalam stack.
- Peek -> digunakan untuk mengembalikan top item dari stack tanpa menghilangkannya.
- isFull -> digunakan untuk mengecek apakah stack penuh atau tidak.
- isEmpty -> digunakan untuk mengecek apakah stack kosong atau tidak.
- Size -> digunakan untuk mengembalikan elemen dalam stack.
- Clear -> digunakan untuk menghapus seluruh elemen dalam satck sehingga stack kosong.
- Search -> digunakan untuk mencari suatu elemen tertentu dalam stack.
- Top -> digunakan untuk melihat elemen teratas dalam stack tanpa menghapusnya.

**Kelebihan dan Kekurangan Stack :**

- Kelebihan stack yaitu penambahan dan penghapusan data dapat dilakukan dengan cepat, yaitu selama memori masih tersedia penambahan data bisa terus dilakukan. Dengan demikian tidak ada kekuatiran terjadinya stack overflow[3].
- Kekurangan stack yaitu setiap sel tidak hanya menyimpan value saja, melainkan juga pointer ke sel berikutnya. Hal ini menyebabkan implementasi stack memakai linked list akan memerlukan memori yang lebih banyak daripada di implementasikan dengan array. Setiap halaman pada linked list hanya bisa di akses dengan cara sekuensial, sehingga lambat[3].

## Guided

### 1. Program Pertama Stack

```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull()
{
    return (top == maksimal);
}

bool isEmpty()
{
    return (top == 0);
}

void pushArrayBuku(string data)
{
    if (isFull())
    {
        cout << "Data telah penuh" << endl;
    }
    else
    {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku()
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang dihapus" << endl;
    }
    else
    {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi)
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    }
    else
    {
        int index = top;
        for (int i = 0; i < posisi; i++)
        {
            index--;
        }
        cout << "posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack()
{
    return top;
}

void changeArrayBuku(int posisi, string data)
{
    if (posisi > top)
    {
        cout << "Posisi melebihi data yang ada" << endl;
    }
    else
    {
        int index = top;
        for (int i = 1; i <= posisi; i++)
        {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArrayBuku()
{
    for (int i = top; i >= 0; i--)
    {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku()
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang dicetak" << endl;
    }
    else
    {
        for (int i = top - 1; i >= 0; i--)
        {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main()
{
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya data = " << countStack() << endl;

    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << "\n";

    destroyArrayBuku();
    cout << "Jumlah data setelah dihapus : " << top << endl;
    cetakArrayBuku();

    return 0;
}
``` 

Pada kode ini, terdapat array `arrayBuku` yang memiliki ukuran maksimal 5, variabel `top` yang menyimpan indeks dari elemen teratas stack, dan fungsi-fungsi operasi dasar stack seperti `isFull()` untuk memeriksa apakah stack penuh, `isEmpty()` untuk memeriksa apakah stack kosong, `pushArrayBuku()` untuk menambahkan data ke dalam stack, `popArrayBuku()` untuk menghapus data dari stack, `peekArrayBuku()` untuk melihat data pada posisi tertentu dalam stack, `countStack()` untuk menghitung banyaknya data dalam stack, `changeArrayBuku()` untuk mengubah data pada posisi tertentu dalam stack, dan `destroyArrayBuku()` untuk menghapus semua data dalam stack.

Dalam fungsi `main()`, beberapa operasi stack dilakukan. Pertama, beberapa data buku dimasukkan ke dalam stack menggunakan `pushArrayBuku()`. Kemudian, data buku dicetak menggunakan `cetakArrayBuku()`. Dilakukan pula pengecekan apakah stack penuh dan kosong menggunakan `isFull()` dan `isEmpty()`. Selanjutnya, dilakukan operasi peek untuk melihat data pada posisi kedua dalam stack menggunakan `peekArrayBuku()`, kemudian satu data dihapus dari stack menggunakan `popArrayBuku()`. Setelah itu, dicetak jumlah data dalam stack dengan `countStack()`. Data pada posisi kedua dalam stack diubah menggunakan `changeArrayBuku()` menjadi "Bahasa Jerman" dan hasilnya dicetak kembali. Terakhir, dilakukan penghapusan semua data dalam stack menggunakan `destroyArrayBuku()` dan dicetak jumlah data setelah dihapus beserta isi stack yang sudah kosong.

## Unguided

### 1. Soal mengenai Stack
Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan
dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari
depan dan belakang sama. Jelaskan bagaimana cara kerja programnya

```C++
#include <iostream>
using namespace std;

// Array untuk menyimpan karakter dari kalimat
string arrayData[25];
// Maksimum elemen dalam array
int maksimal = 25;
// Indeks untuk menunjukkan elemen teratas dalam stack
int top = 0;

// Fungsi untuk mengecek apakah stack sudah penuh
bool isFull()
{
    return (top == maksimal);
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty()
{
    return (top == 0);
}

// Fungsi untuk menambahkan karakter ke dalam arrayData (mengisi stack)
void pushArrayData(string kalimat)
{
    // Jika stack sudah penuh, cetak pesan
    if (isFull())
    {
        cout << "Data telah penuh" << endl;
    }
    else
    {
        // Masukkan karakter ke dalam arrayData pada indeks top, lalu naikkan top
        arrayData[top] = kalimat;
        top++;
    }
}

// Fungsi untuk menghapus karakter dari arrayData (mengosongkan stack)
void popArrayData()
{
    // Jika stack kosong, cetak pesan
    if (isEmpty())
    {
        cout << "Tidak ada data yang dihapus" << endl;
    }
    else
    {
        // Kosongkan karakter pada arrayData pada indeks top - 1, lalu turunkan top
        arrayData[top - 1] = "";
        top--;
    }
}

// Fungsi untuk mengecek apakah kalimat adalah palindrom
bool isPalindrom(string kalimat)
{
    int length = kalimat.length();
    // Memasukkan setengah karakter pertama dari kalimat ke dalam stack
    for (int i = 0; i < length / 2; i++)
    {
        pushArrayData(string(1, kalimat[i])); // Masukkan karakter ke stack
    }
    // Membandingkan setengah karakter kedua dengan isi stack
    for (int i = (length + 1) / 2; i < length; i++)
    {
        // Jika karakter dari kalimat tidak sama dengan karakter pada stack,
        // berarti bukan palindrom, kembalikan false
        if (kalimat[i] != arrayData[top - 1][0])
        {
            return false;
        }
        popArrayData(); // Hapus karakter pada stack
    }
    // Jika semua karakter cocok, kembalikan true (kalimat adalah palindrom)
    return true;
}

int main()
{
    string kalimat;
    cout << "Masukkan kalimat : ";
    getline(cin, kalimat); // Meminta input kalimat dari pengguna

    // Memeriksa apakah kalimat adalah palindrom
    if (isPalindrom(kalimat))
    {
        cout << "Kalimat tersebut adalah palindrom" << endl;
    }
    else
    {
        cout << "Kalimat tersebut bukan palindrom" << endl;
    }

    return 0;
}
```
Output Jika Kalimat Palindrom :
![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/c872d95e-9daa-4941-8896-2d6bcfbedd9c)

Output Jika Kalimat Bukan Palindrom :
![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/4e004d06-94a2-4003-9e39-009b258826b9)

**Berikut Penjelasan Cara Kerja Program**

**1. Deklarasi Array dan Variabel:**

- `arrayData`: Array string untuk menyimpan data sementara.
- `maksimal`: Batas maksimum elemen dalam array (25).
- `top`: Indeks untuk menunjuk elemen teratas dalam array.

**2. Fungsi-fungsi:**

- `isFull()`: Mengecek apakah array sudah penuh.
- `isEmpty()`: Mengecek apakah array kosong.
- `pushArrayData(string kalimat)`: Menambahkan data ke dalam array.
    - Jika array penuh, program akan menampilkan pesan "Data telah penuh".
    - Jika tidak, data akan ditambahkan ke elemen array dengan indeks `top` dan nilai `top` akan bertambah 1.
- `popArrayData()`: Menghapus data dari array.
    - Jika array kosong, program akan menampilkan pesan "Tidak ada data yang dihapus".
    - Jika tidak, elemen array dengan indeks `top` - 1 akan dihapus dan nilai `top` akan berkurang 1.
- `isPalindrom(string kalimat)`: Mengecek apakah kalimat merupakan palindrom.
    - `length`: Menampung panjang kalimat.
    - **Memasukkan setengah karakter pertama ke dalam stack:**
        - Looping dari indeks 0 hingga setengah panjang kalimat (dibulatkan ke bawah).
        - Pada setiap iterasi, karakter pada indeks loop dimasukkan ke dalam array `arrayData` menggunakan fungsi `pushArrayData()`.
    - **Membandingkan setengah karakter kedua dengan isi stack:**
        - Looping dari indeks setengah panjang kalimat (dibulatkan ke atas) hingga panjang kalimat - 1.
        - Pada setiap iterasi:
            - Membandingkan karakter pada indeks loop dengan karakter teratas dalam stack (diakses menggunakan `arrayData[top - 1][0]`).
            - Jika tidak sama, fungsi mengembalikan nilai `false` (kalimat bukan palindrom).
            - Jika sama, karakter teratas dalam stack dihapus menggunakan fungsi `popArrayData()`.
    - Jika loop selesai tanpa ada karakter yang tidak sama, fungsi mengembalikan nilai `true` (kalimat palindrom).

**3. Fungsi Utama (main):**

- Mendapatkan input kalimat dari pengguna.
- Memanggil fungsi `isPalindrom()` untuk mengecek apakah kalimat palindrom.
- Menampilkan hasil pengecekan (palindrom atau bukan).

### 2. Soal mengenai Stack
Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan
stack dengan minimal 3 kata. Jelaskan output program dan source codenya
beserta operasi/fungsi yang dibuat?

```C++
#include <iostream>
#include <string>

using namespace std;

// Mendefinisikan array dan variabel top dan maksimal
string arrayData[25];       // Array untuk menyimpan data
int maksimal = 25, top = 0; // maksimal adalah ukuran maksimum array, top adalah indeks teratas dari array

// Fungsi untuk memeriksa apakah array penuh
bool isFull()
{
    return (top == maksimal); // Mengembalikan true jika top sama dengan maksimal
}

// Fungsi untuk memeriksa apakah array kosong
bool isEmpty()
{
    return (top == 0); // Mengembalikan true jika top adalah 0, artinya tidak ada data
}

// Fungsi untuk menambahkan data ke dalam array
void pushArrayData(string kalimat)
{
    if (isFull())
    { // Memeriksa apakah array penuh
        cout << "Data telah penuh" << endl;
    }
    else
    {
        arrayData[top] = kalimat; // Menambahkan data ke dalam array di posisi top
        top++;                    // Menaikkan nilai top
    }
}

// Fungsi untuk menghapus data dari array
void popArrayData()
{
    if (isEmpty())
    { // Memeriksa apakah array kosong
        cout << "Tidak ada data yang dihapus" << endl;
    }
    else
    {
        arrayData[top - 1] = ""; // Menghapus data dengan mengosongkan nilai pada posisi top-1
        top--;                   // Menurunkan nilai top
    }
}

// Fungsi untuk membalikkan kalimat
void reverseKalimat(string kalimat)
{
    for (char &c : kalimat)
    {
        pushArrayData(string(1, c)); // Memasukkan setiap karakter ke dalam stack
    }

    string reversedString = "";
    while (!isEmpty())
    {
        reversedString += arrayData[top - 1]; // Mengambil karakter dari stack untuk membentuk kalimat terbalik
        popArrayData();
    }

    cout << "Hasil\t: " << reversedString << endl; // Menampilkan kalimat terbalik
}

// Fungsi utama
int main()
{
    string kalimat;
    cout << "Masukkan kalimat : ";
    getline(cin, kalimat); // Meminta input kalimat dari pengguna

    cout << "Kalimat\t: " << kalimat << endl; // Menampilkan kalimat awal
    reverseKalimat(kalimat);                  // Memanggil fungsi untuk membalikkan kalimat

    return 0;
}
```

Output Pembalikan Kalimat :
![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/56212c25-e9ec-42b9-a06b-74459cfc7ea6)

Output dari program ini adalah membalikkan setiap karakter dalam input kalimat yang diberikan oleh pengguna. Setelah membalikkan, program menampilkan kalimat terbalik tersebut. Jadi, jika inputnya adalah "wUjUd AslI cAhAyA", outputnya akan menjadi "AyAhAc IlslA dUjUw".

program mendefinisikan sebuah array `arrayData` yang bertipe `string` untuk menyimpan data, serta dua variabel `maksimal` dan `top`. Variabel `maksimal` menentukan ukuran maksimum array, sedangkan `top` adalah indeks teratas dari array, yang menunjukkan posisi terakhir data yang dimasukkan.

Program kemudian mendefinisikan beberapa operasi/fungsi:

* **`isFull()`:** Fungsi ini memeriksa apakah array penuh dengan membandingkan nilai `top` dengan `maksimal`. Jika `top` sama dengan `maksimal`, maka array penuh dan fungsi ini akan mengembalikan nilai `true`.
* **`isEmpty()`:** Fungsi ini memeriksa apakah array kosong dengan membandingkan nilai `top` dengan 0. Jika `top` adalah 0, maka array kosong dan fungsi ini akan mengembalikan nilai `true`.
* **`pushArrayData()`:** Fungsi ini menambahkan data ke dalam array. Pertama, fungsi ini memeriksa apakah array penuh dengan menggunakan fungsi `isFull()`. Jika array penuh, fungsi ini akan menampilkan pesan "Data telah penuh". Jika array tidak penuh, fungsi ini akan menambahkan data ke dalam array di posisi `top` dan meningkatkan nilai `top`.
* **`popArrayData()`:** Fungsi ini menghapus data dari array. Pertama, fungsi ini memeriksa apakah array kosong dengan menggunakan fungsi `isEmpty()`. Jika array kosong, fungsi ini akan menampilkan pesan "Tidak ada data yang dihapus". Jika array tidak kosong, fungsi ini akan menghapus data di posisi `top-1` dan menurunkan nilai `top`.
* **`reverseKalimat()`:** Fungsi ini membalikkan kalimat dengan menggunakan stack. Pertama, fungsi ini memasukkan setiap karakter dari kalimat ke dalam stack dengan menggunakan fungsi `pushArrayData()`. Kemudian, fungsi ini membuat variabel string kosong bernama `reversedString`. Lalu, fungsi ini mengulangi loop while sampai stack kosong. Di dalam loop, fungsi ini menambahkan karakter dari stack ke variabel `reversedString` dengan menggunakan fungsi `popArrayData()`. Terakhir, fungsi ini menampilkan kalimat terbalik yang tersimpan dalam variabel `reversedString`.

Fungsi utama `main()` meminta pengguna untuk memasukkan sebuah kalimat, kemudian menampilkan kalimat tersebut. Selanjutnya, fungsi `reverseKalimat()` dipanggil untuk membalikkan kalimat tersebut, dan hasilnya ditampilkan.

## Kesimpulan

Dalam dunia pemrograman, struktur data stack adalah kumpulan elemen-elemen yang diatur berdasarkan prinsip Last In, First Out (LIFO), yang berarti elemen terakhir yang dimasukkan ke dalam stack akan menjadi elemen pertama yang dikeluarkan. Ini memungkinkan operasi-operasi seperti penambahan elemen (push) dan penghapusan elemen (pop) dilakukan dengan cepat dan efisien. Stack sering digunakan dalam penyelesaian masalah seperti pemanggilan fungsi dalam pemrograman dan manajemen memori dalam sistem komputer.

## Referensi

[1] Mulyana, A., et al., Cara Mudah Mempelajari Algoritma dan Struktur Data. Edisi Pertama. Yogyakarta : DIVA Press, 2021

[2] Universitas Bakrie, “Kenalan dengan Pengertian Stack dalam Pemrograman,” bakrie.ac.id. [Online]. Tersedia : https://bakrie.ac.id/articles/552-kenalan-dengan-pengertian-stack-dalam-pemrograman.html [Diakses 5 Mei 2024].

[3] Sitompul, D. U. A, et al, "Struktur Data Stack,". 2020, hlm. . URL: https://id.scribd.com/document/459268842/MAKALAH-STRUKTUR-DATA-STACK.
