#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Fungsi untuk mengurutkan string menggunakan algoritma Selection Sort
void selectionSort(string &str)
{
    int a = str.length(); // Mendapatkan panjang string
    // Melakukan iterasi sepanjang string
    for (int i = 0; i < a - 1; i++)
    {
        int min = i; // Menganggap elemen pertama sebagai elemen terkecil
        // Mencari elemen terkecil di antara elemen yang belum diurutkan
        for (int j = i + 1; j < a; j++)
        {
            if (str[j] < str[min])
            {
                min = j; // Menyimpan indeks elemen terkecil yang ditemukan
            }
        }
        // Menukar elemen terkecil dengan elemen pertama yang belum diurutkan
        if (min != i)
        {
            swap(str[i], str[min]);
        }
    }
}

// Fungsi untuk melakukan pencarian biner dalam string
void binarySearch(const string &str, char target)
{
    int awal = 0, akhir = str.length() - 1; // Inisialisasi indeks awal dan akhir
    bool found = false;                     // Flag untuk menandai apakah huruf ditemukan
    while (awal <= akhir)
    {
        int tengah = awal + (akhir - awal) / 2; // Menghitung indeks tengah
        if (str[tengah] == target)              // Jika huruf ditemukan
        {
            found = true;
            cout << "Huruf '" << target << "' ditemukan pada index : ";
            // Mencari semua kemunculan huruf target
            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] == target)
                {
                    cout << i << ", ";
                }
            }
            break; // Keluar dari loop setelah semua kemunculan ditemukan
        }
        else if (str[tengah] < target) // Jika huruf di tengah kurang dari target
        {
            awal = tengah + 1; // Mencari di setengah kanan array
        }
        else // Jika huruf di tengah lebih dari target
        {
            akhir = tengah - 1; // Mencari di setengah kiri array
        }
    }
    if (!found) // Jika huruf tidak ditemukan dalam string
    {
        cout << "Huruf '" << target << "' tidak ditemukan." << endl;
    }
}

int main()
{
    string kalimat;   // Variabel untuk menyimpan kalimat yang dimasukkan pengguna
    char hurufTarget; // Variabel untuk menyimpan huruf target yang dimasukkan pengguna

    cout << "=========== Program pencarian huruf =========== " << endl;
    cout << "Masukkan kalimat : "; // Meminta pengguna untuk memasukkan kalimat
    getline(cin, kalimat);         // Membaca input kalimat dari pengguna

    cout << "Masukkan huruf yang ingin di cari : "; // Meminta pengguna untuk memasukkan huruf target
    cin >> hurufTarget;

    selectionSort(kalimat); // Mengurutkan seluruh karakter dalam kalimat
    cout << endl;

    cout << "===================== Hasil ===================" << endl;
    
    cout << "Kata yang sudah diurutkan : "; // Menampilkan kalimat yang sudah di urutkan
    for (int i = 0; i < kalimat.length(); i++)
    {
        cout << setw(3) << kalimat[i];
    }
    cout << endl;

    binarySearch(kalimat, hurufTarget); // Mencari kemunculan huruf target dalam kalimat

    return 0;
}
