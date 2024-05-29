#include <iostream>
using namespace std;

// Struktur data untuk Node Pohon
struct Pohon
{
    char data;
    Pohon *left, *right, *parent; // Pointer ke anak kiri, anak kanan, dan parent
};

// pointer global
Pohon *root; // Root dari pohon

// Inisialisasi
void init()
{
    root = NULL; // Menginisialisasi root dengan NULL
}

// Mengecek apakah pohon kosong
bool isEmpty()
{
    return root == NULL;
}

// Membuat node baru
Pohon *newPohon(char data)
{
    Pohon *node = new Pohon(); // Mengalokasikan memori untuk node baru
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

// Membuat node root
void buatNode(char data)
{
    if (isEmpty())
    {
        root = newPohon(data); // Membuat node root jika pohon kosong
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    }
    else
    {
        cout << "\nPohon sudah dibuat" << endl; // Jika pohon sudah ada
    }
}

// Mencari node berdasarkan data
Pohon *findNode(Pohon *node, char data)
{
    if (node == NULL || node->data == data)
        return node; // Mengembalikan node jika ditemukan atau NULL jika tidak

    // Rekursi untuk mencari node pada subtree kiri dan kanan
    Pohon *foundNode = findNode(node->left, data);
    if (foundNode == NULL)
        foundNode = findNode(node->right, data);

    return foundNode;
}

// Menambahkan node kiri
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl; // Jika pohon belum dibuat
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kiri!" << endl; // Jika anak kiri sudah ada
            return NULL;
        }
        else
        {
            Pohon *baru = newPohon(data); // Membuat node baru
            baru->parent = node; // Menetapkan parent
            node->left = baru; // Menetapkan anak kiri
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
            return baru;
        }
    }
}

// Menambahkan node kanan
Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl; // Jika pohon belum dibuat
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kanan!" << endl; // Jika anak kanan sudah ada
            return NULL;
        }
        else
        {
            Pohon *baru = newPohon(data); // Membuat node baru
            baru->parent = node; // Menetapkan parent
            node->right = baru; // Menetapkan anak kanan
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
            return baru;
        }
    }
}

// Memperbarui data node
void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl; // Jika pohon belum dibuat
    }
    else
    {
        if (!node)
            cout << "\nNode yang ingin diganti tidak ada!!" << endl; // Jika node tidak ditemukan
        else
        {
            char temp = node->data;
            node->data = data; // Mengubah data node
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

// Menampilkan informasi node
void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl; // Jika pohon belum dibuat
    }
    else
    {
        if (!node)
        {
            cout << "\nNode yang ditunjuk tidak ada!" << endl; // Jika node tidak ditemukan
        }
        else
        {
            cout << "\nData Node: " << node->data << endl;
            cout << "Root: " << root->data << endl;
            if (!node->parent)
                cout << "Parent: (tidak punya parent)" << endl; // Jika tidak punya parent
            else
                cout << "Parent: " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << "Sibling: " << node->parent->left->data << endl; // Menampilkan sibling jika ada
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "Sibling: " << node->parent->right->data << endl;
            else
                cout << "Sibling: (tidak punya sibling)" << endl;
            if (!node->left)
                cout << "Child Kiri: (tidak punya child kiri)" << endl; // Menampilkan anak kiri jika ada
            else
                cout << "Child Kiri: " << node->left->data << endl;
            if (!node->right)
                cout << "Child Kanan: (tidak punya child kanan)" << endl; // Menampilkan anak kanan jika ada
            else
                cout << "Child Kanan: " << node->right->data << endl;
        }
    }
}

// Traversal PreOrder
void preOrder(Pohon *node)
{
    if (node != NULL)
    {
        cout << " " << node->data << ", ";
        preOrder(node->left); // Rekursi untuk anak kiri
        preOrder(node->right); // Rekursi untuk anak kanan
    }
}

// Traversal InOrder
void inOrder(Pohon *node)
{
    if (node != NULL)
    {
        inOrder(node->left); // Rekursi untuk anak kiri
        cout << " " << node->data << ", ";
        inOrder(node->right); // Rekursi untuk anak kanan
    }
}

// Traversal PostOrder
void postOrder(Pohon *node)
{
    if (node != NULL)
    {
        postOrder(node->left); // Rekursi untuk anak kiri
        postOrder(node->right); // Rekursi untuk anak kanan
        cout << " " << node->data << ", ";
    }
}

// Menghitung ukuran pohon
int size(Pohon *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + size(node->left) + size(node->right); // Rekursi untuk menghitung ukuran subtree kiri dan kanan
    }
}

// Menghitung tinggi pohon
int height(Pohon *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        int heightKiri = height(node->left); // Rekursi untuk menghitung tinggi subtree kiri
        int heightKanan = height(node->right); // Rekursi untuk menghitung tinggi subtree kanan
        return (heightKiri > heightKanan) ? heightKiri + 1 : heightKanan + 1;
    }
}

// Menampilkan karakteristik pohon
void characteristic()
{
    int s = size(root);
    int h = height(root);
    cout << "\nSize Tree: " << s << endl;
    cout << "Height Tree: " << h << endl;
    if (h != 0)
        cout << "Average Node of Tree: " << static_cast<float>(s) / h << endl;
    else
        cout << "Average Node of Tree: 0" << endl;
}

// Menampilkan anak-anak dari suatu node
void displayChildren(Pohon *node)
{
    if (node == NULL)
    {
        cout << "\nNode yang ditunjuk tidak ada!" << endl; // Jika node tidak ditemukan
        return;
    }

    cout << "\nChild nodes dari " << node->data << " adalah: " << endl;
    if (node->left != NULL)
        cout << "Child kiri: " << node->left->data << endl; // Menampilkan anak kiri jika ada
    else
        cout << "Child kiri: (tidak punya Child kiri)" << endl;

    if (node->right != NULL)
        cout << "Child kanan: " << node->right->data << endl; // Menampilkan anak kanan jika ada
    else
        cout << "Child kanan: (tidak punya Child kanan)" << endl;
}

// Menampilkan keturunan dari suatu node
void displayDescendants(Pohon *node)
{
    void preOrder(Pohon * node);

    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl; // Jika pohon belum dibuat
    }
    else if (!node)
    {
        cout << "\nNode yang ditunjuk tidak ada!" << endl; // Jika node tidak ditemukan
    }
    else
    {
        cout << "Descendants dari node " << node->data << " : ";
                if (node->left) preOrder(node->left); // Menampilkan keturunan dari anak kiri
        if (node->right) preOrder(node->right); // Menampilkan keturunan dari anak kanan
        cout << endl;
    }
}

// Menghapus seluruh pohon
void deleteTree(Pohon *node)
{
    if (node != NULL)
    {
        deleteTree(node->left); // Rekursi untuk menghapus anak kiri
        deleteTree(node->right); // Rekursi untuk menghapus anak kanan
        delete node; // Menghapus node saat ini
    }
}

// Menghapus subtree dari suatu node
void deleteSubtree(Pohon *node)
{
    if (node != NULL)
    {
        deleteTree(node->left); // Menghapus subtree kiri
        deleteTree(node->right); // Menghapus subtree kanan
        if (node->parent != NULL)
        {
            if (node->parent->left == node)
            {
                node->parent->left = NULL; // Memutus hubungan dari parent jika node adalah anak kiri
            }
            else if (node->parent->right == node)
            {
                node->parent->right = NULL; // Memutus hubungan dari parent jika node adalah anak kanan
            }
        }
        delete node; // Menghapus node saat ini
    }
}

// Sistem menu
void menu()
{
    int choice;
    char data, parentdata_2311102185;
    Pohon *node;

    do
    {
        cout << "========= Program Tree ========" << endl;
        cout << "\nMenu: " << endl;
        cout << "1. Buat Node Root" << endl;
        cout << "2. Tambah Child Kiri" << endl;
        cout << "3. Tambah Child Kanan" << endl;
        cout << "4. Update Node" << endl;
        cout << "5. Characteristics" << endl;
        cout << "6. Find Node" << endl;
        cout << "7. PreOrder Traversal" << endl;
        cout << "8. InOrder Traversal" << endl;
        cout << "9. PostOrder Traversal" << endl;
        cout << "10. Print Child" << endl;
        cout << "11. Print Descendants" << endl;
        cout << "12. Hapus Tree" << endl;
        cout << "13. Hapus SubTree" << endl;
        cout << "14. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Masukkan data untuk root node: ";
            cin >> data;
            buatNode(data); // Membuat node root
            break;
        case 2:
            cout << "Masukkan data untuk node kiri: ";
            cin >> data;
            cout << "Masukkan data node parent: ";
            cin >> parentdata_2311102185;
            node = findNode(root, parentdata_2311102185); // Mencari parent node
            insertLeft(data, node); // Menambahkan anak kiri
            break;
        case 3:
            cout << "Masukkan data untuk node kanan: ";
            cin >> data;
            cout << "Masukkan node parent: ";
            cin >> parentdata_2311102185;
            node = findNode(root, parentdata_2311102185); // Mencari parent node
            insertRight(data, node); // Menambahkan anak kanan
            break;
        case 4:
            cout << "Masukkan data baru untuk node: ";
            cin >> data;
            cout << "Masukkan data node yang akan diupdate: ";
            cin >> parentdata_2311102185;
            node = findNode(root, parentdata_2311102185); // Mencari node yang akan diupdate
            update(data, node); // Memperbarui node
            break;
        case 5:
            characteristic(); // Menampilkan karakteristik pohon
            break;
        case 6:
            cout << "Masukkan data node yang akan dicari: ";
            cin >> data;
            node = findNode(root, data); // Mencari node
            if (node == NULL)
            {
                cout << "\nNode dengan data " << data << " tidak ditemukan!" << endl; // Jika node tidak ditemukan
            }
            else
            {
                find(node); // Menampilkan informasi node
            }
            break;
        case 7:
            cout << "\nPreOrder Traversal:" << endl;
            preOrder(root); // Traversal PreOrder
            cout << "\n";
            break;
        case 8:
            cout << "\nInOrder Traversal:" << endl;
            inOrder(root); // Traversal InOrder
            cout << "\n";
            break;
        case 9:
            cout << "\nPostOrder Traversal:" << endl;
            postOrder(root); // Traversal PostOrder
            cout << "\n";
            break;
        case 10:
            cout << "Masukkan data node yang akan ditampilkan child-nya: ";
            cin >> data;
            node = findNode(root, data); // Mencari node
            displayChildren(node); // Menampilkan anak-anak dari node
            break;
        case 11:
            cout << "Masukkan data node yang akan ditampilkan descendant-nya: ";
            cin >> data;
            node = findNode(root, data); // Mencari node
            displayDescendants(node); // Menampilkan keturunan dari node
            break;
        case 12:
            if (!isEmpty())
            {
                deleteTree(root); // Menghapus seluruh pohon
                root = NULL;
                cout << "\nPohon berhasil dihapus." << endl;
            }
            else
            {
                cout << "\nPohon belum dibuat!" << endl; // Jika pohon belum ada
            }
            break;
        case 13:
            if (!isEmpty())
            {
                cout << "Masukkan data node yang akan dihapus subtree-nya: ";
                cin >> data;
                node = findNode(root, data); // Mencari node
                if (node != NULL)
                {
                    deleteSubtree(node); // Menghapus subtree dari node
                    cout << "\nSubtree dari node " << data << " berhasil dihapus." << endl;
                }
                else
                {
                    cout << "\nNode yang ditunjuk tidak ada!" << endl; // Jika node tidak ditemukan
                }
            }
            else
            {
                cout << "\nPohon belum dibuat!" << endl; // Jika pohon belum ada
            }
            break;
        case 14:
            cout << "Terima kasih! Code By Kepin" << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl; // Jika pilihan tidak valid
        }
    } while (choice != 14);
}

int main()
{
    init(); // Menginisialisasi pohon
    menu(); // Menjalankan sistem menu
    return 0;
}