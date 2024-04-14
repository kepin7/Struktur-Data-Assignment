# <h1 align="center">Laporan Praktikum Modul Hash Table</h1>

<p align="center">Hizkia Kevin Octaviano - 2311102185</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

Hash Table merupakan salah satu struktur data yang digunakan dalam penyimpanan data sementara. Tujuan penggunaan hash table adalah mempercepat pencarian kembali dari banyak data yang disimpan. Hash table menggunakan suatu teknik penyimpanan sehingga waktu yang dibutuhkan untuk penambahan data (insertions), penghapusan data (deletions), dan pencarian data (searching) relatif sama dibanding struktur data atau algoritma yang lain[1].

Diketahui bahwa beberapa struktur data dan algoritma pencarian (searching) memiliki kelebihan serta kekurangan masing-masing. Begitu pula dengan hash tabel yang memiliki kelebihan
dan kekurangan[1]. Adapun kelebihan hash tabel antara lain:

- Relatif lebih cepat[1].
- Kecepatan dalam insertions, deletions, maupun searching
relatif sama[1].

Hash table menggunakan memori penyimpanan utama
berbentuk array dengan tambahan algoritma untuk mempercepat pemrosesan data. Pada intinya, tabel hash merupakan penyimpanan data menggunakan key value yang didapat
dari nilai data itu sendiri. Dengan key value tersebut, diperoleh
hash value. Jadi, hash function merupakan suatu fungsi
sederhana untuk mendapatkan hash value dari key value suatu
data[1]. Beberapa hal yang perlu diperhatikan untuk membuat
hash function adalah:

- Ukuran array/table size[1].
- Key value/nilai yang didapat dari data[1].
- Hash value/hash index/indeks yang dituju[1].

## Guided

### 1. Program Pertama Hash Table

```C++
#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

// Fungsi hash sederhana
int hash_func(int key)
{
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node
{
    int key;
    int value;
    Node *next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class hash table
class HashTable
{
private:
    Node **table;

public:
    HashTable()
    {
        table = new Node *[MAX_SIZE]();
    }
    ~HashTable()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insertion
    void insert(int key, int value)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node *node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }
    // Searching
    int get(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    // Deletion
    void remove(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        Node *prev = nullptr;
        while (current != nullptr)
        {
            if (current->key == key)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traversal
    void traverse()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                cout << current->key << ": " << current->value
                     << endl;
                current = current->next;
            }
        }
    }
};

int main()
{
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;

    // Deletion
    ht.remove(4);

    // Traversal
    ht.traverse();

    return 0;
}
```

Program ini menggunakan fungsi hash sederhana untuk menentukan indeks penyimpanan setiap elemen berdasarkan kunci yang diberikan. Setiap elemen disimpan dalam bentuk linked list di dalam array, di mana setiap elemen di linked list memiliki pasangan kunci-nilai dan pointer ke elemen berikutnya.

Kelas `HashTable` memiliki beberapa fungsi utama, termasuk `insert`, `get`, `remove`, dan `traverse`. Fungsi `insert` digunakan untuk menambahkan pasangan kunci-nilai ke dalam hash table. Fungsi `get` digunakan untuk mencari nilai yang terkait dengan kunci tertentu. Fungsi `remove` digunakan untuk menghapus pasangan kunci-nilai berdasarkan kunci yang diberikan. Dan fungsi `traverse` digunakan untuk mencetak semua pasangan kunci-nilai yang tersimpan dalam hash table.

Di dalam fungsi `main`, beberapa contoh operasi dilakukan untuk menguji fungsi-fungsi tersebut, seperti penambahan data, pencarian nilai berdasarkan kunci, penghapusan data, dan pencetakan seluruh isi hash table.

### 2. Program Kedua Hash Table

```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int TABLE_SIZE = 11;
string name;
string phone_number;

class HashNode
{
public:
    string name;
    string phone_number;
    HashNode(string name, string phone_number)
    {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap
{
private:
    vector<HashNode *> table[TABLE_SIZE];

public:
    int hashFunc(string key)
    {
        int hash_val = 0;
        for (char c : key)
        {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string name, string phone_number)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name)
    {
        int hash_val = hashFunc(name);
        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++)
        {
            if ((*it)->name == name)
            {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    string searchByName(string name)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                return node->phone_number;
            }
        }
        return "";
    }

    void print()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << ": ";
            for (auto pair : table[i])
            {
                if (pair != nullptr)
                {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    HashMap employee_map;

    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    cout << "Nomer Hp Mistah : "
         << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : "
         << employee_map.searchByName("Pastah") << endl;

    employee_map.remove("Mistah");

    cout << "Nomer Hp Mistah setelah dihapus : "
         << employee_map.searchByName("Mistah") << endl
         << endl;

    cout << "Hash Table : " << endl;

    employee_map.print();

    return 0;
}
```

Program ini menggunakan hash table untuk menyimpan data nama dan nomor telepon karyawan.

Kelas `HashNode` digunakan untuk merepresentasikan node dalam hash table yang berisi pasangan nama dan nomor telepon. Kelas `HashMap` mengelola hash table itu sendiri dan menyediakan operasi-operasi seperti penyisipan (`insert`), pencarian berdasarkan nama (`searchByName`), dan penghapusan (`remove`). Implementasi ini menggunakan teknik chaining, di mana setiap slot dalam tabel hash memiliki linked list dari node-node yang mungkin memiliki nilai hash yang sama.

Fungsi hash yang digunakan adalah fungsi sederhana yang menghitung jumlah karakter dalam kunci (nama) dan kemudian melakukan modulo dengan ukuran tabel hash untuk menentukan indeks penyimpanan. Operasi pencarian dan penghapusan dilakukan dengan mencari node dalam linked list yang sesuai dengan kunci yang diberikan.

Di dalam `main`, beberapa contoh operasi dilakukan untuk menguji fungsi-fungsi tersebut, seperti penambahan data, pencarian berdasarkan nama, penghapusan data, dan pencetakan seluruh isi hash table.

## Unguided

### 1. Soal mengenai Hash Table
Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa
memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru,
menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan
nilai. Dengan ketentuan :

a. Setiap mahasiswa memiliki NIM dan nilai.

b. Program memiliki tampilan pilihan menu berisi poin C.

c. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).

```C++
#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 10;

// struktur data untuk setiap node
struct mahasiswa
{
    string nama;
    long long NIM;
    int nilai;
    mahasiswa *next; // pointer untuk menunjukkan node selanjutnya dalam collision handling

    mahasiswa(string nama, long long NIM, int nilai) : nama(nama), NIM(NIM), nilai(nilai), next(nullptr) {}
};

// class hash table
class HashTable
{
private:
    mahasiswa **table; // array pointer untuk menunjukkan ke elemen-elemen tabel hash

    // fungsi hash sederhana
    int hash_func(long long key)
    {
        return key % MAX_SIZE; // menggunakan modulus untuk mendapatkan indeks
    }

public:
    // constructor
    HashTable()
    {
        table = new mahasiswa *[MAX_SIZE](); // inisialisasi array pointer dengan nullptr
    }

    // destructor
    ~HashTable()
    {
        // menghapus semua node dan array pointer
        for (int i = 0; i < MAX_SIZE; ++i)
        {
            mahasiswa *current = table[i];
            while (current != nullptr)
            {
                mahasiswa *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // insertion
    void insert(string nama, long long NIM, int nilai)
    {
        int index = hash_func(NIM);                                 // mendapatkan indeks berdasarkan NIM
        mahasiswa *new_mahasiswa = new mahasiswa(nama, NIM, nilai); // membuat node baru
        new_mahasiswa->next = table[index];                         // menambahkan node baru ke depan daftar di indeks yang tepat
        table[index] = new_mahasiswa;
    }

    // deletion
    void remove(long long NIM)
    {
        int index = hash_func(NIM);        // mendapatkan indeks berdasarkan NIM
        mahasiswa *current = table[index]; // mengambil node pertama di indeks yang tepat
        mahasiswa *prev = nullptr;         // pointer untuk node sebelumnya
        while (current != nullptr)
        {
            if (current->NIM == NIM)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next; // jika node yang dihapus adalah node pertama di indeks, atur node berikutnya sebagai node pertama
                }
                else
                {
                    prev->next = current->next; // jika bukan, hubungkan node sebelumnya dengan node setelahnya
                }
                delete current; // hapus node yang ditemukan
                cout << "Mahasiswa dengan NIM " << NIM << " telah dihapus." << endl;
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "Mahasiswa dengan NIM " << NIM << " tidak ditemukan." << endl;
    }

    // searching by NIM
    mahasiswa *cari_NIM(long long NIM)
    {
        long long index = hash_func(NIM);  // mendapatkan indeks berdasarkan NIM
        mahasiswa *current = table[index]; // mengambil node pertama di indeks yang tepat
        while (current != nullptr)
        {
            if (current->NIM == NIM)
            {
                return current; // kembalikan node jika NIM cocok
            }
            current = current->next;
        }
        return nullptr; // kembalikan nullptr jika tidak ditemukan
    }

    // searching by rentang nilai
    void cari_nilai(int awal, int akhir)
    {
        // mencetak header tabel
        cout << "-----------------------------------------------------------" << endl;
        cout << "|       Nama         |       NIM        |      Nilai      |" << endl;
        cout << "-----------------------------------------------------------" << endl;
        // traverse semua bucket pada tabel hash
        for (int i = 0; i < MAX_SIZE; ++i)
        {
            mahasiswa *current = table[i]; // mengambil node pertama di indeks yang tepat
            // traverse semua node dalam bucket
            while (current != nullptr)
            {
                // jika nilai berada dalam rentang yang ditentukan, cetak informasi mahasiswa
                if (current->nilai >= awal && current->nilai <= akhir)
                {
                    cout << "| " << setw(19) << left << current->nama
                         << "| " << setw(17) << current->NIM
                         << "| " << setw(15) << current->nilai << " |" << endl;
                }
                current = current->next;
            }
        }
        cout << "-----------------------------------------------------------" << endl;
    }

    // traversal
    void traverse()
    {
        // mencetak header tabel
        cout << "-----------------------------------------------------------" << endl;
        cout << "|       Nama         |       NIM        |      Nilai      |" << endl;
        cout << "-----------------------------------------------------------" << endl;
        // traverse semua bucket pada tabel hash
        for (int i = 0; i < MAX_SIZE; ++i)
        {
            mahasiswa *current = table[i]; // mengambil node pertama di indeks yang tepat
            // traverse semua node dalam bucket
            while (current != nullptr)
            {
                // cetak informasi mahasiswa
                cout << "| " << setw(19) << left << current->nama
                     << "| " << setw(17) << current->NIM
                     << "| " << setw(15) << current->nilai << " |" << endl;
                current = current->next;
            }
        }
        cout << "-----------------------------------------------------------" << endl;
    }
};

int main()
{
    HashTable ht;

    int pilih, nilai, awal, akhir;
    string nama;
    long long NIM;

    do
    {
        // menu utama
        cout << "\nMenu:" << endl;
        cout << "1. Tambah Data Mahasiswa" << endl;
        cout << "2. Hapus Data Mahasiswa" << endl;
        cout << "3. Cari berdasarkan NIM" << endl;
        cout << "4. Cari berdasarkan Rentang Nilai" << endl;
        cout << "5. Tampilkan Semua Data" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih menu : ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            // tambah data mahasiswa
            cout << "Masukan nama : ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukan NIM : ";
            cin >> NIM;
            cout << "Masukan nilai : ";
            cin >> nilai;
            ht.insert(nama, NIM, nilai);
            cout<<"Data berhasil ditambahkan"<<endl;
            break;
        case 2:
            // hapus data mahasiswa berdasarkan NIM
            cout << "Masukan NIM yang ingin dihapus : ";
            cin >> NIM;
            ht.remove(NIM);
            break;
        case 3:
            // cari mahasiswa berdasarkan NIM
            cout << "Masukan NIM yang ingin dicari : ";
            cin >> NIM;
            {
                mahasiswa *mahasiswa_ptr = ht.cari_NIM(NIM);
                if (mahasiswa_ptr)
                {
                    cout << "Ditemukan mahasiswa dengan NIM " << NIM << " bernama " << mahasiswa_ptr->nama << " dan memiliki nilai " << mahasiswa_ptr->nilai << endl;
                }
                else
                {
                    cout << "mahasiswa dengan NIM " << NIM << " tidak ditemukan" << endl;
                }
            }
            break;
        case 4:
            // cari mahasiswa berdasarkan rentang nilai
            cout << "masukan nilai awal : ";
            cin >> awal;
            cout << "maukan nilai akhir : ";
            cin >> akhir;
            ht.cari_nilai(awal, akhir);
            break;
        case 5:
            // tampilkan semua data mahasiswa
            ht.traverse();
            break;
        case 6:
            cout << "Thankyou code By Kepin." << endl; // keluar dari program
            break;
        default:
            cout << "Pilihan invalid!" << endl; // jika pilihan tidak valid
        }
    } while (pilih != 6); // ulangi sampai pengguna memilih untuk keluar

    return 0;
}

```

#### Output menu 1:

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/13b227b4-9582-4a46-b62a-2157176512bb)

#### Output menu 2:

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/0644e67b-aa7d-48cd-90ac-600ef5dac077)

#### Output menu 3:

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/301ebe3b-d37e-49ea-8652-61a559f89383)

#### Output menu 4:

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/e3db90c6-ee25-416e-bea0-0fe484159358)

#### Output menu 5:

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/43adccec-0767-4eea-94b9-46c2f18f1e98)

#### Output menu 6:

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/307eef7f-4ab9-41e1-8c60-e4690a15b348)

Program hash table yang diberikan adalah untuk menyimpan dan mengelola data mahasiswa. Hash table digunakan untuk memetakan NIM mahasiswa ke informasi lainnya seperti nama dan nilai. 

Setiap mahasiswa direpresentasikan oleh sebuah struktur data (`mahasiswa`) yang memiliki tiga atribut: nama, NIM, dan nilai. Selain itu, terdapat sebuah kelas `HashTable` yang bertanggung jawab untuk mengelola tabel hash. Tabel hash ini diimplementasikan sebagai array dari pointer ke elemen-elemen `mahasiswa`. Penanganan collision dilakukan dengan menggunakan linked list di setiap slot tabel hash.
Program menyediakan beberapa operasi, seperti:

1. `insert`: Menambahkan data mahasiswa baru ke hash table.
2. `remove`: Menghapus data mahasiswa berdasarkan NIM.
3. `cari_NIM`: Mencari mahasiswa berdasarkan NIM.
4. `cari_nilai`: Mencari mahasiswa berdasarkan rentang nilai.
5. `traverse`: Menampilkan semua data mahasiswa yang tersimpan dalam hash table.

Di dalam fungsi `main`, terdapat sebuah loop menu yang memberikan pilihan kepada pengguna untuk melakukan operasi seperti menambah, menghapus, mencari, dan menampilkan data mahasiswa. Pengguna dapat memilih menu hingga memilih untuk keluar dari program.

## Kesimpulan

Hash table adalah struktur data yang efisien digunakan untuk memetakan kunci ke nilai-nilai tertentu. Dengan menggunakan fungsi hash, kunci-kunci tersebut diubah menjadi indeks yang menunjukkan lokasi penyimpanan dalam tabel hash. Hal ini memungkinkan akses cepat dan efisien terhadap data, dengan waktu akses rata-rata yang konstan (O(1)). Selain itu, teknik penanganan collision seperti chaining memungkinkan penanganan konflik yang terjadi saat dua kunci menghasilkan indeks yang sama. Dengan demikian, hash table sangat berguna dalam pengelolaan data di berbagai aplikasi, seperti basis data, pencarian, dan penyimpanan asosiatif.

## Referensi

[1] Mulyana, A., et al., Cara Mudah Mempelajari Algoritma dan Struktur Data. Edisi Pertama. Yogyakarta : DIVA Press, 2021

[2] "geeksforgeeks", [Online]. Available: https://www.geeksforgeeks.org/. [Accessed: April 14, 2024].
