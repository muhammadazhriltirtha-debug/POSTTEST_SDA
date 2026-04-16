#include <iostream>
    #define MAX 100
    using namespace std;

    string stackAksi[MAX];
    string stackUndo[MAX];
    string stackRedo[MAX];

    int topAksi = -1;
    int topUndo = -1;
    int topRedo = -1;

    void pushAksi(string aksi) {
        if (topAksi >= MAX - 1) {
            cout << "Stack penuh\n";
            return;
        }

        topAksi++;
        stackAksi[topAksi] = aksi;

        topUndo++;
        stackUndo[topUndo] = aksi;

        topRedo = -1;

        cout << "Aksi ditambahkan: " << aksi << endl;
    }

    void popAksi() {
        if (topAksi < 0) {
            cout << "Stack kosong\n";
            return;
        }

        cout << "Aksi dihapus: " << stackAksi[topAksi] << endl;
        topAksi--;
    }

    void undo() {
        if (topUndo < 0) {
            cout << "Tidak bisa undo\n";
            return;
        }

        string aksi = stackUndo[topUndo];
        topUndo--;

        if (topAksi >= 0) topAksi--;

        topRedo++;
        stackRedo[topRedo] = aksi;

        cout << "Undo: " << aksi << endl;
    }

    void redo() {
        if (topRedo < 0) {
            cout << "Tidak bisa redo\n";
            return;
        }

        string aksi = stackRedo[topRedo];
        topRedo--;

        topAksi++;
        stackAksi[topAksi] = aksi;

        topUndo++;
        stackUndo[topUndo] = aksi;

        cout << "Redo: " << aksi << endl;
    }

    1void display() {
        if (topAksi < 0) {
            cout << "Kosong\n";
            return;
        }

        cout << "Isi Stack:\n";
        for (int i = topAksi; i >= 0; i--) {
            cout << "- " << stackAksi[i] << endl;
        }
    }

    int main() {
        int pilih;
        string aksi;

        do {
            cout << "\n=== MENU GENAP ===\n";
            cout << "1. Push\n";
            cout << "2. Pop\n";
            cout << "3. Undo\n";
            cout << "4. Redo\n";
            cout << "5. Tampil\n";
            cout << "0. Keluar\n";
            cout << "Pilih: ";
            cin >> pilih;

            switch (pilih) {
                case 1:
                    cout << "Masukkan aksi: ";
                    cin >> aksi;
                    pushAksi(aksi);
                    break;
                case 2:
                    popAksi();
                    break;
                case 3:
                    undo();
                    break;
                case 4:
                    redo();
                    break;
                case 5:
                    display();
                    break;
            }
        } while (pilih != 0);

        return 0;
    }