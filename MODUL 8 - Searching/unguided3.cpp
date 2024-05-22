#include <iostream>
using namespace std;

int main()
{
    int n = 10;                                     // Jumlah elemen dalam array data
    int data[n] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}; // Array data dengan nilai-nilai yang akan dicari
    int cari = 4;                                   // Angka yang akan dicari dalam array data
    int index[n];                                   // Array untuk menyimpan indeks di mana angka ditemukan
    int count = 0;                                  // Untuk menghitung kemunculan angka
    bool ketemu = false;                            // Variabel untuk menandai apakah angka ditemukan atau tidak

    // Algoritma Sequential
    for (int i = 0; i < n; i++)
    {
        if (data[i] == cari) // Memeriksa apakah elemen saat ini sama dengan angka yang dicari
        {
            ketemu = true;    // Menandai bahwa angka ditemukan
            index[count] = i; // Menyimpan indeks di mana angka ditemukan
            count++;          // Menambah hitungan kemunculan angka
        }
    }

    // Menampilkan informasi tentang pencarian
    cout << "Program Sequential Search Sederhana\n" << endl;

    // Menampilkan data awal
    cout << "DATA = [ ";
    for (int i = 0; i < n; i++)
    {
        cout << data[i] << ", ";
    }
    cout << "]" << endl;

    // Menampilkan hasil pencarian
    if (ketemu) // Jika angka ditemukan
    {
        cout << "\nAngka " << cari << " muncul " << count << " kali dalam data." << endl;

        if (count > 0) // Jika angka muncul setidaknya satu kali
        {
            cout << "Angka " << cari << " ditemukan pada index : ";
            for (int i = 0; i < count; i++)
            {
                cout << index[i]; // Menampilkan indeks di mana angka ditemukan
                if (i != count - 1)
                {
                    cout << ", ";
                }
            }
            cout << endl;
        }
    }
    else // Jika angka tidak ditemukan
    {
        cout << "Angka " << cari << " tidak dapat ditemukan pada data." << endl;
    }

    return 0;
}