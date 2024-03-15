#include <iostream>
using namespace std;

int main()
{
    // Deklarasi variabel
    int n;
    // Meminta pengguna untuk memasukkan jumlah elemen array
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;
    // Deklarasi array dengan ukuran n
    int arr[n];

    // Input elemen array
    cout << "Masukkan " << n << " elemen array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Array ke - " << i + 1 << ": ";
        cin >> arr[i];
    }
    cout << endl;

    // Output data array
    cout << "Data Array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Menampilkan nomor genap
    cout << "Nomor genap : ";
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            cout << arr[i] << ", ";
        }
    }
    cout << endl;

    // Menampilkan nomor ganjil
    cout << "Nomor ganjil : ";
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 != 0)
        {
            cout << arr[i] << ", ";
        }
    }
}
