#include <ctime>
#include <iostream>
using namespace std;

void heap(int a[], int n) {
    for (int i = n / 2; i > 0; i--) {
        int k = i, v = a[k], heap = 0;
        while (!heap && (2 * k <= n)) {
            int j = 2 * k;
            if (j < n && a[j] < a[j + 1])
                j++;
            if (v >= a[j])
                heap = 1;
            else {
                a[k] = a[j];
                k = j;
            }
        }
        a[k] = v;
    }
}

void sort(int a[], int n) {
    for (int k = n; k >= 1; k--) {
        int max = a[1], j = 1;
        for (int i = 1; i <= k; i++) {
            if (max < a[i]) {
                max = a[i];
                j = i;
            }
        }
        swap(a[1], a[j]);
        swap(a[1], a[k]);
    }
}

int main() {
    int n;
    cout << "Enter n:";
    cin >> n;
    int a[n];
    cout << "Enter elements:";
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    clock_t start = clock();
    heap(a, n);
    sort(a, n);
    cout << "Sorted: ";
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl
         << "Time: " << (clock() - start) << "clock cycles" << endl;
}
