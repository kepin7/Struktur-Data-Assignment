#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){

    string kalimat;
    
    // Meminta pengguna untuk memasukkan sebuah kalimat
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);

    // Membuat map untuk menyimpan jumlah kemunculan setiap karakter
    map<char, int> hitungKarakter;

    // Menghitung kemunculan setiap karakter dalam kalimat
    for (char i : kalimat){
        // Mengabaikan spasi
        if (i != ' '){
            // Menambahkan karakter ke dalam map atau meningkatkan jumlah kemunculannya
            ++hitungKarakter[i];
        }
    }

    // Menampilkan hasil hitungan
    cout << "\nJumlah kemunculan karakter :\n";
    for (const auto& pair : hitungKarakter){
        cout << "'" << pair.first << "': " << pair.second << " kali" << endl;
    }
    return 0;
}