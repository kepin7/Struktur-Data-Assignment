#include <iostream>

using namespace std;

int main()
{
    // Deklarasi variabel
    int maks, a, i = 1, lokasi;

    // Input panjang array
    cout << "Masukkan panjang array : ";
    cin >> a;

    // Deklarasi array dengan panjang `a`
    int array[a];

    // Input nilai elemen array
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }

    // Inisialisasi variabel `maks` dengan nilai elemen array pertama
    maks = array[0];

    // Looping untuk mencari nilai maksimum
    for (i = 0; i < a; i++)
    {
        // Jika nilai elemen array lebih besar dari `maks`
        if (array[i] > maks)
        {
            // Update nilai `maks` dengan nilai elemen array
            maks = array[i];
            // Simpan lokasi elemen array dengan nilai maksimum
            lokasi = i;
        }
    }

    // Output nilai maksimum dan lokasinya
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
}
