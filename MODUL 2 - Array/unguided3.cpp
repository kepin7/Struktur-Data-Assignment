#include <iostream>

using namespace std;

int main()
{
    // Deklarasi variabel
    int op, maks, min, a, i = 1, lokasi_maks, lokasi_min, total = 0;

    // Input panjang array
    cout << "Masukkan panjang array: ";
    cin >> a;

    // Deklarasi array dengan panjang `a`
    int array[a];

    // Input nilai elemen array
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i + 1) << ": ";
        cin >> array[i];
        total += array[i];
    }

    // Inisialisasi variabel `maks` dan `min` dengan nilai elemen array pertama
    maks = min = array[0];
    lokasi_maks = lokasi_min = 0;

    // perulangan untuk mencari nilai maksimum dan minimum
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi_maks = i;
        }
        else if (array[i] < min)
        {
            min = array[i];
            lokasi_min = i;
        }
    }

    // menghitung nilai rata-rata
    float rata_rata = (float)total / a;

    // Menampilkan menu
    do
    {
        cout << "\n===== Menu =====\n";
        cout << "1. Mencari Nilai Maksimum\n";
        cout << "2. Mencari Nilai Minimum\n";
        cout << "3. Mencari Nilai Rata-rata\n";
        cout << "4. Keluar\n";
        cout << "Masukkan pilihan : ";
        cin >> op;

        switch (op)
        {
        case 1:
            // Output nilai maksimum dan lokasinya
            cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << (lokasi_maks + 1) << endl;
            break;
        case 2:
            // Output nilai minimum dan lokasinya
            cout << "Nilai minimum adalah " << min << " berada di Array ke " << (lokasi_min + 1) << endl;
            break;
        case 3:
            // Output nilai rata-rata
            cout << "Nilai rata-rata adalah " << rata_rata << endl;
            break;
        case 4:
            // Keluar dari program
            cout << "Thank you!, Code By Kevin" << endl;
            break;
        default:
            // pilihan tidak valid
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (op != 4);

    return 0;
}
