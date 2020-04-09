#include <iostream>
using namespace std;

int partition(int a[], int l, int r) {
    int pivot = a[r];
    int pIndex = 0;
    for (int i = 0; i < r; i++) {
        if (a[i] <= pivot) {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
    swap(a[pIndex], a[r]);

    return pIndex;
}

void quickSort(int a[], int l, int r) {
    if (l < r) {
        int p = partition(a, l, r);
        quickSort(a, 0, p - 1);
        quickSort(a, p + 1, r);
    }
}

int main() {
    int arr[] = {3, 5, 7, 1, 2, 6};

    quickSort(arr, 0, 5);

    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}