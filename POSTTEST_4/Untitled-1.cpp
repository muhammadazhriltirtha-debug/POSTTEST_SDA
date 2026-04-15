#include <iostream>
using namespace std;

void bubbleSortHuruf(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSortAngka(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[max]) {
                max = j;
            }
        }
        swap(arr[i], arr[max]);
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {

    char huruf[] = {'d', 'a', 'f', 'b', 'c'};
    int angka[] = {12, 5, 20, 3, 9};
    int bebas[] = {7, 2, 10, 1, 6};

    int n = 5;

    cout << "Huruf sebelum: ";
    for (int i = 0; i < n; i++) cout << huruf[i] << " ";

    cout << "\nAngka sebelum: ";
    for (int i = 0; i < n; i++) cout << angka[i] << " ";

    cout << "\nData bebas sebelum: ";
    for (int i = 0; i < n; i++) cout << bebas[i] << " ";

    bubbleSortHuruf(huruf, n);  
    selectionSortAngka(angka, n); 
    insertionSort(bebas, n);     

    cout << "\n\nHuruf ascending: ";
    for (int i = 0; i < n; i++) cout << huruf[i] << " ";

    cout << "\nAngka descending: ";
    for (int i = 0; i < n; i++) cout << angka[i] << " ";

    cout << "\nData bebas (Insertion Sort): ";
    for (int i = 0; i < n; i++) cout << bebas[i] << " ";

    return 0;
}