#include <iostream>
#include <iomanip>
using namespace std;

struct Mahasiswa
{
    string nama;   // Nama mahasiswa
    long long nim; // NIM mahasiswa
};

struct Node
{
    Mahasiswa data; // Data mahasiswa disimpan dalam node
    Node *next;     // Pointer ke node berikutnya dalam antrian
};

// Pointer global untuk mengelola bagian depan dan belakang antrian
Node *front = NULL;
Node *back = NULL;

// Fungsi untuk memeriksa apakah antrian kosong
bool isEmpty()
{
    return front == NULL; // Antrian kosong jika front adalah NULL
}

// Fungsi untuk menambahkan elemen ke belakang antrian
void enqueueAntrian(string nama, long long nim)
{
    Node *newNode = new Node;  // Membuat node baru
    newNode->data.nama = nama; // Mengatur nama mahasiswa untuk node baru
    newNode->data.nim = nim;   // Mengatur NIM mahasiswa untuk node baru
    newNode->next = NULL;      // Node baru akan menjadi node terakhir, jadi next adalah NULL

    if (isEmpty()) // Jika antrian kosong
    {
        front = back = newNode; // front dan back mengarah ke node baru
    }
    else // Jika antrian tidak kosong
    {
        back->next = newNode; // Menautkan node baru setelah node belakang saat ini
        back = newNode;       // Memperbarui pointer back ke node baru
    }
}

// Fungsi untuk menghapus elemen dari depan antrian
void dequeueAntrian()
{
    if (isEmpty()) // Jika antrian kosong
    {
        cout << "Antrian kosong" << endl;
    }
    else // Jika antrian tidak kosong
    {
        Node *temp = front;  // Simpan sementara node depan
        front = front->next; // Pindahkan pointer front ke node berikutnya
        delete temp;         // Hapus node depan lama

        if (front == NULL) // Jika antrian sekarang kosong
        {
            back = NULL; // Perbarui pointer back ke NULL
        }
    }
}

// Fungsi untuk menghitung jumlah elemen dalam antrian
int countQueue()
{
    int count = 0;       // Inisialisasi hitungan ke nol
    Node *curr = front;  // Mulai dari depan antrian
    while (curr != NULL) // Traversal hingga akhir antrian
    {
        count++;           // Menambah hitungan untuk setiap node
        curr = curr->next; // Pindah ke node berikutnya
    }
    return count; // Kembalikan jumlah node
}

// Fungsi untuk mengosongkan antrian
void clearQueue()
{
    while (!isEmpty()) // Selama antrian tidak kosong
    {
        dequeueAntrian(); // Hapus elemen dari depan antrian
    }
}

// Fungsi untuk menampilkan elemen-elemen dalam antrian
void viewQueue()
{
    cout << "====== Data antrian mahasiswa ======" << endl;
    if (isEmpty()) // Jika antrian kosong
    {
        cout << "Data kosong !" << endl;
        return;
    }

    cout << "-----------------------------------------" << endl;
    cout << "|       Nama         |       NIM        |" << endl;
    cout << "-----------------------------------------" << endl;

    Node *curr = front;  // Mulai dari depan antrian
    while (curr != NULL) // Traversal hingga akhir antrian
    {
        cout << "| " << setw(18) << left << curr->data.nama << " | " << setw(17) << left << curr->data.nim << "|" << endl; // Cetak nama dan NIM node
        curr = curr->next;                                                                                                 // Pindah ke node berikutnya
    }
    cout << "-----------------------------------------" << endl;
}

int main()
{
    enqueueAntrian("Kepin", 123456789);
    enqueueAntrian("Hizkia", 2311102185);
    viewQueue(); // Menampilkan antrian
    cout << "\nJumlah antrian = " << countQueue() << "\n\n";
    dequeueAntrian(); // Menghapus elemen dari depan antrian
    viewQueue();      // Menampilkan antrian
    cout << "\nJumlah antrian = " << countQueue() << "\n\n";
    clearQueue(); // Mengosongkan antrian
    viewQueue();  // Menampilkan antrian
    cout << "\nJumlah antrian = " << countQueue() << "\n\n";

    return 0;
}
