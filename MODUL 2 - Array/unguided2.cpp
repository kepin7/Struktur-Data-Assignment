#include <iostream>
using namespace std;

int main()
{
    // Deklarasi variabel untuk menyimpan jumlah baris, kolom, dan kedalaman
    int x, y, z;
    // Meminta pengguna untuk memasukkan jumlah baris, kolom, dan kedalaman
    cout << "Masukkan jumlah baris: ";
    cin >> x;
    cout << "Masukkan jumlah kolom: ";
    cin >> y;
    cout << "Masukkan jumlah kedalaman: ";
    cin >> z;

    cout << endl;
    // Deklarasi array tiga dimensi dengan ukuran sesuai input pengguna
    int arr[x][y][z];

    // Perulangan untuk input elemen array
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                // Meminta pengguna untuk memasukkan nilai untuk setiap elemen array
                cout << "Input Array[" << i << "][" << j << "][" << k << "] = ";
                cin >> arr[i][j][k];
            }
        }
        cout << endl;
    }

    // Perulangan untuk output Array
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                // Cetak elemen data array
                cout << "Data Array[" << i << "][" << j << "][" << k << "] = " << arr[i][j][k] << endl;
            }
        }
    }
    cout << endl;

    // Perulangan untuk tampilan array
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                // Cetak elemen array
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}