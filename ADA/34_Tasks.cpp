#include <iostream>
using namespace std;
int temp[10], k = 0;

void topo(int n, int indegree[10], int a[10][10]) {
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            indegree[i] = 1;
            temp[++k] = i;
            for (int j = 1; j <= n; j++) {
                if (a[i][j] == 1 && indegree[j] != -1)
                    indegree[j]--;
            }
            i = 0;
        }
    }
}

void main() {
    int i, j, n, p, x, y, indegree[10], a[10][10];
    int pre[10][10];

    cout << "Enter the number of vertices:";
    cin >> n;
    for (i = 1; i <= n; i++)
        indegree[i] = 0;

    cout << "Enter number of prerequisites:";
    cin >> p;

    cout << "Enter " << p << " prerequisites:";
    for (i = 1; i <= p; i++) {
        for (j = 1; j <= 2; j++)
            cin >> pre[i][j];
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            a[i][j] = 0;
    }
    for (i = 1; i <= p; i++) {
        x = pre[i][1];
        y = pre[i][2];
        a[x + 1][y + 1] = 1;
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (a[i][j] == 1)
                indegree[j]++;
        }
    }
    topo(n, indegree, a);

    if (k != n)
        cout << "All tasks are not possible";

    else {
        cout << "All tasks are possible";
    }
}