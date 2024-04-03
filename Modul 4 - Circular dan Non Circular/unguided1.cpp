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
            int posisiHapus;
            cout << "Masukkan Posisi: ";
            cin >> posisiHapus;
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
