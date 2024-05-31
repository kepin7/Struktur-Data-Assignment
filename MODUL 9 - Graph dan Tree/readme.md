# <h1 align="center">Laporan Praktikum Modul Graph & Tree</h1>

<p align="center">Hizkia Kevin Octaviano - 2311102185</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

### Graph ###

Graph adalah jenis struktur data yang terdiri dari berbagai node yang saling terhubung. Node pada jenis ini disebut sebagai simpul dimana akan ada garis yang menghubungkan dari setiap simpul tersebut. Jenis ini biasanya digunakan sebagai cara untuk membuat jaringan tertentu, misalnya jaringan komputer atau jaringan telepon. 
Graph menggambarkan suatu kumpulan objek dimana pasangan dari objek tersebut terhubung oleh sebuah link. Objek yang saling terhubung tergambarkan oleh sebuah titik yang disebut sebagai verteks. Sedangkan link yang menghubungkan verteks disebut dengan edge.
Graph dibedakan menjadi dua jenis, yaitu directed graph dan undirected graph. Directed graph adalah garis yang terhubung ke semua simpul, sedangkan undirected graph tidak semua simpul terhubung dengan garis. Jika sebuah simpul tidak terhubung dengan simpul lainnya, maka disebut dengan isolated vertex. Keunggulan jenis ini yaitu dapat membantu untuk memeriksa hubungan antar node dengan cepat dan juga cocok digunakan untuk grafik yang tidak banyak mengandung node. Sementara kekurangannya adalah perlu waktu yang lebih lama dalam hal memodifikasi data[1].

### Istilah pada graph ###

**1. Vertex**

Vertex yaitu himpunan node/titik pada sebuah graph[2].

**2. Edge**

Edge yaitu himpunan garis yang menghubungkan tiap node/vertex[2].

**3. Adjancent**

Dua buah titik dikatakan berdekatan (adjacent) jika keduanya terhubung dengan sebuah sisi[2].

**4. Weight**

Sebuah graph G = (V, E) disebut sebuah graph berbobot
(weight graph) apabila terdapat sebuah fungsi bobot
bernilai real W pada himpunan E[2].

**5. Path**

Path adalah jalur dengan setiap vertex berbeda[2].

**6. Cycle**

Cycle (siklus) atau circuit (sirkuit) merupakan lintasan
yang berawal dan berakhir pada simpul yang sama[2].

### Tree ###

Tree merupakan salah satu jenis struktur data linear yang memiliki
pola seperti pohon. Jenis struktur data ini termasuk kedalam struktur
data hierarkis karena seringkali digunakan untuk menyimpan dan
menyusun data di berbagai level. Oleh karena itu jenis ini sering
dianggap sebagai kumpulan node yang saling terhubung. Setiap node
terdiri dari beberapa data atau link dari node lainnya. Binary tree
adalah salah satu istilah yang sering digunakan dalam jenis ini,
dimana setiap node memiliki paling banyak dua child yaitu left child
dan right child. Binary tree seringkali diimplementasikan
menggunakan link[1]. 

### Istilah pada Tree ###

1. Root: node yang terletak di bagian paling atas[1]. 
2. Child node: turunan dari setiap node[1]. 
3. Parent node: node yang berisi child node (sub-node)[1]. 
4. Siblings: node yang asalnya dari parent node yang sama[1]. 
5. Leaf node: node yang tidak memiliki keturunan lagi[1]. 
6. Internal node: simpul yang memiliki minimal satu child node[1]. 
7. Edge: garis yang menghubungkan antara dua buah simpul dalam tree[1]. 
8. Height of node: jumlah edge dari sebuah node ke leaf node yang paling dalam[1]. 
9. Depth of node: banyaknya edge dari root ke sebuah node[1]. 
10. Height of tree: Panjang jalur terpanjang dari root node ke leaf node sebuah tree[1]. 
11. Degree of node: jumlah cabang yang melekat pada simpul[1]. 
12. Subtree: setiap simpul dari tree beserta turunannya[1]. 

## Guided

### 1. Program Graph

```C++
#include <iostream>
#include <iomanip>
using namespace std;
string simpul[7] = {
    "Ciamis",
    "Bandung",
    "Bekasi",
    "tasikmalaya",
    "Cianjur",
    "Purwokerto",
    "Yogyakarta"};
int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}};

void tampilGraph()
{
    for (int baris = 0; baris < 7; baris++)
    {
        cout << " " << setiosflags(ios::left) << setw(15)
             << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++)
        {
            if (busur[baris][kolom] != 0)
            {
                cout << " " << simpul[kolom] << "(" << busur[baris][kolom]
                     << ")";
            }
        }
        cout << endl;
    }
}
int main()
{
    tampilGraph();
    return 0;
}
``` 

Program graf tersebut terdiri dari 7 simpul, masing-masing merepresentasikan sebuah kota, yaitu "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", dan "Yogyakarta". Matriks `busur` berukuran 7x7 menyimpan bobot (jarak) antara simpul-simpul tersebut, di mana nilai nol menunjukkan tidak ada hubungan langsung (edge) antara dua simpul. Fungsi `tampilGraph` bertugas untuk mencetak graf dalam format yang mudah dibaca, dengan menampilkan setiap simpul beserta simpul-simpul tetangganya yang terhubung, lengkap dengan bobot masing-masing busur. Dalam fungsi `main`, `tampilGraph` dipanggil untuk menunjukkan struktur graf dengan hubungan antar kota dan jarak yang diwakili oleh bobot dari setiap busur, membantu dalam visualisasi hubungan antar simpul dalam graf berbobot.

### 2. Program Tree

```C++
#include <iostream>
using namespace std;
// PROGRAM BINARY TREE
// Deklarasi Pohon
struct Pohon
{
    char data;
    Pohon *left, *right, *parent; // pointer
};
// pointer global
Pohon *root;
// Inisialisasi
void init()
{
    root = NULL;
}
bool isEmpty()
{
    return root == NULL;
}
Pohon *newPohon(char data)
{
    Pohon *node = new Pohon();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}
void buatNode(char data)
{
    if (isEmpty())
    {
        root = newPohon(data);
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    }
    else
    {
        cout << "\nPohon sudah dibuat" << endl;
    }
}
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kiri!"
                 << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
            return baru;
        }
    }
}
Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kanan!"
                 << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
            return baru;
        }
    }
}
void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}
void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\nData node : " << node->data << endl;
        }
    }
}
void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\nData Node : " << node->data << endl;
            cout << "Root : " << root->data << endl;
            if (!node->parent)
                cout << "Parent : (tidak punya parent)" << endl;
            else
                cout << "Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << "Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "Sibling : " << node->parent->right->data << endl;
            else
                cout << "Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << "Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << "Child Kanan : " << node->right->data << endl;
        }
    }
}
// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}
// inOrder
void inOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}
// Hapus Node Tree
void deleteTree(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                if (node->parent->left == node)
                    node->parent->left = NULL;
                else if (node->parent->right == node)
                    node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}
// Hapus SubTree
void deleteSub(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data << " berhasil dihapus." << endl;
    }
}

// Hapus Tree
void clear()
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else
    {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}
// Cek Size Tree
int size(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}
// Cek Height Level Tree
int height(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}
// Karakteristik Tree
void characteristic()
{
    int s = size(root);
    int h = height(root);
    cout << "\nSize Tree : " << s << endl;
    cout << "Height Tree : " << h << endl;
    if (h != 0)
        cout << "Average Node of Tree : " << s / h << endl;
    else
        cout << "Average Node of Tree : 0" << endl;
}
int main()
{
    init();
    buatNode('A');
    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ;
    nodeB = insertLeft('B', root);
    nodeC = insertRight('C', root);
    nodeD = insertLeft('D', nodeB);
    nodeE = insertRight('E', nodeB);
    nodeF = insertLeft('F', nodeC);
    nodeG = insertLeft('G', nodeE);
    nodeH = insertRight('H', nodeE);
    nodeI = insertLeft('I', nodeG);
    nodeJ = insertRight('J', nodeG);
    update('Z', nodeC);
    update('C', nodeC);
    retrieve(nodeC);
    find(nodeC);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n" << endl;
    cout << "InOrder :" << endl;
    inOrder(root);
    cout << "\n" << endl;
    cout << "PostOrder :" << endl;
    postOrder(root);
    cout << "\n" << endl;
    characteristic();
    deleteSub(nodeE);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n" << endl;
    characteristic();
}
``` 

Program dimulai dengan mendeklarasikan struktur `Pohon` yang merepresentasikan simpul dalam pohon, dengan atribut `data` untuk menyimpan nilai simpul dan pointer `left`, `right`, serta `parent` untuk menghubungkan simpul dengan anak kiri, anak kanan, dan induknya. Program ini menyediakan beberapa fungsi utama: `init` untuk inisialisasi pohon, `isEmpty` untuk memeriksa apakah pohon kosong, `newPohon` untuk membuat simpul baru, `buatNode` untuk membuat simpul akar, `insertLeft` dan `insertRight` untuk menambahkan simpul baru sebagai anak kiri atau kanan dari simpul yang ada, `update` untuk mengganti nilai simpul, `retrieve` untuk mengambil nilai simpul, `find` untuk mencari dan menampilkan informasi simpul (termasuk data, induk, saudara, dan anak-anaknya), serta `preOrder`, `inOrder`, dan `postOrder` untuk melakukan traversal pohon dalam urutan pre-order, in-order, dan post-order. Selain itu, program ini juga menyediakan fungsi `deleteTree` untuk menghapus seluruh pohon, `deleteSub` untuk menghapus subtree, `clear` untuk menghapus pohon secara keseluruhan, `size` untuk menghitung jumlah simpul dalam pohon, `height` untuk menghitung tinggi pohon, dan `characteristic` untuk menampilkan karakteristik pohon seperti ukuran, tinggi, dan rata-rata simpul. Program ini juga menyertakan sebuah fungsi `main` yang menginisialisasi pohon, menambahkan simpul-simpul dengan beberapa operasi, memperbarui dan mengambil nilai simpul, menampilkan traversal pohon, serta menghapus subtree dan menampilkan karakteristik pohon setelah modifikasi.

## Unguided

### 1. Soal mengenai Graph
Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.

Output Program

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/84beec41-6816-404c-b784-c5b59696f097)

```C++
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
```
Output Program :

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/973f421c-16b5-4151-bfc8-c315459b74cb)

Program dimulai dengan mendeklarasikan struktur `Graph` yang terdiri dari tiga komponen utama: array `simpul` untuk menyimpan nama-nama simpul dalam graf, matriks `busur` untuk menyimpan bobot busur antara simpul-simpul tersebut, dan integer `jumlahSimpul` untuk menyimpan jumlah total simpul dalam graf.

Dalam fungsi `main`, pengguna diminta untuk memasukkan jumlah simpul dalam graf. Program kemudian mengalokasikan memori untuk array `simpul` dan matriks `busur` sesuai dengan jumlah simpul yang dimasukkan. Pengguna juga diminta untuk memasukkan nama-nama simpul, yang disimpan dalam array `simpul`. Selanjutnya, pengguna memasukkan bobot untuk setiap pasangan simpul, yang disimpan dalam matriks `busur`.

Fungsi `tampil` digunakan untuk menampilkan graf dalam bentuk tabel. Fungsi ini pertama-tama menampilkan header kolom dengan nama-nama simpul, kemudian menampilkan matriks bobot busur antar simpul dengan nama-nama simpul di baris pertama dan kolom pertama, serta bobot busur di sel-sel tabel.

Setelah semua data dimasukkan, graf ditampilkan dengan memanggil fungsi `tampil`.

### 2. Soal mengenai Tree
Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!

```C++
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
```

Output Program :

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/77940da6-72ca-45e2-af56-2b491285ab88)

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/11987ceb-6ccd-4601-b157-2d2a6d71561d)

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/b23c621a-75e5-4a49-9571-2d1810d34a42)

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/fe22e473-f1a6-4deb-ba7d-713f1524ae2c)

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/d1938b77-d928-473a-8f1d-d2a98d2b72aa)

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/1e09615d-e5b8-4f7b-a97e-a710e158f8a1)

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/a12365b6-0c43-43f1-a419-01312a00028a)

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/59ce63c2-de48-43d1-84a0-eece3162476e)

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/b6d52617-cba3-4cf3-8346-fbc3d4177b8c)

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91455626/dc2be4ab-c58e-4ffa-a019-df8fe0fe8a6c)

Program ini menyediakan berbagai operasi untuk mengelola pohon biner, termasuk pembuatan pohon, penambahan node, pembaruan data node, dan penghapusan pohon atau subtree. Pohon direpresentasikan dengan struktur `Pohon` yang memiliki data serta pointer ke anak kiri, anak kanan, dan parent. Program dimulai dengan inisialisasi pohon melalui fungsi `init` yang mengatur root pohon ke `NULL`. Fungsi `isEmpty` digunakan untuk mengecek apakah pohon kosong. Fungsi `newPohon` digunakan untuk membuat node baru, sementara fungsi `buatNode` untuk membuat root node jika pohon belum ada. Pengguna dapat menambahkan anak kiri dan kanan pada node tertentu menggunakan fungsi `insertLeft` dan `insertRight`. Fungsi `findNode` digunakan untuk mencari node berdasarkan data, sedangkan fungsi `update` untuk memperbarui data node. Fungsi `find` menampilkan informasi detail suatu node termasuk parent, sibling, dan anak-anaknya. Program ini juga menyediakan metode traversal seperti PreOrder, InOrder, dan PostOrder untuk menelusuri pohon. Selain itu, fungsi `size` dan `height` digunakan untuk menghitung ukuran dan tinggi pohon, sementara `characteristic` menampilkan karakteristik pohon. Pengguna juga dapat menampilkan anak-anak dan keturunan dari node tertentu menggunakan fungsi `displayChildren` dan `displayDescendants`. Terakhir, program menyediakan opsi untuk menghapus seluruh pohon atau subtree tertentu melalui fungsi `deleteTree` dan `deleteSubtree`.

## Kesimpulan

Graph dan tree merupakan salah satu struktur data pemrograman. Keduanya merepresentasikan hubungan antara objek atau node, tetapi dengan cara yang sedikit berbeda. Graph terdiri dari node dan edge yang menghubungkan node-node tersebut, di mana setiap edge dapat menghubungkan dua node dengan arah yang sama atau berbeda. Sementara itu, tree merupakan salah satu jenis graph yang khusus, di mana tidak ada siklus atau loop dan setiap node hanya memiliki satu parent kecuali root. Tree sering digunakan untuk merepresentasikan hierarki data seperti pada struktur folder dalam sistem operasi. Baik graph maupun tree memiliki banyak aplikasi dalam berbagai bidang seperti jaringan komputer, pengolahan gambar, pencarian jalur terpendek, dan lain sebagainya.

## Referensi

[1] DASAR PEMROGRAMAN : Teori & Aplikasi. (2023). (n.p.): PT. Sonpedia Publishing Indonesia.

[2] Mulyana, A., et al., Cara Mudah Mempelajari Algoritma dan Struktur Data. Edisi Pertama. Yogyakarta : DIVA Press, 2021
