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