#include <iostream>
#include <string>
using namespace std;

// Deklarasi Struct Node
struct Node
{
    string nama;
    int usia;
    Node *next;
};

Node *head = NULL; // Pointer yang menunjuk ke node pertama (head) dari linked list
Node *tail = NULL; // Pointer yang menunjuk ke node terakhir (tail) dari linked list

// Fungsi untuk menambah node baru di depan
void insertDepan(string nama, int usia)
{
    Node *baru = new Node; // Membuat node baru
    baru->nama = nama;     // Mengisi data nama pada node baru
    baru->usia = usia;     // Mengisi data usia pada node baru

    // Menambahkan node baru di depan head
    baru->next = head; // Node baru menunjuk ke node yang ditunjuk oleh head
    head = baru;       // Head menunjuk ke node baru

    // Jika linked list sebelumnya kosong, tail juga perlu diubah
    if (tail == NULL)
    {
        tail = baru;
    }
}

// Fungsi untuk menambah node baru di belakang
void insertBelakang(string nama, int usia)
{
    Node *baru = new Node; // Membuat node baru
    baru->nama = nama;     // Mengisi data nama pada node baru
    baru->usia = usia;     // Mengisi data usia pada node baru
    baru->next = NULL;     // Mengatur pointer next node baru menjadi NULL

    if (head == NULL) // Jika linked list kosong
    {
        head = baru; // Head menunjuk ke node baru
        tail = baru; // Tail juga menunjuk ke node baru karena hanya ada satu node dalam linked list
    }
    else // Jika linked list tidak kosong
    {
        tail->next = baru; // Menambahkan node baru setelah tail
        tail = baru;       // Mengubah tail untuk menunjuk ke node baru yang merupakan node terakhir
    }
}

// Fungsi untuk menambah node baru di tengah
void insertTengah(string nama, int usia, string namaSebelumnya)
{
    Node *baru = new Node; // Membuat node baru
    baru->nama = nama;     // Mengisi data nama pada node baru
    baru->usia = usia;     // Mengisi data usia pada node baru

    Node *bantu = head;
    while (bantu != NULL && bantu->nama != namaSebelumnya) // Mencari node dengan namaSebelumnya
    {
        bantu = bantu->next;
    }

    if (bantu == NULL) // Jika node dengan namaSebelumnya tidak ditemukan
    {
        cout << "Data tidak ditemukan" << endl;
        return;
    }

    baru->next = bantu->next; // Mengatur pointer next node baru
    bantu->next = baru;       // Menambahkan node baru setelah node dengan namaSebelumnya
}

// Fungsi untuk menampilkan semua data
void tampil()
{
    Node *bantu = head;
    if (bantu == NULL) // Jika linked list kosong
    {
        cout << "List kosong!" << endl;
        return;
    }

    while (bantu != NULL) // Menampilkan data setiap node dalam linked list
    {
        cout << bantu->nama << "\t" << bantu->usia << endl;
        bantu = bantu->next;
    }
}

// Fungsi untuk menghapus node dengan nama tertentu
void hapus(string nama)
{
    Node *hapus = head;
    Node *sebelum = NULL;

    while (hapus != NULL && hapus->nama != nama) // Mencari node dengan nama yang akan dihapus
    {
        sebelum = hapus;
        hapus = hapus->next;
    }

    if (hapus == NULL) // Jika node dengan nama yang akan dihapus tidak ditemukan
    {
        cout << "Data tidak ditemukan" << endl;
        return;
    }

    if (sebelum == NULL) // Jika node yang akan dihapus adalah head
    {
        head = hapus->next; // Mengubah head menjadi node setelah node yang dihapus
    }
    else
    {
        sebelum->next = hapus->next; // Mengubah pointer next node sebelumnya untuk menghapus node yang dituju
    }

    delete hapus; // Menghapus node yang dihapus dari memory
}

// Fungsi untuk mengubah data mahasiswa dengan nama tertentu
void ubahData(string nama, string namaBaru, int usiaBaru)
{
    Node *ubah = head;

    while (ubah != NULL && ubah->nama != nama) // Mencari node dengan nama yang akan diubah
    {
        ubah = ubah->next;
    }

    if (ubah == NULL) // Jika node dengan nama yang akan diubah tidak ditemukan
    {
        cout << "Data tidak ditemukan" << endl;
        return;
    }

    ubah->nama = namaBaru; // Mengubah data nama pada node yang ditemukan
    ubah->usia = usiaBaru; // Mengubah data usia pada node yang ditemukan
}

int main()
{
    // Menambahkan data
    insertBelakang("John", 19);
    insertBelakang("Jane", 20);
    insertBelakang("Michael", 18);
    insertBelakang("Yusuke", 19);
    insertBelakang("Akechi", 20);
    insertBelakang("Hoshino", 18);
    insertBelakang("Karin", 18);

    char menu;
    string nama, namaBaru;
    int usia, usiaBaru;

    // Menampilkan menu
    do
    {
        cout << "\nMenu:\n";
        cout << "a. Masukkan data\n";
        cout << "b. Hapus data Akechi\n";
        cout << "c. Tambahkan data di antara John dan Jane\n";
        cout << "d. Tambahkan data di awal\n";
        cout << "e. Ubah data Michael\n";
        cout << "f. Tampilkan seluruh data\n";
        cout << "g. Keluar\n";
        cout << "Pilih menu: ";
        cin >> menu;

        switch (menu)
        {
            // Input nama dan usia saya
        case 'a':
            cout << "Masukkan nama dan usia: ";
            cin >> nama >> usia;
            insertDepan(nama, usia);
            cout << "Data berhasil di tambahkan" << endl;
            break;
            // Hapus data akechi
        case 'b':
            hapus("Akechi");
            cout << "Data Akechi telah di hapus" << endl;
            break;
            // Tambahkan data berikut diantara John dan Jane : Futaba 18
        case 'c':
            cout << "Masukkan nama dan usia: ";
            cin >> nama >> usia;
            insertTengah("Futaba", 18, "John");
            cout << "Data futaba telah di tambahkan" << endl;
            break;
            // Tambahkan data berikut diawal : Igor 20
        case 'd':
            cout << "Masukkan nama dan usia: ";
            cin >> nama >> usia;
            insertDepan(nama, usia);
            cout << "Data telah di tambahkan" << endl;
            break;
            // Ubah data Michael menjadi : Reyn 18
        case 'e':
            cout << "Masukkan nama baru, usia baru: ";
            cin >> namaBaru >> usiaBaru;
            ubahData("Michael", namaBaru, usiaBaru);
            cout << "Data berhasil diubah" << endl;
            break;
            // Menampilkan data
        case 'f':
            tampil();
            break;
            // Keluar program
        case 'g':
            cout << "Keluar dari program." << endl;
            break;
            // Jika menu tidak valid
        default:
            cout << "Menu tidak valid!" << endl;
        }
    } while (menu != 'g');

    return 0;
}
