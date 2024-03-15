# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>

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

### 1. Tipe Data Primitif

```C++
#include <iostream>

using namespace std;

int main()
{
    char op;
    float num1, num2;
    // it allows user to enter operator i,e, +, -, *, /
    cin >> op;
    // it allows user to enter the operands
    cin >> num1 >> num2;
    // switch statement begins
    switch (op)
    {
    // if user center +
    case '+':
        cout << num1 + num2;
        break;
    // if user center -
    case '-':
        cout << num1 - num2;
        break;
    // if user center *
    case '*':
        cout << num1 * num2;
        break;
    // if user center /
    case '/':
        cout << num1 / num2;
        break;
    // if the operator is other than +,-,* or /,
    // error message will be display
    default:
        cout << "Error! operator is not correct";
    } // switch statement ends
    return 0;
}
```

Kode diatas adalah program untuk melakukan operasi matematika dasar (penambahan, pengurangan, perkalian, dan pembagian) antara dua bilangan. Setelah pengguna memasukkan operator yang diinginkan (+, -, *, /), program kemudian meminta pengguna untuk memasukkan dua bilangan yang akan dioperasikan. Setelah menerima input, program menggunakan pernyataan switch-case untuk memeriksa operator yang dimasukkan oleh pengguna. Jika operator sesuai dengan salah satu kasus (+, -, *, /), maka program akan melakukan operasi yang sesuai sesuai dengan operator tersebut dan menampilkan hasilnya. Namun, jika operator yang dimasukkan tidak valid, program akan menampilkan pesan kesalahan.

### 2. Tipe Data Abstrak

```C++
#include <stdio.h>

// struct
struct Mahasiswa
{
    const char *name;
    const char *address;
    int age;
};

int main()
{
    // menggunakan struct
    struct Mahasiswa mhs1, mhs2;
    // mengisi nilai ke struct
    mhs1.name = "Dian";
    mhs1.address = "Mataram";
    mhs1.age = 22;
    mhs2.name = "Bambang";
    mhs2.address = "Surabaya";
    mhs2.age = 23;

    // mencetak isi struct
    printf("## Mahasiswa 1 ##\n");
    printf("Name : %s\n", mhs1.name);
    printf("Address : %s\n", mhs1.address);
    printf("Age : %d\n", mhs1.age);
    printf("## Mahasiswa 2 ##\n");
    printf("Name : %s\n", mhs2.name);
    printf("Address : %s\n", mhs2.address);
    printf("Age : %d\n", mhs2.age);
    return 0;
}
```

Kode di atas adalah merupakan program yang menggunakan struktur data atau struct untuk merepresentasikan informasi mahasiswa. Dalam struct `Mahasiswa`, terdapat tiga anggota yaitu `name` (nama), `address` (alamat), dan `age` (umur). Program kemudian membuat dua variabel bertipe struct Mahasiswa, yaitu `mhs1` dan `mhs2`, dan mengisi nilai untuk masing-masing variabel.

Selanjutnya, program mencetak informasi mahasiswa ke layar menggunakan fungsi `printf`, termasuk nama, alamat, dan umur untuk kedua mahasiswa. Hasilnya adalah mencetak informasi mahasiswa 1 (`mhs1`) dan mahasiswa 2 (`mhs2`) ke layar sesuai dengan nilai yang telah diisikan sebelumnya.

### 3. Tipe Data Koleksi

```C++
#include <iostream>
using namespace std;
int main()
{
    //deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;

    //mencetak array
    cout << "Isi array pertama :" << nilai[0] << endl;
    cout << "Isi array kedua :" << nilai[1] << endl;
    cout << "Isi array ketiga :" << nilai[2] << endl;
    cout << "Isi array keempat :" << nilai[3] << endl;
    cout << "Isi array kelima :" << nilai[4] << endl;
    return 0;
}
```

kode tersebut dimulai dengan deklarasi array `nilai` dengan ukuran 5 elemen bertipe integer. Kemudian, setiap elemen dari array tersebut diinisialisasi dengan nilai-nilai tertentu: `nilai[0]` diinisialisasi dengan nilai 23, `nilai[1]` diinisialisasi dengan nilai 50, `nilai[2]` diinisialisasi dengan nilai 34, `nilai[3]` diinisialisasi dengan nilai 78, dan `nilai[4]` diinisialisasi dengan nilai 90. Selanjutnya, program mencetak nilai dari setiap elemen array menggunakan pernyataan `cout`, masing-masing diikuti dengan nomor indeksnya dan nilai yang disimpan di dalamnya. Setelah mencetak nilai dari semua elemen array, program mengakhiri eksekusi dan mengembalikan nilai 0, menandakan bahwa program telah dijalankan dengan sukses. Ini adalah alur kerja program yang sederhana namun efektif untuk menampilkan isi dari sebuah array dengan menggunakan perulangan.

## Unguided

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++
#include <iostream>
using namespace std;

// Fungsi untuk mengkonversi suhu dari Celsius ke Fahrenheit
float celsius_to_fahrenheit(float celsius){
    return (celsius * 9 / 5) + 32;
}
// Fungsi untuk mengkonversi suhu dari Celsius ke Reamur
float celsius_to_reamur(float celsius){
    return celsius * 4 / 5;
}

// Fungsi untuk mengkonversi suhu dari Celsius ke Kelvin
float celsius_to_kelvin(float celsius){
    return celsius + 273.15;
}

// Fungsi untuk mengkonversi suhu dari Fahrenheit ke Celsius
float fahrenheit_to_celsius(float fahrenheit){
    return (fahrenheit - 32) * 5 / 9;
}

// Fungsi untuk mengkonversi suhu dari Reamur ke Celsius
float reamur_to_celsius(float reamur){
    return reamur * 5 / 4;
}

// Fungsi untuk mengkonversi suhu dari Kelvin ke Celsius
float kelvin_to_celsius(float kelvin){
    return kelvin - 273.15;
}

int main(){

    // Deklarasi variabel yang digunakan untuk memproses menu pilihan user
    int pilih;
    // Deklarasi variabel yang digunakan untuk menampung data input dari user
    float temperature;

    // Menampilkan menu pilihan konversi
    cout << "Program Konversi Suhu" << endl;
    cout << "======================" << endl;
    cout << "Pilih jenis konversi:" << endl;
    cout << "1. Celsius ke Fahrenheit" << endl;
    cout << "2. Celsius ke Reamur" << endl;
    cout << "3. Celsius ke Kelvin" << endl;
    cout << "4. Fahrenheit ke Celsius" << endl;
    cout << "5. Reamur ke Celsius" << endl;
    cout << "6. Kelvin ke Celsius" << endl;

    // Meminta pengguna memasukkan pilihan
    cout << "Masukkan pilihan Anda (1-6) : ";
    cin >> pilih;

    // Melakukan konversi berdasarkan pilihan pengguna
    switch (pilih){
        case 1: // Konversi dari Celsius ke Fahrenheit
            cout << "Masukkan suhu dalam Celsius: ";
            cin >> temperature;
            cout << "Suhu dalam Fahrenheit: " << celsius_to_fahrenheit(temperature) << endl;
            break;
        case 2: // Konversi dari Celsius ke Reamur
            cout << "Masukkan suhu dalam Celsius: ";
            cin >> temperature;
            cout << "Suhu dalam Reamur: " << celsius_to_reamur(temperature) << endl;
            break;
        case 3: // Konversi dari Celsius ke Kelvin
            cout << "Masukkan suhu dalam Celsius: ";
            cin >> temperature;
            cout << "Suhu dalam Kelvin: " << celsius_to_kelvin(temperature) << endl;
            break;
        case 4: // Konversi dari Fahrenheit ke Celsius
            cout << "Masukkan suhu dalam Fahrenheit: ";
            cin >> temperature;
            cout << "Suhu dalam Celsius: " << fahrenheit_to_celsius(temperature) << endl;
            break;
        case 5: // Konversi dari Reamur ke Celsius
            cout << "Masukkan suhu dalam Reamur: ";
            cin >> temperature;
            cout << "Suhu dalam Celsius: " << reamur_to_celsius(temperature) << endl;
            break;
        case 6: // Konversi dari Kelvin ke Celsius
            cout << "Masukkan suhu dalam Kelvin: ";
            cin >> temperature;
            cout << "Suhu dalam Celsius: " << kelvin_to_celsius(temperature) << endl;
            break;
        default: // Menangani pilihan yang tidak valid
            cout << "Pilihan tidak valid." << endl;
        }
    return 0;
}

```

#### Output:

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/9a67894a-ba3b-40c1-8baa-fc1c1a505737)

Program dimulai dengan menampilkan menu pilihan konversi suhu kepada pengguna. Setiap pilihan disertai dengan nomor yang berkaitan dan jenis konversi yang dilakukan, seperti dari Celsius ke Fahrenheit, Celsius ke Reamur, dan sebagainya. Setelah menampilkan menu, pengguna diminta untuk memilih opsi dengan memasukkan angka yang sesuai. Setelah memasukkan pilihan, program menggunakan pernyataan switch-case untuk menentukan tindakan yang akan diambil berdasarkan pilihan pengguna.

Misalnya, jika pengguna memilih opsi 3 (Konversi dari Celsius ke Kelvin), program akan meminta pengguna untuk memasukkan suhu dalam Celsius. Setelah pengguna memasukkan suhu, program akan menggunakan fungsi `celsius_to_kelvin` untuk mengkonversi suhu tersebut ke dalam satuan Kelvin. Hasil konversi kemudian dicetak ke layar menggunakan pernyataan `cout`. Jika pengguna memasukkan suhu Celsius 26, program akan menghitung dan mencetak suhu tersebut dalam satuan Kelvin. Misalnya, jika hasil konversi adalah 299.15, maka hasilnya akan dicetak sebagai "Suhu dalam Kelvin: 299.15".

#### Kesimpulan materi tipe data primitif :

Kesimpulan dari materi di atas adalah bahwa tipe data primitif adalah fondasi penting dalam pemrograman. Memahami jenis-jenis dan penggunaannya dengan baik akan membantu dalam penulisan kode yang lebih efisien dan mudah dipahami. Contoh tipe data primitif meliputi int untuk menyimpan bilangan bulat, float untuk bilangan desimal, char untuk huruf atau simbol, dan boolean untuk menyimpan nilai boolean dengan dua kemungkinan nilai, yaitu true atau false.

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya

#### Class 

Class berfungsi untuk mendeskripsikan suatu objek melalui data dan fungsi yang dimiliki. Class memiliki akses default private sehingga tidak semua variabel dapat dieksekusi apabila ada objek yang private. Jika objek anggota dari class tersebut ingin dipublikasikan, maka harus menggunakan `public :`[4]. Class memiliki properti dan metode. Class akan mengelola data yang akan diakses melalui metode (method).

#### Struct

Fungsi struct yaitu dapat menggabungkan sekumpulan variabel dan memberi nama pada variabel-variabel tersebut. Nama yang digunakan sama seperti tipe variabelnya, misalnya : int atau string. Struct dapat mendeklarasikan variabel baru dan mengakses semua kolom. Struct akan mengelola data yang akan diakses secara langsung. Struct memiliki akses default yang terbuka (secara public). Struct hanya dapat memiliki properti. Struct mendefinisikan tipe data dan menginstruksikan kepada C++ untuk mengelompokkan koleksi tipe data dasar sebagai kesatuan tipe data sehingga dapat mendefinisikan variabel dan array variabel.

#### Perbedaan

Perbedaan utama antara class dan struct adalah pada hak akses defaultnya. Dalam class, anggota bersifat private secara default, sementara dalam struct bersifat public secara default. Dengan class, kita dapat menggunakan hak akses private untuk menyembunyikan implementasi internal dari pengguna class, sementara struct lebih terbuka dan digunakan terutama untuk menyimpan data tanpa perilaku yang kompleks.

#### Contoh Program

```C++
#include <iostream>
#include <string>
using namespace std;

// Struktur data untuk menampung informasi pegawai
struct Pegawai
{
    string nama;
    int umur;
    string email;
};

// Class biasa yang belum publik akses (default private)
class Pegawai1
{
    string nama;
    int umur;
    string email;
};

// Class yang sudah menjadi publik akses
class Pegawai2
{
public:
    string nama;
    int umur;
    string email;
};

int main()
{

    // Deklarasi variabel bertipe `Pegawai` dengan nama `pgw1`
    Pegawai pgw1;
    // Deklarasi variabel bertipe `Pegawai2` dengan nama `pgw2`
    Pegawai2 pgw2;

    // Mengisi nilai field pada variabel `pgw1`
    pgw1.nama = "kepin";
    pgw1.umur = 20;
    pgw1.email = "kepin8@gmail.com";

    // Menampilkan informasi pegawai `pgw1`
    cout << "===== Pegawai 1 ====="
         << "\nNama : " << pgw1.nama
         << "\nUmur : " << pgw1.umur << " tahun"
         << "\nEmail : " << pgw1.email << endl;

    // Mengisi nilai field pada variabel `pgw2`
    pgw2.nama = "sugeng";
    pgw2.umur = 50;
    pgw2.email = "sugeng98@gmail.com";

    // Menampilkan informasi pegawai `pgw2`
    cout << "===== Pegawai 2 ====="
         << "\nNama : " << pgw2.nama
         << "\nUmur : " << pgw2.umur << " tahun"
         << "\nEmail : " << pgw2.email << endl;

    return 0;
}
```

#### Output:

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/1c1cd967-5d63-401e-830a-dd9249097315)

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

### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map.

```C++
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){

    string kalimat;
    
    // Meminta pengguna untuk memasukkan sebuah kalimat
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);

    // Membuat map untuk menyimpan jumlah kemunculan setiap karakter
    map<char, int> hitungKarakter;

    // Menghitung kemunculan setiap karakter dalam kalimat
    for (char i : kalimat){
        // Mengabaikan spasi
        if (i != ' '){
            // Menambahkan karakter ke dalam map atau meningkatkan jumlah kemunculannya
            ++hitungKarakter[i];
        }
    }

    // Menampilkan hasil hitungan
    cout << "\nJumlah kemunculan karakter :\n";
    for (const auto& pair : hitungKarakter){
        cout << "'" << pair.first << "': " << pair.second << " kali" << endl;
    }
    return 0;
}
```

#### Output:

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/67e37e29-177e-4e07-856c-d25e844114e2)

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
