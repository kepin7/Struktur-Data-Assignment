# <h1 align="center">Laporan Praktikum Modul Array</h1>

<p align="center">Hizkia Kevin Octaviano - 2311102185</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

Array (larik) ialah penampung sejumlah data sejenis
(homogen) yang menggunakan satu identifier (pengenal).
Masing-masing elemen larik diakses menggunakan indeks
(subscript) dari nol sampai n-1 (n menyatakan jumlah elemen
larik).
Pengolahan data larik harus per elemen. Elemen larik
dapat diakses langsung (acak). Tujuannya adalah untuk
memanipulasi elemen keempat tidak harus melalui elemen
pertama, kedua, dan ketiga. Berdasarkan banyaknya indeks,
larik dibagi menjadi larik satu dimensi dan multidimensi (dua
dimensi dan tiga dimensi)[1].

### 1. Array Satu Dimensi:

Array satu dimensi adalah kumpulan elemen yang bersebelahan di mana
individu elemen diidentifikasi oleh subskrip integer unik yang dimulai dengan
nol. Sekali array dibuat, ukurannya tidak dapat diubah[2]. Dapat
disebut juga dengan istilah vektor yang
menggambarkan data dalam suatu urutan

### 2. Array Dua Dimensi

Array dua demensi yakni suatu kumpulan elemen yang dapat dilakukan
penyimpanan secara terurut di suatu tempat yang terbagi menjadi dua 2 unsur
yakni baris dan kolom[2]. Sering digambarkan sebagai sebuah matriks yaitu sekumpulan informasi yang setiap individu
elemennya diacu dengan menggunakan dua buah indeks
(biasanya dikonotasikan dengan baris dan kolom)[1].

### 3. Array Multi Dimensi

Array multidimensi adalah larik yang berisi satu atau lebih larik. Array Multidimensi merupakan array yang serupa dengan array satu dimensi maupun array dua dimensi, namun array multidimensi dapat memiliki memori yang lebih besar. Biasanya array multidimensi digunakan untuk menyebut array dengan dimensi lebih dari dua atau array yang mempunyai lebih dari dua subskrip, seperti untuk menyebut array tiga dimensi, empat dimensi, lima dimensi dan seterusnya[3].

### Keunggulan dan Kelemahan Array:
#### Keunggulan: 
- Array sangat cocok
untuk pengaksesan acak.
Sembarang elemen di array
dapat diacu secara
langsung tanpa melalui
elemen-elemen lain.
- Jika berada di suatu
lokasi elemen, maka sangat
mudah menelusuri ke
elemen-elemen tetangga,
baik elemen pendahulu atau
elemen penerus 3.
- Jika elemen-elemen
array adalah nilai-nilai
independen dan seluruhnya harus terjaga,maka
penggunaan
penyimpanannya sangat
efisien.

#### Kelemahan:
Array mempunyai fleksibilitas
rendah, sehingga tidak cocok untuk
berbagai aplikasi karena array
mempunyai batasan sebagai
berikut:
- Array harus bertipe
homogen. Kita tidak dapat
mempunyai array dimana
satu elemenadalah karakter,
elemen lain bilangan, dan
elemen lain adalah tipe-tipe
lain.
- Kebanyakan bahasa
pemrograman
mengimplementasikan array
statik yang sulitdiubah
ukurannya di waktu
eksekusi. Bila penambahan
dan pengurangan
terjaditerus-menerus, maka
representasi statis.
- Tidak efisien dalam
penggunaan memori.
- Menyiakan banyak waktu
komputasi.

## [Guided](#guided)

### 1. Program Input Array Tiga Dimensi

```C++
#include <iostream>
using namespace std;
// PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
    // Deklarasi array
    int arr[2][3][3];
    // Input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }
    // Output Array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;
    // Tampilan array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
```

Kode diatas adalah program untuk melakukan operasi matematika dasar (penambahan, pengurangan, perkalian, dan pembagian) antara dua bilangan. Setelah pengguna memasukkan operator yang diinginkan (+, -, *, /), program kemudian meminta pengguna untuk memasukkan dua bilangan yang akan dioperasikan. Setelah menerima input, program menggunakan pernyataan switch-case untuk memeriksa operator yang dimasukkan oleh pengguna. Jika operator sesuai dengan salah satu kasus (+, -, *, /), maka program akan melakukan operasi yang sesuai sesuai dengan operator tersebut dan menampilkan hasilnya. Namun, jika operator yang dimasukkan tidak valid, program akan menampilkan pesan kesalahan.

### 2. Program Mencari Nilai Maksimal pada Array

```C++
#include <iostream>

using namespace std;

int main()
{
    // Deklarasi variabel
    int maks, a, i = 1, lokasi;

    // Input panjang array
    cout << "Masukkan panjang array : ";
    cin >> a;

    // Deklarasi array dengan panjang `a`
    int array[a];

    // Input nilai elemen array
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }

    // Inisialisasi variabel `maks` dengan nilai elemen array pertama
    maks = array[0];

    // Perulangan untuk mencari nilai maksimum
    for (i = 0; i < a; i++)
    {
        // Jika nilai elemen array lebih besar dari `maks`
        if (array[i] > maks)
        {
            // Update nilai `maks` dengan nilai elemen array
            maks = array[i];
            // Simpan lokasi elemen array dengan nilai maksimum
            lokasi = i;
        }
    }

    // Output nilai maksimum dan lokasinya
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
}

```

Kode di atas adalah merupakan program yang menggunakan struktur data atau struct untuk merepresentasikan informasi mahasiswa. Dalam struct `Mahasiswa`, terdapat tiga anggota yaitu `name` (nama), `address` (alamat), dan `age` (umur). Program kemudian membuat dua variabel bertipe struct Mahasiswa, yaitu `mhs1` dan `mhs2`, dan mengisi nilai untuk masing-masing variabel.

Selanjutnya, program mencetak informasi mahasiswa ke layar menggunakan fungsi `printf`, termasuk nama, alamat, dan umur untuk kedua mahasiswa. Hasilnya adalah mencetak informasi mahasiswa 1 (`mhs1`) dan mahasiswa 2 (`mhs2`) ke layar sesuai dengan nilai yang telah diisikan sebelumnya.

## Unguided

### 1. Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!
![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/340d2fb4-1930-4510-b102-a1a127500aa4)

```C++
#include <iostream>
using namespace std;

int main()
{
    // Deklarasi variabel
    int a;
    // Meminta pengguna untuk memasukkan jumlah array
    cout << "Masukkan jumlah array: ";
    cin >> a;
    // Deklarasi array dengan ukuran a
    int arr[a];

    // Input array
    cout << "Masukkan " << a << " angka\n";
    for (int i = 0; i < a; i++)
    {
        cout << "Array ke - " << i << ": ";
        cin >> arr[i];
    }
    cout << endl;

    // Output data array
    cout << "Data Array : ";
    for (int i = 0; i < a; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Menampilkan nomor genap
    cout << "Nomor Genap : ";
    for (int i = 0; i < a; i++)
    {
        if (arr[i] % 2 == 0)
        {
            cout << arr[i] << ", ";
        }
    }
    cout << endl;

    // Menampilkan nomor ganjil
    cout << "Nomor Ganjil : ";
    for (int i = 0; i < a; i++)
    {
        if (arr[i] % 2 != 0)
        {
            cout << arr[i] << ", ";
        }
    }
}

```

#### Output:

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/bba93a44-c7f7-45be-8e62-78f60ff109b6)

Program dimulai dengan menampilkan menu pilihan konversi suhu kepada pengguna. Setiap pilihan disertai dengan nomor yang berkaitan dan jenis konversi yang dilakukan, seperti dari Celsius ke Fahrenheit, Celsius ke Reamur, dan sebagainya. Setelah menampilkan menu, pengguna diminta untuk memilih opsi dengan memasukkan angka yang sesuai. Setelah memasukkan pilihan, program menggunakan pernyataan switch-case untuk menentukan tindakan yang akan diambil berdasarkan pilihan pengguna.

Misalnya, jika pengguna memilih opsi 3 (Konversi dari Celsius ke Kelvin), program akan meminta pengguna untuk memasukkan suhu dalam Celsius. Setelah pengguna memasukkan suhu, program akan menggunakan fungsi `celsius_to_kelvin` untuk mengkonversi suhu tersebut ke dalam satuan Kelvin. Hasil konversi kemudian dicetak ke layar menggunakan pernyataan `cout`. Jika pengguna memasukkan suhu Celsius 26, program akan menghitung dan mencetak suhu tersebut dalam satuan Kelvin. Misalnya, jika hasil konversi adalah 299.15, maka hasilnya akan dicetak sebagai "Suhu dalam Kelvin: 299.15".

```C++
#include <iostream>
using namespace std;

int main()
{
    // Deklarasi variabel untuk menyimpan jumlah baris, kolom, dan lapisan
    int x, y, z;
    // Meminta pengguna untuk memasukkan jumlah baris, kolom, dan lapisan
    cout << "Masukkan jumlah baris : ";
    cin >> x;
    cout << "Masukkan jumlah kolom : ";
    cin >> y;
    cout << "Masukkan jumlah lapisan : ";
    cin >> z;

    cout << endl;
    // Deklarasi array tiga dimensi dengan ukuran sesuai input pengguna
    int arr[x][y][z];

    // Perulangan untuk input elemen array
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                // Meminta pengguna untuk memasukkan nilai untuk setiap elemen array
                cout << "Input Array[" << i << "][" << j << "][" << k << "] = ";
                cin >> arr[i][j][k];
            }
        }
        cout << endl;
    }

    // Perulangan untuk output Array
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                // Cetak elemen data array
                cout << "Data Array[" << i << "][" << j << "][" << k << "] = " << arr[i][j][k] << endl;
            }
        }
    }
    cout << endl;

    // Perulangan untuk tampilan array
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                // Cetak elemen array
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}
```

#### Output:

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/1910c84b-678e-4d20-976a-9391d73cb263)

#### Struct Pegawai:

- `struct Pegawai` mendefinisikan struktur data untuk menampung informasi pegawai.
  
Struktur data ini memiliki tiga field :

- nama: Bertipe `string` untuk menyimpan nama pegawai.
- umur: Bertipe `int` untuk menyimpan usia pegawai.
- email: Bertipe `string` untuk menyimpan alamat email pegawai.

#### Class Pegawai1:

- `class Pegawai1` dan `class Pegawai2` mendefinisikan class untuk menampung informasi pegawai.
- `class Pegawai1` tidak mendeklarasikan akses publik, sehingga semua field dan methodnya bersifat private.
- `class Pegawai2` mendeklarasikan akses public untuk semua fieldnya, sehingga dapat diakses langsung dari luar class.

#### Fungsi main:

- Dua variabel bertipe `Pegawai` dan `Pegawai2` dideklarasikan, yaitu `pgw1` dan `pgw2`.
- Nilai field `nama`, `umur`, dan `email` untuk `pgw1` dan `pgw2` diisi.
- Informasi `pegawai pgw1` dan `pgw2` ditampilkan.

Program tersebut menunjukkan perbedaan dalam penggunaan class dan struct, terutama terkait dengan hak akses default anggota (private pada class, public pada struct). Objek `pgw1` menggunakan struct, sementara `pgw2` menggunakan class dengan hak akses public.

### 3. Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!

```C++
#include <iostream>
using namespace std;

int main()
{
    // Deklarasi variabel
    int a, i, maks, min, lokasi_maks, lokasi_min, total = 0, op;

    // Input panjang array
    cout << "Masukkan panjang array: ";
    cin >> a;

    // Deklarasi array dengan panjang `a`
    int array[a];

    // Input nilai elemen array
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << i << ": ";
        cin >> array[i];
        total += array[i];
    }

    // Inisialisasi variabel `maks` dan `min` dengan nilai elemen array pertama
    maks = min = array[0];
    lokasi_maks = lokasi_min = 0;

    // perulangan untuk mencari nilai maksimum dan minimum
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi_maks = i;
        }
        else if (array[i] < min)
        {
            min = array[i];
            lokasi_min = i;
        }
    }

    // menghitung nilai rata-rata
    float rata_rata = (float)total / a;

    // Menampilkan menu
    do
    {
        cout << "\n===== Menu =====\n";
        cout << "1. Mencari Nilai Maksimum\n";
        cout << "2. Mencari Nilai Minimum\n";
        cout << "3. Mencari Nilai Rata-rata\n";
        cout << "4. Keluar\n";
        cout << "Masukkan pilihan : ";
        cin >> op;

        switch (op)
        {
        case 1:
            // Output nilai maksimum dan lokasinya
            cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi_maks << endl;
            break;
        case 2:
            // Output nilai minimum dan lokasinya
            cout << "Nilai minimum adalah " << min << " berada di Array ke " << lokasi_min << endl;
            break;
        case 3:
            // Output nilai rata-rata
            cout << "Nilai rata-rata adalah " << rata_rata << endl;
            break;
        case 4:
            // Keluar dari program
            cout << "Thank you!, Code By Kevin" << endl;
            break;
        default:
            // pilihan tidak valid
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (op != 4);

    return 0;
}
```

#### Output:

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/f75af208-4731-476e-96fb-35164d4549ef)

program tersebut untuk menghitung jumlah kemunculan setiap karakter dalam sebuah kalimat yang dimasukkan oleh pengguna. Setelah pengguna memasukkan sebuah kalimat, program akan melakukan iterasi melalui setiap karakter dalam kalimat tersebut dan mengabaikan spasi. Kemudian, menggunakan struktur data map dari C++, program menyimpan jumlah kemunculan setiap karakter dalam sebuah map, di mana karakter adalah kunci dan jumlah kemunculannya adalah nilai. Setelah selesai menghitung, program akan menampilkan hasil hitungan tersebut dengan mencetak setiap karakter beserta jumlah kemunculannya ke layar.

## Kesimpulan

pemahaman tentang tipe data primitif, abstraksi kolektif, fungsi, struct, dan class adalah krusial. Tipe data primitif menyediakan dasar untuk menyimpan nilai tunggal, sementara abstraksi kolektif memungkinkan pengelompokkan data menjadi struktur yang lebih besar dan terorganisir. Fungsi, struct, dan class membantu dalam mengorganisir kode menjadi unit-unit yang dapat digunakan kembali dan memfasilitasi pemrograman berorientasi objek. Perbedaan antara array dan map juga penting untuk dipahami; array digunakan untuk koleksi elemen dengan tipe data yang sama, diakses melalui indeks numerik, sementara map menyimpan pasangan kunci-nilai yang memungkinkan akses cepat ke nilai berdasarkan kuncinya. Memahami konsep ini membantu pengembang dalam merancang dan mengimplementasikan solusi yang efisien, terstruktur, dan mudah dimengerti.
## Referensi

[1] Mulyana, A., et al., Cara Mudah Mempelajari Algoritma dan Struktur Data. Edisi Pertama. Yogyakarta : DIVA Press, 2021

[2] Zein, A. dan Eriana, E.S., Algoritma dan Struktur Data. Edisi Pertama. Tangerang Selatan : Unpam Press, 2022.

[3] Rus'an, J.A.P., “Program C++ : Array Multidimensi Menghitung Nilai Tertinggi, Perkalian Matriks, dan Rata-rata”, 30-Des-2022. [Online]. Available: https://medium.com/@jasmeinalbaar29/program-c-array-multidimensi-menghitung-nilai-tertinggi-perkalian-matriks-dan-rata-rata-3d175f2792da.

[4] A. Suhendar, “Struktur data sederhana (statis array)”, 30-Mar-2019. [Online]. Available: osf.io/s2r57.

[5] "cppreference", [Online]. Available: https://en.cppreference.com/w/. [Accessed: March 7, 2024].
