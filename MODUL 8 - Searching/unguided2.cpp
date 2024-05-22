#include <iostream> 
#include <string>   

using namespace std; 

// Fungsi untuk mengecek apakah sebuah karakter adalah huruf vokal
bool cek_huruf(char v)
{
    // Konversi karakter ke huruf kecil
    v = tolower(v);

    // Mengecek apakah karakter adalah salah satu huruf vokal
    return v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u';
}

int main()
{
    // Deklarasi variabel
    string kalimat;  // Variabel untuk menyimpan kalimat yang diinput oleh pengguna
    int jumlahvokal = 0; // Variabel untuk menyimpan jumlah huruf vokal
    int index = 0;   // Variabel untuk menyimpan posisi huruf dalam kalimat (tanpa spasi)

    // Mengambil input kalimat dari pengguna
    cout << "============ Program mencari huruf vokal ============" << endl;
    cout << "Masukkan kalimat : ";
    getline(cin, kalimat); // Mengambil input kalimat lengkap dari pengguna

    // Menghitung jumlah vokal
    for (char huruf : kalimat) // Loop untuk setiap karakter dalam kalimat
    {
        if (cek_huruf(huruf)) // Memeriksa apakah karakter tersebut adalah vokal
        {
            jumlahvokal++; // Jika ya, tambahkan ke jumlah vokal
        }
    }
    cout << endl;

    cout << "====================== Hasil ========================" << endl;
    // Menampilkan hasil
    cout << "Jumlah huruf vokal : " << jumlahvokal << endl;

    // Menghitung dan menampilkan indeks huruf vokal
    cout << "Huruf vokal terdapat pada index : ";
    for (int i = 0; i < kalimat.length(); i++) // Loop untuk setiap karakter dalam kalimat
    {
        if (kalimat[i] != ' ') 
        {
            index++; 
            if (cek_huruf(kalimat[i])) // Memeriksa apakah karakter adalah vokal
            {
                cout << index << ", "; // Jika ya, cetak indeks posisi karakter tersebut
            }
        }
    }

    return 0; 
}