#include <iostream>
using namespace std;

// Array untuk menyimpan karakter dari kalimat
string arrayData[25];
// Maksimum elemen dalam array
int maksimal = 25;
// Indeks untuk menunjukkan elemen teratas dalam stack
int top = 0;

// Fungsi untuk mengecek apakah stack sudah penuh
bool isFull()
{
    return (top == maksimal);
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty()
{
    return (top == 0);
}

// Fungsi untuk menambahkan karakter ke dalam arrayData (mengisi stack)
void pushArrayData(string kalimat)
{
    // Jika stack sudah penuh, cetak pesan
    if (isFull())
    {
        cout << "Data telah penuh" << endl;
    }
    else
    {
        // Masukkan karakter ke dalam arrayData pada indeks top, lalu naikkan top
        arrayData[top] = kalimat;
        top++;
    }
}

// Fungsi untuk menghapus karakter dari arrayData (mengosongkan stack)
void popArrayData()
{
    // Jika stack kosong, cetak pesan
    if (isEmpty())
    {
        cout << "Tidak ada data yang dihapus" << endl;
    }
    else
    {
        // Kosongkan karakter pada arrayData pada indeks top - 1, lalu turunkan top
        arrayData[top - 1] = "";
        top--;
    }
}

// Fungsi untuk mengecek apakah kalimat adalah palindrom
bool isPalindrom(string kalimat)
{
    int length = kalimat.length();
    // Memasukkan setengah karakter pertama dari kalimat ke dalam stack
    for (int i = 0; i < length / 2; i++)
    {
        pushArrayData(string(1, kalimat[i])); // Masukkan karakter ke stack
    }
    // Membandingkan setengah karakter kedua dengan isi stack
    for (int i = (length + 1) / 2; i < length; i++)
    {
        // Jika karakter dari kalimat tidak sama dengan karakter pada stack,
        // berarti bukan palindrom, kembalikan false
        if (kalimat[i] != arrayData[top - 1][0])
        {
            return false;
        }
        popArrayData(); // Hapus karakter pada stack
    }
    // Jika semua karakter cocok, kembalikan true (kalimat adalah palindrom)
    return true;
}

int main()
{
    string kalimat;
    cout << "Masukkan kalimat : ";
    getline(cin, kalimat); // Meminta input kalimat dari pengguna

    // Memeriksa apakah kalimat adalah palindrom
    if (isPalindrom(kalimat))
    {
        cout << "Kalimat tersebut adalah palindrom" << endl;
    }
    else
    {
        cout << "Kalimat tersebut bukan palindrom" << endl;
    }

    return 0;
}
