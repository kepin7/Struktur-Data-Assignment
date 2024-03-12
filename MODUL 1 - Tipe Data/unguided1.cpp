#include <iostream>
using namespace std;

// Fungsi untuk mengkonversi suhu dari Celsius ke Fahrenheit
float celsius_to_fahrenheit(float celsius){
    return (celsius * 9 / 5) + 32;
}
// Fungsi untuk mengkonversi suhu dari Celsius ke Reamur
float celsius_to_reamur(float celsius){
    return celsius * 4 / 5;
}

// Fungsi untuk mengkonversi suhu dari Celsius ke Kelvin
float celsius_to_kelvin(float celsius){
    return celsius + 273.15;
}

// Fungsi untuk mengkonversi suhu dari Fahrenheit ke Celsius
float fahrenheit_to_celsius(float fahrenheit){
    return (fahrenheit - 32) * 5 / 9;
}

// Fungsi untuk mengkonversi suhu dari Reamur ke Celsius
float reamur_to_celsius(float reamur){
    return reamur * 5 / 4;
}

// Fungsi untuk mengkonversi suhu dari Kelvin ke Celsius
float kelvin_to_celsius(float kelvin){
    return kelvin - 273.15;
}

int main(){

    // Deklarasi variabel yang digunakan untuk memproses menu pilihan user
    int pilih;
    // Deklarasi variabel yang digunakan untuk menampung data input dari user
    float temperature;

    // Menampilkan menu pilihan konversi
    cout << "Program Konversi Suhu" << endl;
    cout << "======================" << endl;
    cout << "Pilih jenis konversi:" << endl;
    cout << "1. Celsius ke Fahrenheit" << endl;
    cout << "2. Celsius ke Reamur" << endl;
    cout << "3. Celsius ke Kelvin" << endl;
    cout << "4. Fahrenheit ke Celsius" << endl;
    cout << "5. Reamur ke Celsius" << endl;
    cout << "6. Kelvin ke Celsius" << endl;

    // Meminta pengguna memasukkan pilihan
    cout << "Masukkan pilihan Anda (1-6) : ";
    cin >> pilih;

    // Melakukan konversi berdasarkan pilihan pengguna
    switch (pilih){
        case 1: // Konversi dari Celsius ke Fahrenheit
            cout << "Masukkan suhu dalam Celsius: ";
            cin >> temperature;
            cout << "Suhu dalam Fahrenheit: " << celsius_to_fahrenheit(temperature) << endl;
            break;
        case 2: // Konversi dari Celsius ke Reamur
            cout << "Masukkan suhu dalam Celsius: ";
            cin >> temperature;
            cout << "Suhu dalam Reamur: " << celsius_to_reamur(temperature) << endl;
            break;
        case 3: // Konversi dari Celsius ke Kelvin
            cout << "Masukkan suhu dalam Celsius: ";
            cin >> temperature;
            cout << "Suhu dalam Kelvin: " << celsius_to_kelvin(temperature) << endl;
            break;
        case 4: // Konversi dari Fahrenheit ke Celsius
            cout << "Masukkan suhu dalam Fahrenheit: ";
            cin >> temperature;
            cout << "Suhu dalam Celsius: " << fahrenheit_to_celsius(temperature) << endl;
            break;
        case 5: // Konversi dari Reamur ke Celsius
            cout << "Masukkan suhu dalam Reamur: ";
            cin >> temperature;
            cout << "Suhu dalam Celsius: " << reamur_to_celsius(temperature) << endl;
            break;
        case 6: // Konversi dari Kelvin ke Celsius
            cout << "Masukkan suhu dalam Kelvin: ";
            cin >> temperature;
            cout << "Suhu dalam Celsius: " << kelvin_to_celsius(temperature) << endl;
            break;
        default: // Menangani pilihan yang tidak valid
            cout << "Pilihan tidak valid." << endl;
        }
    return 0;
}
