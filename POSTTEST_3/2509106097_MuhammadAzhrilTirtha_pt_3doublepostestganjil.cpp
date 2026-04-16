#include <iostream>
#define MAX 100
using namespace std;

string queue[MAX];
int front = -1, rear = -1;

bool isFull() {
    return rear == MAX - 1;
}

bool isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(string nama) {
    if (isFull()) {
        cout << "Queue penuh\n";
        return;
    }
    if (front == -1) front = 0;

    rear++;
    queue[rear] = nama;
    cout << nama << " masuk antrian\n";
}

void enqueueDarurat(string nama) {
    if (isFull()) {
        cout << "Queue penuh\n";
        return;
    }

    if (front == -1) {
        front = rear = 0;
        queue[front] = nama;
    } else {
        for (int i = rear; i >= front; i--) {
            queue[i + 1] = queue[i];
        }
        queue[front] = nama;
        rear++;
    }

    cout << nama << " (DARURAT) masuk paling depan\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue kosong\n";
        return;
    }

    cout << queue[front] << " keluar dari antrian\n";
    front++;

    if (isEmpty()) front = rear = -1;
}

void display() {
    if (isEmpty()) {
        cout << "Queue kosong\n";
        return;
    }

    cout << "Isi antrian:\n";
    for (int i = front; i <= rear; i++) {
        cout << "- " << queue[i] << endl;
    }
}

int main() {
    int pilih;
    string nama;

    do {
        cout << "\n=== MENU GANJIL ===\n";
        cout << "1. Enqueue\n";
        cout << "2. Hewan Darurat\n";
        cout << "3. Dequeue\n";
        cout << "4. Tampil\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                cout << "Nama hewan: ";
                cin >> nama;
                enqueue(nama);
                break;
            case 2:
                cout << "Nama hewan darurat: ";
                cin >> nama;
                enqueueDarurat(nama);
                break;
            case 3:
                dequeue();
                break;
            case 4:
                display();
                break;
        }
    } while (pilih != 0);

    return 0;
}