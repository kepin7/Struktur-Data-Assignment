# <h1 align="center">Laporan Praktikum Modul Array</h1>

<p align="center">Hizkia Kevin Octaviano - 2311102185</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

Tipe data merupakan klasifikasi jenis-jenis data yang berfungsi untuk menentukan data serta variabel yang dapat digunakan dalam suatu sistem dan operasi-operasi tertentu. Tipe data adalah semua himpunan yang ada pada semua data tanpa terkecuali[1]. Adanya klasifikasi data juga dapat membantu operasi komputer mengenali nilai data beserta instruksinya. Tipe data dibagi menjadi 3, antara lain :

### 1. Tipe Data Primitif:

Tipe data primitif merupakan tipe data yang dapat menyimpan satu nilai dan telah ditentukan oleh sistem. Bahasa pemrograman biasanya menyediakan tipe data sebagai bagian dari bahasa diri[2]. Tipe data ini, yang dikenal sebagai primitif. Berikut beberapa macam tipe data primitif :

- **Int**: Digunakan untuk menyimpan bilangan bulat seperti 10, 2, atau 4.
- **Float**: Menggunakan bilangan desimal seperti 1.5, 3.5, atau 3.14.
- **Char**: Berfungsi untuk menyimpan huruf atau simbol seperti A, B, C.
- **Boolean**: Digunakan untuk menyimpan nilai boolean, yaitu true atau false.

### 2. Tipe Data Abstrak:

Tipe data abstrak, atau Abstrak Data Type (ADT) adalah kelas atau tipe untuk objek yang perilakunya ditentukan oleh satu set nilai dan satu set operasi[2]. Proses memberikan hanya informasi dasar dan menyembunyikan detailnya disebut abstraksi[2]. Tipe data abstrak, atau Abstrak Data Type (ADT) pertama kali ditemukan oleh ilmuwan komputer dan digunakan untuk memisahkan struktur penyimpanan dari perilaku tipe data abstrak (seperti tumpukan dan antrian)[2]. Fitur yang dibentuk oleh programer dan bisa berisi berbagai jenis data. Fitur class dalam Object Oriented Programming (OOP) mirip dengan struktur data struct pada bahasa C++, dengan perbedaan akses default (public untuk struct, private untuk class).

### 3. Tipe Data Koleksi:

Tipe data koleksi digunakan untuk mengelompokkan dan menyimpan beberapa nilai atau objek secara bersamaan. Beberapa contoh tipe data koleksi meliputi:

- **Array**: Struktur data statis dengan elemen-elemen tipe data yang sama dan ukuran tetap.
- **Vector**: Mirip dengan array, untuk menyimpan data dalam bentuk elemen-elemen yang alokasi memorinya dilakukan secara otomatis dan bersebelahan.
- **Map**: Mirip dengan array, untuk menyimpan elemen-elemen dengan tipe data yang sama namun bisa digunakan pula untuk tipe data selain integer pada indeksnya, disebut "key", dan menggunakan struktur pohon self-balancing seperti Red-Black Tree pada std::map[3].

Tipe data koleksi memungkinkan pengelolaan dan akses data yang lebih terstruktur, sementara tipe data abstrak memberikan fleksibilitas dalam membentuk jenis data sesuai kebutuhan programer. Tipe data primitif, di sisi lain, sudah ditentukan oleh sistem dengan perbedaan tergantung pada bahasa pemrograman dan sistem operasional yang digunakan.

### Perbandingan Tipe Data:

| Tipe Data |           Definisi           |                         Karakteristik                         |         Contoh         |
| :-------: | :--------------------------: | :-----------------------------------------------------------: | :--------------------: |
| Primitif  | Dasar, disediakan bahasa C++ | Ukuran memori tetap, operasi aritmatika/logika, nilai default | int, float, char, bool |
|  Abstrak  | Dibuat programer, fleksibel  |          Struktur data statis, akses default berbeda          |     struct, class      |
|  Koleksi  |  Mengelompokkan nilai/objek  |         Pengelolaan/akses terstruktur, statis/dinamis         |   array, vector, map   |

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

#### Kesimpulan materi tipe data primitif :

Kesimpulan dari materi di atas adalah bahwa tipe data primitif adalah fondasi penting dalam pemrograman. Memahami jenis-jenis dan penggunaannya dengan baik akan membantu dalam penulisan kode yang lebih efisien dan mudah dipahami. Contoh tipe data primitif meliputi int untuk menyimpan bilangan bulat, float untuk bilangan desimal, char untuk huruf atau simbol, dan boolean untuk menyimpan nilai boolean dengan dua kemungkinan nilai, yaitu true atau false.

### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

#### Class 

Class berfungsi untuk mendeskripsikan suatu objek melalui data dan fungsi yang dimiliki. Class memiliki akses default private sehingga tidak semua variabel dapat dieksekusi apabila ada objek yang private. Jika objek anggota dari class tersebut ingin dipublikasikan, maka harus menggunakan `public :`[4]. Class memiliki properti dan metode. Class akan mengelola data yang akan diakses melalui metode (method).

#### Struct

Fungsi struct yaitu dapat menggabungkan sekumpulan variabel dan memberi nama pada variabel-variabel tersebut. Nama yang digunakan sama seperti tipe variabelnya, misalnya : int atau string. Struct dapat mendeklarasikan variabel baru dan mengakses semua kolom. Struct akan mengelola data yang akan diakses secara langsung. Struct memiliki akses default yang terbuka (secara public). Struct hanya dapat memiliki properti. Struct mendefinisikan tipe data dan menginstruksikan kepada C++ untuk mengelompokkan koleksi tipe data dasar sebagai kesatuan tipe data sehingga dapat mendefinisikan variabel dan array variabel.

#### Perbedaan

Perbedaan utama antara class dan struct adalah pada hak akses defaultnya. Dalam class, anggota bersifat private secara default, sementara dalam struct bersifat public secara default. Dengan class, kita dapat menggunakan hak akses private untuk menyembunyikan implementasi internal dari pengguna class, sementara struct lebih terbuka dan digunakan terutama untuk menyimpan data tanpa perilaku yang kompleks.

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

#### Perbedaan Dari Array dan Map:

`Array` merupakan sekumpulan data dengan tipe yang sama dan disimpan dalam satu variabel saja. Array menyimpan data yang memiliki urutan dan dapat diakses menggunakan indeks. Indeks dalam array digunakan untuk mengakses data.
`Map` merupakan sekumpulan key-value yang disimpan dalam satu variabel. Map menyimpan data yang memiliki hubungan key-value dan dapat diakses menggunakan key. Key dalam map digunakan untuk mengakses data. 
Dengan demikian, array menggunakan indeks untuk mengakses data, sedangkan map menggunakan key. Array dapat menyimpan data dengan tipe yang sama, sedangkan map dapat menyimpan key dan value dengan tipe yang berbeda. 

Singkatnya, array cocok untuk situasi dengan data yang memiliki ukuran tetap dan diakses secara numerik, sementara map lebih fleksibel dan berguna untuk data yang memiliki hubungan kunci-nilai yang unik.

## Kesimpulan

pemahaman tentang tipe data primitif, abstraksi kolektif, fungsi, struct, dan class adalah krusial. Tipe data primitif menyediakan dasar untuk menyimpan nilai tunggal, sementara abstraksi kolektif memungkinkan pengelompokkan data menjadi struktur yang lebih besar dan terorganisir. Fungsi, struct, dan class membantu dalam mengorganisir kode menjadi unit-unit yang dapat digunakan kembali dan memfasilitasi pemrograman berorientasi objek. Perbedaan antara array dan map juga penting untuk dipahami; array digunakan untuk koleksi elemen dengan tipe data yang sama, diakses melalui indeks numerik, sementara map menyimpan pasangan kunci-nilai yang memungkinkan akses cepat ke nilai berdasarkan kuncinya. Memahami konsep ini membantu pengembang dalam merancang dan mengimplementasikan solusi yang efisien, terstruktur, dan mudah dimengerti.
## Referensi

[1] Litalia. (2023, September 30). _Pengertian Tipe Data Beserta Fungsi dan Jenis-Jenis Tipe Data_ [online]. Available: https://www.jurnalponsel.com/pengertian-tipe-data/.

[2] Zein, A. dan Eriana, E.S., Algoritma dan Struktur Data. Edisi Pertama. Tangerang Selatan : Unpam Press, 2022.

[3] Paul J. Deitel and Harvey M. Deitel, C++20 Programming - Fundamentals to Advanced Features, 1st ed. Boston, MA, USA: Pearson, 2020.

[4] Tecom. (2010, Mei 24). _Struct dan Class pada C++_ [online]. Available: https://ainkhina.blogspot.com/2010/05/struct-pada-c.html?m=1.

[5] "cppreference", [Online]. Available: https://en.cppreference.com/w/. [Accessed: March 7, 2024].
