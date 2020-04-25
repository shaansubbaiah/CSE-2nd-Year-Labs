#include <iostream>
using namespace std;

int min_change(int n, int m, int c[]) {
    int count = 0;
    cout << "Coins used: ";
    while (n > 0) {
        for (int i = m; i > 0; i--) {
            if (n >= c[i]) {
                cout << c[i] << " ";
                n -= c[i];
                count++;
                break;
            }
        }
    }
    return count;
}

int main() {
    int n, m;
    cout << "Enter the amount: ";
    cin >> n;
    cout << "Enter number of different coins: ";
    cin >> m;
    int coin[m + 1];
    cout << "Enter amount in " << m << " coins in ascending order:";
    for (int i = 1; i <= m; i++)
        cin >> coin[i];
    int result = min_change(n, m, coin);
    cout << endl
         << "No of coins required: " << result;

    return 0;
}
