#include <iostream>
using namespace std;

// Deklarasi sebuah struktur node
struct node {
    int value;
    node *next;
};

node *head = NULL; // buat linked list masih kosong
node *tail = NULL;

// Deklarasi fungsi printList
void printList();

// TODO : Insert di Depan
void insertFirst(int n) {
    node *newnode = new node;
    newnode -> value = n;
    newnode -> next = NULL;

    if (head == NULL) {
        head = newnode;
        tail = head;
    }
    else {
        newnode -> next = head;
        head = newnode;
    }

    printList();
}

// TODO : Insert di belakang
void insertLast(int n) {
    node *newnode = new node;
    newnode -> value = n;
    newnode -> next = NULL;

    if (head == NULL) {
        head = newnode;
        tail = head;
    }
    else {
        tail -> next = newnode;
        tail = newnode;
    }

    printList();
}

// TODO : Insert setelah nilai tertentu
void insertAfter(int n, int check) {
    if (head == NULL) {
        cout << "List kosong silahkan insert" << endl;
        return;
    }

    node *newnode = new node;
    newnode -> value = n;
    newnode -> next = NULL;

    node *p = head;

    while (p != NULL && p -> value != check) {
        p = p -> next;
    }

    if (p == NULL) {
        cout << "Node dengan nilai " << check
             << " tidak ketemu" << endl;

        delete newnode;
    }
    else {
        newnode -> next = p -> next;
        p -> next = newnode;

        if (p == tail) {
            tail = newnode;
        }

        printList();
    }
}

// TODO : Delete berdasarkan nilai
void deleteNode(int n) {
    if (head == NULL) {
        cout << "List kosong" << endl;
        return;
    }

    // Jika node yang dihapus adalah head
    if (head -> value == n) {
        node *temp = head;

        head = head -> next;

        if (head == NULL) {
            tail = NULL;
        }

        delete temp;

        printList();
        return;
    }

    // Mencari node sebelum node yang akan dihapus
    node *p = head;

    while (p -> next != NULL && p -> next -> value != n) {
        p = p -> next;
    }

    // Jika nilai tidak ditemukan
    if (p -> next == NULL) {
        cout << "Node dengan nilai " << n
             << " tidak ketemu" << endl;
    }
    else {
        node *temp = p -> next;

        p -> next = temp -> next;

        // Jika yang dihapus adalah tail
        if (temp == tail) {
            tail = p;
        }

        delete temp;

        printList();
    }
}

// Cetak linked list
void printList() {
    node *temp = head;

    cout << "Isi dari linked list : ";

    while (temp != NULL) {
        cout << temp -> value << " -> ";
        temp = temp -> next;
    }

    cout << "NULL" << endl;
}

int main() {

    int pilihan;
    int n;
    int check;

    do {
        cout << endl;
        cout << "===== MENU LINKED LIST =====" << endl;
        cout << "1. Insert di depan" << endl;
        cout << "2. Insert di belakang" << endl;
        cout << "3. Insert setelah nilai tertentu" << endl;
        cout << "4. Delete berdasarkan nilai" << endl;
        cout << "5. Tampilkan linked list" << endl;
        cout << "0. Keluar" << endl;

        cout << "Pilih : ";
        cin >> pilihan;

        if (pilihan == 1) {

            cout << "Masukkan nilai : ";
            cin >> n;

            insertFirst(n);
        }

        else if (pilihan == 2) {

            cout << "Masukkan nilai : ";
            cin >> n;

            insertLast(n);
        }

        else if (pilihan == 3) {

            cout << "Masukkan nilai baru : ";
            cin >> n;

            cout << "Masukkan nilai yang ingin dicari : ";
            cin >> check;

            insertAfter(n, check);
        }

        else if (pilihan == 4) {

            cout << "Masukkan nilai yang ingin dihapus : ";
            cin >> n;

            deleteNode(n);
        }

        else if (pilihan == 5) {

            printList();
        }

        else if (pilihan == 0) {

            cout << "Program selesai." << endl;
        }

        else {

            cout << "Pilihan tidak tersedia." << endl;
        }

    } while (pilihan != 0);

    return 0;
}