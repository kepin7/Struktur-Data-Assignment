#include <iostream>
#include <string>

using namespace std;

// Mendefinisikan array dan variabel top dan maksimal
string arrayData[25];       // Array untuk menyimpan data
int maksimal = 25, top = 0; // maksimal adalah ukuran maksimum array, top adalah indeks teratas dari array

// Fungsi untuk memeriksa apakah array penuh
bool isFull()
{
    return (top == maksimal); // Mengembalikan true jika top sama dengan maksimal
}

// Fungsi untuk memeriksa apakah array kosong
bool isEmpty()
{
    return (top == 0); // Mengembalikan true jika top adalah 0, artinya tidak ada data
}

// Fungsi untuk menambahkan data ke dalam array
void pushArrayData(string kalimat)
{
    if (isFull())
    { // Memeriksa apakah array penuh
        cout << "Data telah penuh" << endl;
    }
    else
    {
        arrayData[top] = kalimat; // Menambahkan data ke dalam array di posisi top
        top++;                    // Menaikkan nilai top
    }
}

// Fungsi untuk menghapus data dari array
void popArrayData()
{
    if (isEmpty())
    { // Memeriksa apakah array kosong
        cout << "Tidak ada data yang dihapus" << endl;
    }
    else
    {
        arrayData[top - 1] = ""; // Menghapus data dengan mengosongkan nilai pada posisi top-1
        top--;                   // Menurunkan nilai top
    }
}

// Fungsi untuk membalikkan kalimat
void reverseKalimat(string kalimat)
{
    for (char &c : kalimat)
    {
        pushArrayData(string(1, c)); // Memasukkan setiap karakter ke dalam stack
    }

    string reversedString = "";
    while (!isEmpty())
    {
        reversedString += arrayData[top - 1]; // Mengambil karakter dari stack untuk membentuk kalimat terbalik
        popArrayData();
    }

    cout << "Hasil\t: " << reversedString << endl; // Menampilkan kalimat terbalik
}

// Fungsi utama
int main()
{
    string kalimat;
    cout << "Masukkan kalimat : ";
    getline(cin, kalimat); // Meminta input kalimat dari pengguna

    cout << "Kalimat\t: " << kalimat << endl; // Menampilkan kalimat awal
    reverseKalimat(kalimat);                  // Memanggil fungsi untuk membalikkan kalimat

    return 0;
}