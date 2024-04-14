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
