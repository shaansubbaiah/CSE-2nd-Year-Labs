#include <ctime>
#include <iostream>

using namespace std;

void selectionSort(int arr[], int n) {
    int min, minIndex;
    for (int i = 0; i < n - 1; i++) {
        min = arr[i];
        minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (min > arr[j]) {
                min = arr[j];
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }

    // display
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main() {
    clock_t timeTaken;
    int arr[] = {4, 6, 8, 3, 5, 2, 9, 1, 0, 7};
    int n = 10;

    timeTaken = clock();
    selectionSort(arr, n);
    timeTaken = clock() - timeTaken;

    cout << "\nTime taken: " << timeTaken << "clocks";

    return 0;
}