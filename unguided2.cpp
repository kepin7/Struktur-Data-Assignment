#include <iostream>
#include <iomanip> // Untuk setw
#include <string>
using namespace std;

// Node untuk menyimpan informasi produk
class Node
{
public:
    string namaProduk;
    int harga;
    Node *prev;
    Node *next;
};

// Doubly Linked List untuk menyimpan daftar produk
class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;

    // Konstruktor untuk inisialisasi linked list
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Fungsi untuk menambahkan produk di awal linked list
    void push(string namaProduk, int harga)
    {
        Node *newNode = new Node;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr)
        {
            head->prev = newNode;
        }
        else
        {
            tail = newNode;
        }
        head = newNode;
    }

    // Fungsi untuk menghapus produk berdasarkan nama
    void deleteNode(string namaProduk)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->namaProduk == namaProduk)
            {
                if (current->prev != nullptr)
                {
                    current->prev->next = current->next;
                }
                else
                {
                    head = current->next;
                }

                if (current->next != nullptr)
                {
                    current->next->prev = current->prev;
                }
                else
                {
                    tail = current->prev;
                }

                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Data dengan nama produk '" << namaProduk << "' tidak ditemukan" << endl;
    }

    // Fungsi untuk memasukkan produk setelah produk tertentu
    void insertAfter(string namaProduk, int harga, string afterProduk, int afterHarga)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->namaProduk == afterProduk && current->harga == afterHarga)
            {
                Node *newNode = new Node;
                newNode->namaProduk = namaProduk;
                newNode->harga = harga;
                newNode->prev = current;
                newNode->next = current->next;

                if (current->next != nullptr)
                {
                    current->next->prev = newNode;
                }
                else
                {
                    tail = newNode;
                }
                current->next = newNode;
                return;
            }
            current = current->next;
        }
        cout << "Data not found" << endl;
    }

    // Fungsi untuk memperbarui nama dan harga produk
    bool update(string oldNamaProduk, int oldHarga, string newNamaProduk, int newHarga)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->namaProduk == oldNamaProduk && current->harga == oldHarga)
            {
                current->namaProduk = newNamaProduk;
                current->harga = newHarga;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Fungsi untuk menghapus semua data dari linked list
    void deleteAll()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    // Fungsi untuk menampilkan semua produk dari belakang ke depan
    void tampilkanData()
    {
        Node *current = tail; // Mulai dari tail
        cout << "-----------------------------------------" << endl;
        cout << "|       Nama Produk     |     Harga     |" << endl;
        cout << "-----------------------------------------" << endl;
        while (current != nullptr)
        {
            cout << "|\t" << setw(12) << left << current->namaProduk << " \t| " << setw(6) << current->harga << " \t|" << endl;
            current = current->prev; // Bergerak ke node sebelumnya
        }
        cout << "-----------------------------------------" << endl;
    }
};

int main()
{
    DoublyLinkedList list;

    // Inisialisasi awal data
    list.push("Originote", 60000);
    list.push("Somethinc", 150000);
    list.push("Skintific", 100000);
    list.push("Wardah", 50000);
    list.push("Hanasui", 30000);

    int pilihan;
    do
    {
        // Menampilkan menu
        cout << "Toko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;

        cout << "Masukan pilihan [1-8]: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
        {
            string namaProduk;
            int harga;
            cout << "Masukan nama produk: ";
            cin >> namaProduk;
            cout << "Masukan harga: ";
            cin >> harga;
            list.push(namaProduk, harga);
            break;
        }
        case 2:
        {
            string namaProduk;
            cout << "Masukan nama produk: ";
            cin >> namaProduk;
            list.deleteNode(namaProduk);
            break;
        }
        case 3:
        {
            string oldNamaProduk, newNamaProduk;
            int oldHarga, newHarga;
            cout << "Masukkan nama produk yang lama: ";
            cin >> oldNamaProduk;
            cout << "Masukkan harga produk yang lama: ";
            cin >> oldHarga;
            cout << "Masukkan nama produk yang baru: ";
            cin >> newNamaProduk;
            cout << "Masukkan harga produk yang baru: ";
            cin >> newHarga;
            bool updated = list.update(oldNamaProduk, oldHarga, newNamaProduk, newHarga);
            if (updated)
            {
                cout << "Data berhasil diperbarui" << endl;
            }
            else
            {
                cout << "Data tidak ditemukan" << endl;
            }
            break;
        }
        case 4:
        {
            string namaProduk, afterProduk;
            int harga, afterHarga;
            cout << "Masukkan nama produk yang akan ditambahkan: ";
            cin >> namaProduk;
            cout << "Masukkan harga produk yang akan ditambahkan: ";
            cin >> harga;
            cout << "Masukkan nama produk setelah produk baru: ";
            cin >> afterProduk;
            cout << "Masukkan harga produk setelah produk baru: ";
            cin >> afterHarga;
            list.insertAfter(namaProduk, harga, afterProduk, afterHarga);
            break;
        }
        case 5:
        {
            string namaProduk;
            cout << "Masukkan nama produk yang akan dihapus: ";
            cin >> namaProduk;
            list.deleteNode(namaProduk);
            break;
        }
        case 6:
        {
            list.deleteAll();
            cout << "Semua data berhasil dihapus" << endl;
            break;
        }
        case 7:
        {
            list.tampilkanData();
            break;
        }
        case 8:
        {
            cout << "Terima kasih code By kevin." << endl;
            break;
        }
        default:
        {
            cout << "Pilihan tidak valid" << endl;
            break;
        }
        }
    } while (pilihan != 8);

    return 0;
}