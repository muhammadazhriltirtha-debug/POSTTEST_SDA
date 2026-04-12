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

Kereta dataKereta[MAX];
int jumlah = 0;

void swapPtr(Kereta *a, Kereta *b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}


void tampil(Kereta *arr, int n) {
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

void tambah() {
    if (jumlah >= MAX) {
        cout << "Data penuh!\n";
        return;
    }

    cout << "\nTambah Data Kereta\n";
    cout << "No Kereta: "; cin >> dataKereta[jumlah].noKereta;
    cout << "Nama Kereta: "; cin >> dataKereta[jumlah].nama;
    cout << "Asal: "; cin >> dataKereta[jumlah].asal;
    cout << "Tujuan: "; cin >> dataKereta[jumlah].tujuan;
    cout << "Harga: "; cin >> dataKereta[jumlah].harga;
    jumlah++;
}

void linearSearch(string asal, string tujuan) {
    if (jumlah == 0) {
        cout << "Data kosong!\n";
        return;
    }

    bool ketemu = false;
    for (int i = 0; i < jumlah; i++) {
        if (dataKereta[i].asal == asal && dataKereta[i].tujuan == tujuan) {

            if (i != 0) swapPtr(&dataKereta[i], &dataKereta[0]);

            cout << "\nDitemukan:\n";
            tampil(dataKereta, 1);
            ketemu = true;
            break;
        }
    }

    if (!ketemu) cout << "Data tidak ditemukan!\n";
}

int minVal(int a, int b) {
    return (a < b) ? a : b;
}

void jumpSearch(int key) {
    if (jumlah == 0) {
        cout << "Data kosong!\n";
        return;
    }

    int step = sqrt(jumlah);
    int prev = 0;

    while (dataKereta[minVal(step, jumlah)-1].noKereta < key) {
        prev = step;
        step += sqrt(jumlah);

        if (prev >= jumlah) {
            cout << "Tidak ditemukan!\n";
            return;
        }
    }

    for (int i = prev; i < minVal(step, jumlah); i++) {
        if (dataKereta[i].noKereta == key) {

            if (i != 0) swapPtr(&dataKereta[i], &dataKereta[0]);

            cout << "\nDitemukan:\n";
            tampil(dataKereta, 1);
            return;
        }
    }

    cout << "Tidak ditemukan!\n";
}

void merge(Kereta arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Kereta *L = new Kereta[n1];
    Kereta *R = new Kereta[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l+i];
    for (int j = 0; j < n2; j++) R[j] = arr[m+1+j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i].nama <= R[j].nama)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(Kereta arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void selectionSort() {
    if (jumlah == 0) {
        cout << "Data kosong!\n";
        return;
    }

    for (int i = 0; i < jumlah-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < jumlah; j++) {
            if (dataKereta[j].harga < dataKereta[minIdx].harga) {
                minIdx = j;
            }
        }
        swapPtr(&dataKereta[i], &dataKereta[minIdx]);
    }
}

int main() {
    int pilih;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Tampil Data\n";
        cout << "2. Tambah Data\n";
        cout << "3. Cari Rute\n";
        cout << "4. Cari Nomor\n";
        cout << "5. Urutkan Nama (A-Z)\n";
        cout << "6. Urutkan Harga (Termurah)\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                tampil(dataKereta, jumlah);
                break;
            case 2:
                tambah();
                break;
            case 3: {
                string asal, tujuan;
                cout << "Asal: "; cin >> asal;
                cout << "Tujuan: "; cin >> tujuan;
                linearSearch(asal, tujuan);
                break;
            }
            case 4: {
                int no;
                cout << "No Kereta: "; cin >> no;
                jumpSearch(no);
                break;
            }
            case 5:
                mergeSort(dataKereta, 0, jumlah-1);
                cout << "Berhasil diurutkan berdasarkan nama\n";
                break;
            case 6:
                selectionSort();
                cout << "Berhasil diurutkan berdasarkan harga\n";
                break;
        }

    } while (pilih != 0);

    return 0;
}