#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Struktur untuk merepresentasikan graf
struct Graph
{
    string *simpul;   // Array untuk menyimpan simpul-simpul graf
    int **busur;      // Matriks untuk menyimpan bobot busur antar simpul
    int jumlahSimpul; // Jumlah total simpul dalam graf
};

// Fungsi untuk menampilkan graf
void tampil(Graph g)
{
    // Menampilkan header kolom dengan nama simpul
    cout << setw(10) << " ";
    for (int i = 0; i < g.jumlahSimpul; i++)
    {
        cout << setw(10) << g.simpul[i];
    }
    cout << endl;

    // Menampilkan matriks bobot busur antar simpul
    for (int i = 0; i < g.jumlahSimpul; i++)
    {
        cout << setw(10) << g.simpul[i]; // Menampilkan nama simpul di baris
        for (int j = 0; j < g.jumlahSimpul; j++)
        {
            cout << setw(10) << g.busur[i][j]; // Menampilkan bobot busur
        }
        cout << endl;
    }
}

int main()
{
    Graph g_2311102185; // Membuat objek graf

    // Meminta pengguna untuk memasukkan jumlah simpul
    cout << "Silahkan masukan jumlah simpul : ";
    cin >> g_2311102185.jumlahSimpul;
    cin.ignore(); // Membersihkan buffer

    // Mengalokasikan memori untuk array simpul dan matriks busur
    g_2311102185.simpul = new string[g_2311102185.jumlahSimpul];
    g_2311102185.busur = new int *[g_2311102185.jumlahSimpul];
    for (int i = 0; i < g_2311102185.jumlahSimpul; i++)
    {
        g_2311102185.busur[i] = new int[g_2311102185.jumlahSimpul]();
    }

    // Meminta pengguna untuk memasukkan nama-nama simpul
    cout << "Silahkan masukan nama simpul\n";
    for (int i = 0; i < g_2311102185.jumlahSimpul; i++)
    {
        cout << "Simpul " << i + 1 << " : ";
        getline(cin, g_2311102185.simpul[i]);
    }

    // Meminta pengguna untuk memasukkan bobot busur antar simpul
    cout << "\nSilahkan masukan bobot antar simpul\n";
    for (int i = 0; i < g_2311102185.jumlahSimpul; i++)
    {
        for (int j = 0; j < g_2311102185.jumlahSimpul; j++)
        {
            cout << g_2311102185.simpul[i] << "--> " << g_2311102185.simpul[j] << " = ";
            cin >> g_2311102185.busur[i][j];
        }
    }

    // Menampilkan graf
    cout << endl;
    tampil(g_2311102185);

    return 0;
}