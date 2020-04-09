// Quick sort
#include <iostream>
using namespace std;

void merge(int p[], int plen, int q[], int qlen, int r[]) {
    int pi = 0, qi = 0, ri = 0;
    while (pi < plen && qi < qlen) {
        if (p[pi] < q[qi]) {
            r[ri] = p[pi];
            pi++;
        } else {
            r[ri] = q[qi];
            qi++;
        }
        ri++;
    }
    while (pi < plen) {
        r[ri] = p[pi];
        ri++;
        pi++;
    }
    while (qi < qlen) {
        r[ri] = q[qi];
        ri++;
        qi++;
    }
}

void mergeSort(int a[], int l) {
    if (l < 2)
        return;
    int mid = l / 2;
    int left[mid];
    int right[l - mid];

    for (int i = 0; i < l; i++) {
        if (i < mid)
            left[i] = a[i];
        else
            right[i - mid] = a[i];
    }

    mergeSort(left, mid);
    mergeSort(right, l - mid);

    merge(left, mid, right, l - mid, a);
}

int main() {
    int arr[] = {3, 5, 7, 1, 2, 6};
    int len = 6;

    mergeSort(arr, len);

    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}