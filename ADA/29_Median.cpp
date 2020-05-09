#include <iostream>
using namespace std;

void merge(int a[], int b[], int c[], int n) {
    int i = 0, j = 0, k = 0;

    while (i < n && j < n) {
        if (a[i] < b[j]) {
            c[k] = a[i];
            k++;
            i++;
        } else {
            c[k] = b[j];
            k++;
            j++;
        }
    }

    while (i < n) {
        c[k] = a[i];
        k++;
        i++;
    }

    while (j < n) {
        c[k] = b[j];
        k++;
        j++;
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int a[n], b[n], c[n * 2];

    cout << "Enter first array: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter second array: ";
    for (int i = 0; i < n; i++)
        cin >> b[i];

    merge(a, b, c, n);

    cout << "Median= " << (c[n - 1] + c[n]) / 2 << endl;
}