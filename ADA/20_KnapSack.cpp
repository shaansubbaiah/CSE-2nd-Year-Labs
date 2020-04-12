#include <iostream>
using namespace std;

int main() {
    int totCap = 8;
    int totItm = 4;
    int profit[] = {1, 2, 5, 6};
    int weight[] = {2, 3, 4, 5};
    int k[5][5];

    for (int i = 0; i <= totItm; i++) {
        for (int w = 0; w <= totCap; w++) {
            if (i == 0 || k == 0)
                k[i][w] = 0;
            else if (weight[i] > w)
                k[i][w] = k[i - 1][w];
            else
                k[i][w] = max(k[i - 1][w], (k[i - 1][w - weight[i]] + profit[i]));
        }
    }

    int i = totItm, w = totCap;
    while (i != 0 && w != 0) {
        if (k[i][w] != k[i - 1][w]) {
            cout << i << " ";
            w -= weight[i];
        }
        i--;
    }

    return 0;
}