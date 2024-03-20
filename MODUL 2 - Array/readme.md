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
elemen-elemen lain[4].
- Jika berada di suatu
lokasi elemen, maka sangat
mudah menelusuri ke
elemen-elemen tetangga,
baik elemen pendahulu atau
elemen penerus 3[4].
- Jika elemen-elemen
array adalah nilai-nilai
independen dan seluruhnya harus terjaga, maka
penggunaan
penyimpanannya sangat
efisien[4].

#### Kelemahan:
Array mempunyai fleksibilitas
rendah, sehingga tidak cocok untuk
berbagai aplikasi karena array
mempunyai batasan sebagai
berikut:
- Array harus bertipe
homogen. Kita tidak dapat
mempunyai array dimana
satu elemen adalah karakter,
elemen lain bilangan, dan
elemen lain adalah tipe-tipe
lain[4].
- Kebanyakan bahasa
pemrograman
mengimplementasikan array
statik yang sulit diubah
ukurannya di waktu
eksekusi. Bila penambahan
dan pengurangan
terjadi terus-menerus, maka
representasi statis[4].
- Tidak efisien dalam
penggunaan memori[4].
- Menyiakan banyak waktu
komputasi[4].

## Guided

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

program mendeklarasikan array `arr` dengan dimensi `[2][3][3]`. Kemudian, program meminta pengguna untuk memasukkan nilai-nilai ke dalam array tersebut dengan menggunakan tiga nested loop. Pertama, loop pertama digunakan untuk mengakses elemen di dimensi pertama `x`, loop kedua untuk dimensi kedua `y`, dan loop ketiga untuk dimensi ketiga `z`. Setelah selesai memasukkan nilai, program kemudian menampilkan nilai-nilai yang telah dimasukkan.

Selanjutnya, program akan menampilkan kembali nilai-nilai array dalam format yang terstruktur dengan mencetak indeks `x`, `y`, `z`, beserta nilainya. Terakhir, program akan menampilkan kembali nilai-nilai array dalam format yang lebih sederhana tanpa indeks `x`, `y`, `z`, hanya nilai-nilainya saja.

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

Program meminta untuk memasukkan panjang array yang diinginkan. Setelah panjang array dimasukkan, program mendeklarasikan array dengan panjang tersebut. Kemudian, program meminta user untuk memasukkan nilai-nilai elemen array satu per satu.

Setelah semua nilai dimasukkan, program melakukan iterasi melalui setiap elemen array untuk menemukan nilai maksimum. Variabel `maks` diinisialisasi dengan nilai elemen pertama array. Selanjutnya, program membandingkan setiap elemen array dengan nilai `maks`. Jika nilai elemen array saat ini lebih besar dari `maks`, maka nilai `maks` diperbarui dengan nilai elemen array tersebut, dan lokasi elemen tersebut disimpan dalam variabel `lokasi`.

Setelah proses selesai, program mengeluarkan hasil berupa nilai maksimum yang ditemukan beserta lokasinya dalam array.

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

Program meminta user untuk memasukkan jumlah elemen array yang diinginkan. Nilai ini disimpan dalam variabel `a`. Kemudian, array `arr` dideklarasikan dengan ukuran yang sesuai dengan nilai `a`.

Selanjutnya, user diminta untuk memasukkan `a` buah angka, satu per satu. Setiap angka yang dimasukkan akan disimpan dalam array `arr`. Setelah itu, program akan menampilkan kembali data array yang telah dimasukkan oleh user.

Kemudian, program memulai iterasi melalui array `arr` untuk memisahkan angka genap dan ganjil. Dalam loop pertama, setiap elemen array diuji apakah merupakan angka genap atau tidak dengan menggunakan operasi modulo `%`. Jika sisa pembagian dengan 2 adalah 0, maka angka tersebut adalah angka genap dan akan ditampilkan. Begitu juga dalam loop kedua, hanya saja kondisinya untuk menampilkan angka ganjil.

Setelah loop-loop tersebut selesai, program akan mengakhiri eksekusinya.

Program tersebut memberikan pengguna kemampuan untuk memasukkan sejumlah angka, menyimpannya dalam array, dan menampilkan kembali angka-angka tersebut bersama dengan pemisahan antara angka genap dan ganjil.

### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

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

Program ini meminta user untuk memasukkan jumlah baris, kolom, dan lapisan, dan kemudian membuat array tiga dimensi sesuai dengan input tersebut. Setelah itu, program meminta user untuk mengisi nilai-nilai array tersebut dan mencetak nilai-nilai tersebut lalu program mencetak array dalam format yang rapi.

Program mendeklarasikan variabel `x`, `y`, dan `z` untuk menyimpan jumlah baris, kolom, dan lapisan.
User diminta untuk memasukkan jumlah baris, kolom, dan lapisan menggunakan `cin`.
Array tiga dimensi `arr` dideklarasikan dengan ukuran yang sesuai dengan input user.
Program menggunakan tiga perulangan bersarang untuk meminta user memasukkan nilai untuk setiap elemen array.
Setelah semua nilai dimasukkan, program mencetak nilai-nilai array tersebut dengan menggunakan perulangan bersarang lagi.
Kemudian, program mencetak nilai array dalam format yang lebih rapi dengan cara mencetak elemen-elemen array satu per satu dalam baris yang sama sebelum berpindah ke baris berikutnya. Program selesai dijalankan setelah mencetak array dalam format yang rapi.

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

Program dimulai dengan mendeklarasikan beberapa variabel, termasuk variabel untuk menyimpan panjang array `a`, iterasi `i`, nilai maksimum `maks` dan minimum `min`, lokasi nilai maksimum `lokasi_maks` dan minimum `lokasi_min`, total elemen array `total`, serta opsi menu `op`.

User diminta untuk memasukkan panjang array melalui input dari keyboard. Sebuah array dengan panjang yang ditentukan oleh pengguna kemudian dideklarasikan `int array[a]` untuk menyimpan elemen-elemen array. User diminta untuk memasukkan nilai-nilai elemen array satu per satu melalui input dari keyboard. Selama pengguna memasukkan nilai, total elemen array juga dihitung. Nilai maksimum `maks` dan minimum `min` diinisialisasi dengan nilai dari elemen array pertama. Lokasi maksimum `lokasi_maks` dan minimum `lokasi_min` juga diinisialisasi dengan indeks 0. Dilakukan perulangan untuk memeriksa setiap elemen array. Jika nilai elemen array saat ini lebih besar dari nilai maksimum yang ditemukan sebelumnya, maka nilai maksimum dan lokasinya diperbarui. Begitu juga untuk nilai minimum. Setelah selesai mencari nilai maksimum dan minimum, nilai rata-rata dari semua elemen array dihitung. Program memasuki loop `do-while` untuk menampilkan menu kepada user dan meminta input opsi menu. menampilkan sebuah menu yang memungkinkan pengguna untuk memilih opsi, antara lain:

1. menu no `1` Mencari Nilai Maksimum: Menampilkan nilai maksimum beserta lokasinya dalam array.
2. menu no `2` Mencari Nilai Minimum: Menampilkan nilai minimum beserta lokasinya dalam array.
3. menu no `3` Mencari Nilai Rata-rata: Menampilkan nilai rata-rata dari elemen-elemen array.
4. menu no `4` Keluar: Mengakhiri program.

Perulangan akan terus berlanjut sampai pengguna memilih opsi `4` untuk keluar (`op == 4`), di mana program akan menampilkan pesan terima kasih dan keluar dari program.

## Kesimpulan

Array merupakan struktur data yang digunakan untuk menyimpan kumpulan nilai yang serupa dengan tipe data yang sama dalam satu variabel. Dalam array, elemen-elemen disimpan secara berurutan dalam memori dan diakses melalui indeks. Penggunaan array memungkinkan pengelolaan data yang efisien dan memudahkan akses terhadap nilai-nilai tersebut. Namun, perlu diingat bahwa ukuran array biasanya tetap setelah dideklarasikan, sehingga perlu hati-hati dalam pengelolaan memori agar tidak terjadi overflow atau underflow. Array juga memungkinkan penggunaan banyak algoritma dan teknik pemrograman yang berguna, seperti pencarian dan pengurutan. Dengan pemahaman yang baik tentang array dalam C++, program dapat lebih efisien dan mudah untuk dikembangkan.

## Referensi

[1] Mulyana, A., et al., Cara Mudah Mempelajari Algoritma dan Struktur Data. Edisi Pertama. Yogyakarta : DIVA Press, 2021

[2] Zein, A. dan Eriana, E.S., Algoritma dan Struktur Data. Edisi Pertama. Tangerang Selatan : Unpam Press, 2022.

[3] Rus'an, J.A.P., “Program C++ : Array Multidimensi Menghitung Nilai Tertinggi, Perkalian Matriks, dan Rata-rata”, 30-Des-2022. [Online]. Available: https://medium.com/@jasmeinalbaar29/program-c-array-multidimensi-menghitung-nilai-tertinggi-perkalian-matriks-dan-rata-rata-3d175f2792da.

[4] A. Suhendar, “Struktur data sederhana (statis array)”, 30-Mar-2019. [Online]. Available: https://osf.io/preprints/osf/s2r57.

[5] "geeksforgeeks", [Online]. Available: https://www.geeksforgeeks.org/. [Accessed: March 15, 2024].
