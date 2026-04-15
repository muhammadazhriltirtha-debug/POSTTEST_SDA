#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *headQueue = NULL;

Node *headStack = NULL;


void enqueue(int dataBaru) {
    Node *nodeBaru = new Node;
    nodeBaru->data = dataBaru;
    nodeBaru->next = NULL;

    if (headQueue == NULL) {
        headQueue = nodeBaru;
    } else {
        Node *temp = headQueue;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nodeBaru;
    }
    cout << "Data masuk antrian\n";
}

void dequeue() {
    if (headQueue == NULL) {
        cout << "Antrian kosong\n";
        return;
    }
    Node *temp = headQueue;
    cout << "Data keluar: " << temp->data << endl;
    headQueue = headQueue->next;
    delete temp;
}

void tampilAntrian() {
    if (headQueue == NULL) {
        cout << "Antrian kosong\n";
        return;
    }
    Node *temp = headQueue;
    cout << "Isi Antrian: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}


void push(int dataBaru) {
    Node *nodeBaru = new Node;
    nodeBaru->data = dataBaru;
    nodeBaru->next = headStack;
    headStack = nodeBaru;

    cout << "Data masuk stack\n";
}

void pop() {
    if (headStack == NULL) {
        cout << "Stack kosong\n";
        return;
    }
    Node *temp = headStack;
    cout << "Data keluar (Pop): " << temp->data << endl;
    headStack = headStack->next;
    delete temp;
}

void peek() {
    if (headStack == NULL) {
        cout << "Stack kosong\n";
        return;
    }
    cout << "Data teratas: " << headStack->data << endl;
}

void tampilRiwayat() {
    if (headStack == NULL) {
        cout << "Riwayat kosong\n";
        return;
    }
    Node *temp = headStack;
    cout << "Isi Riwayat (Stack): ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
int main() {
    int pilihan, data;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Push\n";
        cout << "4. Pop\n";
        cout << "5. Peek\n";
        cout << "6. Tampil Antrian\n";
        cout << "7. Tampil Riwayat\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data: ";
                cin >> data;
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                cout << "Masukkan data: ";
                cin >> data;
                push(data);
                break;
            case 4:
                pop();
                break;
            case 5:
                peek();
                break;
            case 6:
                tampilAntrian();
                break;
            case 7:
                tampilRiwayat();
                break;
            case 0:
                cout << "Program selesai\n";
                break;
            default:
                cout << "Pilihan tidak valid\n";
        }

    } while (pilihan != 0);

    return 0;
}