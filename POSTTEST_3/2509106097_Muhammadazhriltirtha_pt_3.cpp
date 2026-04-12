#include <iostream>
#include <cmath>
using namespace std;

#define MAX 100

struct Kereta {
    int noKereta;
    string nama;
    string asal;
    string tujuan;
    int harga;
};

struct Tiket {
    string namaPenumpang;
    string asal;
    string tujuan;
};

Kereta dataKereta[MAX];
int jumlah = 0;

Tiket antrian[MAX];
int front = -1, rear = -1;

Tiket riwayat[MAX];
int top = -1;

void swapPtr(Kereta *a, Kereta *b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

void tampilKereta(Kereta *arr, int n) {
    if (n == 0) {
        cout << "Data kosong!\n";
        return;
    }

    cout << "\n=== DATA KERETA ===\n";
    for (int i = 0; i < n; i++) {
        cout << "No: " << (arr+i)->noKereta
             << " | Nama: " << (arr+i)->nama
             << " | Asal: " << (arr+i)->asal
             << " | Tujuan: " << (arr+i)->tujuan
             << " | Harga: " << (arr+i)->harga << endl;
    }
}

void tambahKereta() {
    if (jumlah >= MAX) {
        cout << "Data penuh!\n";
        return;
    }

    cout << "\nTambah Data Kereta\n";
    cout << "No Kereta: "; cin >> dataKereta[jumlah].noKereta;
    cout << "Nama: "; cin >> dataKereta[jumlah].nama;
    cout << "Asal: "; cin >> dataKereta[jumlah].asal;
    cout << "Tujuan: "; cin >> dataKereta[jumlah].tujuan;
    cout << "Harga: "; cin >> dataKereta[jumlah].harga;
    jumlah++;
}

void enqueue() {
    if (rear == MAX-1) {
        cout << "Antrian penuh!\n";
        return;
    }

    if (front == -1) front = 0;

    rear++;

    cout << "Nama Penumpang: "; cin >> antrian[rear].namaPenumpang;
    cout << "Asal: "; cin >> antrian[rear].asal;
    cout << "Tujuan: "; cin >> antrian[rear].tujuan;

    cout << "Masuk ke antrian!\n";
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Antrian kosong!\n";
        return;
    }

    cout << "\nDiproses:\n";
    cout << "Nama: " << antrian[front].namaPenumpang
         << " | Rute: " << antrian[front].asal
         << " -> " << antrian[front].tujuan << endl;

    if (top < MAX-1) {
        top++;
        riwayat[top] = antrian[front];
    }

    front++;
}

void popRiwayat() {
    if (top == -1) {
        cout << "Riwayat kosong!\n";
        return;
    }

    cout << "Dihapus: " << riwayat[top].namaPenumpang << endl;
    top--;
}

void peek() {
    cout << "\n=== PEEK ===\n";

    if (front != -1 && front <= rear) {
        cout << "Antrian terdepan: " << antrian[front].namaPenumpang << endl;
    } else {
        cout << "Antrian kosong\n";
    }

    if (top != -1) {
        cout << "Transaksi terakhir: " << riwayat[top].namaPenumpang << endl;
    } else {
        cout << "Riwayat kosong\n";
    }
}

void tampilAntrian() {
    if (front == -1 || front > rear) {
        cout << "Antrian kosong!\n";
        return;
    }

    cout << "\n=== ANTRIAN ===\n";
    for (Tiket *p = &antrian[front]; p <= &antrian[rear]; p++) {
        cout << p->namaPenumpang << " | "
             << p->asal << " -> " << p->tujuan << endl;
    }
}

void tampilRiwayat() {
    if (top == -1) {
        cout << "Riwayat kosong!\n";
        return;
    }

    cout << "\n=== RIWAYAT ===\n";
    for (Tiket *p = &riwayat[0]; p <= &riwayat[top]; p++) {
        cout << p->namaPenumpang << " | "
             << p->asal << " -> " << p->tujuan << endl;
    }
}

int main() {
    int pilih;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Tambah Kereta\n";
        cout << "2. Tampil Kereta\n";
        cout << "3. Enqueue (Beli Tiket)\n";
        cout << "4. Dequeue (Proses Tiket)\n";
        cout << "5. Tampil Antrian\n";
        cout << "6. Tampil Riwayat\n";
        cout << "7. Pop Riwayat\n";
        cout << "8. Peek\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1: tambahKereta(); break;
            case 2: tampilKereta(dataKereta, jumlah); break;
            case 3: enqueue(); break;
            case 4: dequeue(); break;
            case 5: tampilAntrian(); break;
            case 6: tampilRiwayat(); break;
            case 7: popRiwayat(); break;
            case 8: peek(); break;
        }

    } while (pilih != 0);

    return 0;
}