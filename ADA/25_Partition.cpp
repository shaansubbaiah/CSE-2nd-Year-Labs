#include <iostream>
using namespace std;

int partition(int n, int a[]) {
    int sum = 0, part_sum;
    for (int i = 0; i < n; i++)
        sum += a[i];
    if (sum % 2 != 0)
        return 0;
    int part[(sum / 2) + 1][n + 1];  //2D array where part[i][j] is true 1 if subset of array from 0-j-1 index has sum=i
    for (int i = 0; i <= n; i++)
        part[0][i] = 1;
    for (int i = 1; i <= sum / 2; i++)
        part[i][0] = 0;
    for (int i = 1; i <= sum / 2; i++) {
        for (int j = 1; j <= n; j++) {
            part[i][j] = part[i][j - 1];
            if (i >= a[j - 1])
                part[i][j] = part[i][j] || part[i - a[j - 1]][j - 1];
        }
    }
    return part[sum / 2][n];
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    int a[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (partition(n, a))
        cout << "Can be divided";
    else
        cout << "Cannot be divided";

    return 0;
}
