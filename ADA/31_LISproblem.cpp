
#include <iostream>
using namespace std;

int lis(int arr[], int n) {
    int lis[n], i, j, max = 0;

    for (i = 0; i < n; i++)
        lis[i] = 1;

    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (max < lis[i])
            max = lis[i];
    }

    return max;
}

int main() {
    int n;
    cout << "Length: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Length of lis is " << lis(arr, n);
    return 0;
}
