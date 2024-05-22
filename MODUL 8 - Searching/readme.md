# <h1 align="center">Laporan Praktikum Modul Searching</h1>

<p align="center">Hizkia Kevin Octaviano - 2311102185</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

Algoritma pencarian (searching algorithm) adalah algoritma yang menerima sebuah argumen kunci dan dengan langkah-langkah tertentu akan mencari rekaman dengan kunci tersebut [1]. Setelah dilakukan proses pencarian, maka akan diperoleh salah satu dari dua kemungkinan yaitu data yang dicari ditemukan (successful) atau data yang dicari tidak ditemukan (unsuccessful) [1].

Tehnik Pencarian meliput tehnik Sequential Search / Linier Search dan tehnik Binary Search[2].

### A. Sequential Search ###

Teknik dengan menggunakan algoritma searching yang sederhana dimana
pencarian secara runtun dengan melakukan pembanding antar elemen satu
satu secara urut diawali element pertama sampai ditemukannya data yang
diinginkan[2].

### B. Binary Search ###

Algoritma pencarian yang digunakan untuk mencari elemen dari array yang diurutkan. Kompleksitas waktu pencarian linier adalah O (n)[2]. Sedangkan kompleksitas
waktu pencarian biner adalah O (log n)[2]. Oleh karena itu, pencarian biner
adalah algoritma yang efisien dan lebih cepat mencari tetapi hanya dapat
digunakan untuk mencari dari array yang diurutkan[2].

## Guided

### 1. Program Pertama Sequential Search

```C++
#include <iostream>
using namespace std;
int main()
{
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;
    // algoritma Sequential Search
    for (i = 0; i < n; i++)
    {
        if (data[i] == cari)
        {
            ketemu = true;
            break;
        }
    }
    cout << "\t Program Sequential Search Sederhana\n " << endl;
    cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;
    if (ketemu)
    {
        cout << "\n angka " << cari << " ditemukan pada indeks ke - " << i << endl;
    }
    else
    {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }
    return 0;
}
``` 

Program mendefinisikan array data yang berisi sepuluh bilangan bulat. Kemudian, variabel `cari` digunakan untuk menentukan nilai yang akan dicari di dalam array. Variabel boolean `ketemu` diinisialisasi sebagai false, yang akan berubah menjadi true jika nilai yang dicari ditemukan dalam array. 

Selanjutnya, dilakukan iterasi menggunakan loop for melalui setiap elemen array. Pada setiap iterasi, nilai dari elemen array dicek apakah sama dengan nilai yang dicari (`cari`). Jika ditemukan, variabel `ketemu` diubah menjadi true, dan loop dihentikan menggunakan pernyataan `break`.

Setelah selesai melakukan iterasi, program menampilkan pesan berdasarkan apakah nilai yang dicari ditemukan atau tidak. Jika `ketemu` bernilai true, program akan menampilkan indeks di mana nilai tersebut ditemukan. Jika tidak ditemukan, program akan memberikan pesan bahwa nilai tersebut tidak ditemukan dalam array.

### 2. Program Pertama Binary Search

```C++
#include <iostream>
#include <iomanip>
using namespace std;
// Deklarasi array dan variabel untuk pencarian
int arrayData[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;
void selection_sort(int arr[], int n)
{
    int temp, min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        // Tukar elemen
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
void binary_search(int arr[], int n, int target)
{
    int awal = 0, akhir = n - 1, tengah, b_flag = 0;
    while (b_flag == 0 && awal <= akhir)
    {
        tengah = (awal + akhir) / 2;
        if (arr[tengah] == target)
        {
            b_flag = 1;
            break;
        }
        else if (arr[tengah] < target)
        {
            awal = tengah + 1;
        }
        else
        {
            akhir = tengah - 1;
        }
    }
    if (b_flag == 1)
        cout << "\nData ditemukan pada index ke-" << tengah << endl;
    else
        cout << "\nData tidak ditemukan\n";
}
int main()
{
    cout << "\tBINARY SEARCH" << endl;
    cout << "\nData awal: ";
    // Tampilkan data awal
    for (int x = 0; x < 7; x++)
    {
        cout << setw(3) << arrayData[x];
    }
    cout << endl;
    cout << "\nMasukkan data yang ingin Anda cari: ";
    cin >> cari;
    // Urutkan data dengan selection sort
    selection_sort(arrayData, 7);
    cout << "\nData diurutkan: ";
    // Tampilkan data setelah diurutkan
    for (int x = 0; x < 7; x++)
    {
        cout << setw(3) << arrayData[x];
    }
    cout << endl;
    // Lakukan binary search
    binary_search(arrayData, 7, cari);
    return 0;
}
``` 

Program mendeklarasikan sebuah array bernama `arrayData` yang berisi beberapa nilai integer yang belum diurutkan. Kemudian, program mendefinisikan fungsi `selection_sort` untuk mengurutkan array tersebut menggunakan algoritma selection sort. Selanjutnya, ada fungsi `binary_search` yang akan melakukan pencarian nilai tertentu dalam array yang telah diurutkan menggunakan algoritma binary search. 

Fungsi `main` akan menjalankan program secara keseluruhan. Pertama-tama, program akan menampilkan data awal yang belum diurutkan. Kemudian, pengguna diminta untuk memasukkan nilai yang ingin dicari. Selanjutnya, program akan mengurutkan array tersebut menggunakan fungsi `selection_sort`, menampilkan data yang telah diurutkan, dan kemudian melakukan pencarian menggunakan fungsi `binary_search`. Hasil pencarian, yaitu apakah data ditemukan atau tidak, akan ditampilkan ke pengguna beserta indeksnya jika data ditemukan. Jika data tidak ditemukan, program akan memberikan pesan bahwa data tersebut tidak ditemukan dalam array.

## Unguided

### 1. Soal mengenai Searching
Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!

```C++
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Fungsi untuk mengurutkan string menggunakan algoritma Selection Sort
void selectionSort(string &str)
{
    int a = str.length(); // Mendapatkan panjang string
    // Melakukan iterasi sepanjang string
    for (int i = 0; i < a - 1; i++)
    {
        int min = i; // Menganggap elemen pertama sebagai elemen terkecil
        // Mencari elemen terkecil di antara elemen yang belum diurutkan
        for (int j = i + 1; j < a; j++)
        {
            if (str[j] < str[min])
            {
                min = j; // Menyimpan indeks elemen terkecil yang ditemukan
            }
        }
        // Menukar elemen terkecil dengan elemen pertama yang belum diurutkan
        if (min != i)
        {
            swap(str[i], str[min]);
        }
    }
}

// Fungsi untuk melakukan pencarian biner dalam string
void binarySearch(const string &str, char target)
{
    int awal = 0, akhir = str.length() - 1; // Inisialisasi indeks awal dan akhir
    bool found = false;                     // Flag untuk menandai apakah huruf ditemukan
    while (awal <= akhir)
    {
        int tengah = awal + (akhir - awal) / 2; // Menghitung indeks tengah
        if (str[tengah] == target)              // Jika huruf ditemukan
        {
            found = true;
            cout << "Huruf '" << target << "' ditemukan pada index : ";
            // Mencari semua kemunculan huruf target
            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] == target)
                {
                    cout << i << ", ";
                }
            }
            break; // Keluar dari loop setelah semua kemunculan ditemukan
        }
        else if (str[tengah] < target) // Jika huruf di tengah kurang dari target
        {
            awal = tengah + 1; // Mencari di setengah kanan array
        }
        else // Jika huruf di tengah lebih dari target
        {
            akhir = tengah - 1; // Mencari di setengah kiri array
        }
    }
    if (!found) // Jika huruf tidak ditemukan dalam string
    {
        cout << "Huruf '" << target << "' tidak ditemukan." << endl;
    }
}

int main()
{
    string kalimat;   // Variabel untuk menyimpan kalimat yang dimasukkan pengguna
    char hurufTarget; // Variabel untuk menyimpan huruf target yang dimasukkan pengguna

    cout << "=========== Program pencarian huruf =========== " << endl;
    cout << "Masukkan kalimat : "; // Meminta pengguna untuk memasukkan kalimat
    getline(cin, kalimat);         // Membaca input kalimat dari pengguna

    cout << "Masukkan huruf yang ingin di cari : "; // Meminta pengguna untuk memasukkan huruf target
    cin >> hurufTarget;

    selectionSort(kalimat); // Mengurutkan seluruh karakter dalam kalimat
    cout << endl;

    cout << "===================== Hasil ===================" << endl;
    
    cout << "Kata yang sudah diurutkan : "; // Menampilkan kalimat yang sudah di urutkan
    for (int i = 0; i < kalimat.length(); i++)
    {
        cout << setw(3) << kalimat[i];
    }
    cout << endl;

    binarySearch(kalimat, hurufTarget); // Mencari kemunculan huruf target dalam kalimat

    return 0;
}
```
Output Program :

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/0d766bb5-af02-4289-b3b0-96933f767287)

Awal-awal Program mengurutkan karakter-karakter dalam kalimat menggunakan algoritma Selection Sort dan mencari kemunculan huruf target dalam kalimat menggunakan pencarian biner (binary search).

Di dalam fungsi `selectionSort`, algoritma Selection Sort digunakan untuk mengurutkan karakter-karakter dalam string `str`. Algoritma ini bekerja dengan memilih elemen terkecil dari sisa array yang belum diurutkan pada setiap iterasi, lalu menukarnya dengan elemen pertama yang belum diurutkan. Hal ini dilakukan hingga semua elemen terurut.

Fungsi `binarySearch` digunakan untuk melakukan pencarian biner dalam string `str` terurut. Pencarian dimulai dengan memeriksa elemen di tengah string, jika elemen tersebut sama dengan huruf target, maka program akan mencetak indeks semua kemunculan huruf tersebut dalam string. Jika tidak, program akan memperbarui batas pencarian sesuai dengan apakah elemen tersebut lebih besar atau lebih kecil dari huruf target, dan mencari lagi di setengah array yang relevan. Proses ini berlanjut hingga elemen ditemukan atau batas pencarian tidak lagi valid.

Dalam fungsi `main`, pengguna diminta untuk memasukkan sebuah kalimat dan sebuah huruf target. Kemudian, fungsi `selectionSort` dipanggil untuk mengurutkan karakter-karakter dalam kalimat, dan hasilnya ditampilkan. Setelah itu, fungsi `binarySearch` dipanggil untuk mencari kemunculan huruf target dalam kalimat yang sudah diurutkan, dan hasil pencarian ditampilkan.

### 2. Soal mengenai Searching
Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

```C++
#include <iostream> 
#include <string>   
using namespace std; 

// Fungsi untuk mengecek apakah sebuah karakter adalah huruf vokal
bool cek_huruf(char v)
{
    // Konversi karakter ke huruf kecil
    v = tolower(v);

    // Mengecek apakah karakter adalah salah satu huruf vokal
    return v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u';
}

int main()
{
    // Deklarasi variabel
    string kalimat;  // Variabel untuk menyimpan kalimat yang diinput oleh pengguna
    int jumlahvokal = 0; // Variabel untuk menyimpan jumlah huruf vokal
    int index = 0;   // Variabel untuk menyimpan posisi huruf dalam kalimat (tanpa spasi)

    // Mengambil input kalimat dari pengguna
    cout << "============ Program mencari huruf vokal ============" << endl;
    cout << "Masukkan kalimat : ";
    getline(cin, kalimat); // Mengambil input kalimat lengkap dari pengguna

    // Menghitung jumlah vokal
    for (char huruf : kalimat) // Loop untuk setiap karakter dalam kalimat
    {
        if (cek_huruf(huruf)) // Memeriksa apakah karakter tersebut adalah vokal
        {
            jumlahvokal++; // Jika ya, tambahkan ke jumlah vokal
        }
    }
    cout << endl;

    cout << "====================== Hasil ========================" << endl;
    // Menampilkan hasil
    cout << "Jumlah huruf vokal : " << jumlahvokal << endl;

    // Menghitung dan menampilkan indeks huruf vokal
    cout << "Huruf vokal terdapat pada index : ";
    for (int i = 0; i < kalimat.length(); i++) // Loop untuk setiap karakter dalam kalimat
    {
        if (kalimat[i] != ' ') 
        {
            index++; 
            if (cek_huruf(kalimat[i])) // Memeriksa apakah karakter adalah vokal
            {
                cout << index << ", "; // Jika ya, cetak indeks posisi karakter tersebut
            }
        }
    }

    return 0; 
}
```

Output Program :

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/ab3a07f0-3c87-4e0d-b068-9dba5b4aa673)

Program meminta pengguna untuk memasukkan sebuah kalimat. Kalimat tersebut disimpan dalam variabel `kalimat` menggunakan fungsi `getline(cin, kalimat)`. Selanjutnya, program menggunakan sebuah fungsi bernama `cek_huruf` untuk memeriksa apakah suatu karakter adalah huruf vokal. Fungsi ini melakukan konversi karakter ke huruf kecil menggunakan `tolower` dan kemudian membandingkannya dengan karakter-karakter vokal ('a', 'e', 'i', 'o', 'u'). 

Setelah itu, program melakukan iterasi melalui setiap karakter dalam kalimat menggunakan loop `for (char huruf : kalimat)`. Di dalam loop ini, setiap karakter diperiksa menggunakan fungsi `cek_huruf`, dan jika karakter tersebut merupakan huruf vokal, variabel `jumlahvokal` akan bertambah.

Setelah menghitung jumlah huruf vokal, program kemudian menampilkan hasilnya. Selanjutnya, program mencari dan menampilkan indeks posisi dari huruf vokal dalam kalimat. Ini dilakukan dengan menggunakan loop `for` lagi untuk memeriksa setiap karakter dalam kalimat. Jika karakter tersebut bukan spasi, variabel `index` akan bertambah. Jika karakter tersebut adalah huruf vokal, indeks posisi karakter tersebut akan dicetak.

### 3. Soal mengenai Searching
Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!
```C++
#include <iostream>
using namespace std;

int main()
{
    int n = 10;                                     // Jumlah elemen dalam array data
    int data[n] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}; // Array data dengan nilai-nilai yang akan dicari
    int cari = 4;                                   // Angka yang akan dicari dalam array data
    int index[n];                                   // Array untuk menyimpan indeks di mana angka ditemukan
    int count = 0;                                  // Untuk menghitung kemunculan angka
    bool ketemu = false;                            // Variabel untuk menandai apakah angka ditemukan atau tidak

    // Algoritma Sequential
    for (int i = 0; i < n; i++)
    {
        if (data[i] == cari) // Memeriksa apakah elemen saat ini sama dengan angka yang dicari
        {
            ketemu = true;    // Menandai bahwa angka ditemukan
            index[count] = i; // Menyimpan indeks di mana angka ditemukan
            count++;          // Menambah hitungan kemunculan angka
        }
    }

    // Menampilkan informasi tentang pencarian
    cout << "Program Sequential Search Sederhana\n" << endl;

    // Menampilkan data awal
    cout << "DATA = [ ";
    for (int i = 0; i < n; i++)
    {
        cout << data[i] << ", ";
    }
    cout << "]" << endl;

    // Menampilkan hasil pencarian
    if (ketemu) // Jika angka ditemukan
    {
        cout << "\nAngka " << cari << " muncul " << count << " kali dalam data." << endl;

        if (count > 0) // Jika angka muncul setidaknya satu kali
        {
            cout << "Angka " << cari << " ditemukan pada index : ";
            for (int i = 0; i < count; i++)
            {
                cout << index[i]; // Menampilkan indeks di mana angka ditemukan
                if (i != count - 1)
                {
                    cout << ", ";
                }
            }
            cout << endl;
        }
    }
    else // Jika angka tidak ditemukan
    {
        cout << "Angka " << cari << " tidak dapat ditemukan pada data." << endl;
    }

    return 0;
}
```

Output Program :

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/64aa40b7-8ffc-486b-b329-7163b346aba1)

Program ini terdapat sebuah array `data` yang berisi sekumpulan nilai, dan sebuah variabel `cari` yang merupakan angka yang akan dicari dalam array tersebut. Selain itu, terdapat array `index` yang digunakan untuk menyimpan indeks di mana angka yang dicari ditemukan, serta variabel `count` untuk menghitung jumlah kemunculan angka yang dicari, dan variabel `ketemu` untuk menandai apakah angka tersebut ditemukan atau tidak.

Program menggunakan algoritma pencarian sekuensial dengan melakukan iterasi melalui setiap elemen dalam array `data`. Setiap elemen dicek apakah sama dengan angka yang dicari. Jika ditemukan, variabel `ketemu` diset menjadi true, dan indeks di mana angka tersebut ditemukan disimpan dalam array `index`. Jumlah kemunculan angka yang dicari juga dihitung.

Setelah proses pencarian selesai, program menampilkan informasi tentang hasil pencarian, yaitu apakah angka tersebut ditemukan atau tidak, dan jika iya, berapa kali kemunculannya serta indeks di mana angka tersebut ditemukan.

## Kesimpulan

Berikut ini adalah kesimpulan dalam paragraf tentang materi searching pada C++:

Pencarian (searching) merupakan struktur data dalam pengolahan data. Terdapat beberapa algoritma pencarian yang dapat digunakan, seperti sequential search dan binary search. Sequential search merupakan metode pencarian sederhana yang memeriksa setiap elemen dalam array secara berurutan hingga elemen yang dicari ditemukan atau seluruh elemen telah diperiksa. Sementara itu, binary search merupakan metode pencarian yang lebih efisien untuk array yang telah diurutkan. Algoritma ini membagi array menjadi dua bagian dan mencari elemen target pada salah satu bagian tersebut. Proses ini diulang terus menerus hingga elemen target ditemukan atau seluruh elemen telah diperiksa. Pemilihan algoritma pencarian yang tepat sangat penting untuk memastikan efisiensi dan kinerja program, terutama ketika berurusan dengan set data besar.
## Referensi

[1] Putro, S.S. et al., Algoritma Pemrograman. Edisi Pertama. Malang : Media Nusa Creative (MNC Publishing), 2019.

[2] Zein, A. dan Eriana, E.S., Algoritma dan Struktur Data. Edisi Pertama. Tangerang Selatan : Unpam Press, 2022.
