#include <iostream>
using namespace std;
#define n 5

void dispPair(int p[][4], int l) {
    cout << "Pairs:" << endl;
    for (int k = 0; k < l; k++) {
        cout << p[k][0] << "-" << p[k][1] << " " << p[k][2] << endl;
    }
}

int checkLoop(int p[][4], int l, int curr[]) {
    int e1 = 0, e2 = 0;
    for (int i = 0; i < l; i++) {
        if (p[i][0] == curr[1] && p[i][1] == curr[0] && p[i][3] == 1) {
            return 1;
        }
        if ((p[i][0] == curr[0] || p[i][1] == curr[0]) && p[i][3] == 1) {
            e1 = 1;
        }
        if ((p[i][0] == curr[1] || p[i][1] == curr[1]) && p[i][3] == 1) {
            e2 = 1;
        }
    }
    if (e1 == 1 && e2 == 1) {
        return 1;
    } else {
        return 0;
    }
}

void kru(int g[n][n]) {
    // store edge1, edge2, weight, selected. default to -1 values everywhere
    int pairs[n * n][4] = {-1};
    int k = 0, len = 0;
    // make pairs
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (g[i][j] != 0) {
                pairs[k][0] = i;
                pairs[k][1] = j;
                pairs[k][2] = g[i][j];
                pairs[k][3] = 0;
                len++;
                k++;
            }
        }
    }
    dispPair(pairs, len);
    // sort pairs
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (pairs[i][2] > pairs[j][2]) {
                swap(pairs[j][2], pairs[i][2]);
                swap(pairs[j][1], pairs[i][1]);
                swap(pairs[j][0], pairs[i][0]);
            }
        }
    }
    dispPair(pairs, len);
    // kruskals
    //  set curr to lowest pair
    int currPair[] = {pairs[0][0], pairs[0][1]};
    pairs[0][3] = 1;
    int totVerts = 1, i = 1;
    while (totVerts < n - 1) {
        int nextPair[] = {pairs[i][0], pairs[i][1]};
        if (checkLoop(pairs, len, nextPair) == 0) {
            pairs[totVerts][3] = 1;
            totVerts++;
        } else {
            pairs[totVerts][3] = 0;
        }
        i++;
    }
    // print ans
    int dist = 0;
    cout << "Ans:" << endl;
    for (int k = 0; k < len && pairs[k][3] == 1; k++) {
        cout << pairs[k][0] << "-" << pairs[k][1] << " " << pairs[k][2] << endl;
        dist += pairs[k][2];
    }
    cout << "Tot dist: " << dist << endl;
}

int main() {
    //..................0  1  2  3  4
    int graph[n][n] = {{0, 1, 0, 5, 0},   //0
                       {1, 0, 2, 7, 4},   //1
                       {0, 2, 0, 0, 6},   //2
                       {5, 7, 0, 0, 8},   //3
                       {0, 4, 6, 8, 0}};  //4

    kru(graph);

    return 0;
}