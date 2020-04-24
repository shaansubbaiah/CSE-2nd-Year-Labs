#include <iostream>
using namespace std;

void findMinVert(int v[5], int g[5][5]) {
    int i = 0;  // iter thru v
    while (v[i] != -1) {
        // find least weight branch
        int min = 99;
        for (int j = 0; j < 5; j++) {
            if (g[v[i]][j] > 0 && v[i] != j && min >= g[v[i]][j]) {
                min = g[v[i]][j];
                int newVert = j;
            }
        }
        i++;
    }
}

void findMinEdge(int v[5], int g[5][5]) {
    for (int i = 0; i < 5 - 1; i++) {
        for (int j = 0; j < i; j++) {
        }
    }
}

void prim(int g[5][5]) {
    // let unvisited be -1
    int visited[5] = {0, -1, -1, -1, -1};
    findMinVert(visited, g);

    for (int i = 0; i < 5 - 1; i++) {
    }

    cout << "Visited:";
    for (int i = 0; i < 5; i++)
        cout << visited[i] << ",";
}

int main() {
    //..................0  1  2  3  4
    int graph[5][5] = {{0, 1, 0, 5, 0},   //0
                       {1, 0, 2, 7, 4},   //1
                       {0, 2, 0, 0, 6},   //2
                       {5, 7, 0, 0, 8},   //3
                       {0, 4, 6, 8, 0}};  //4

    prim(graph);

    return 0;
}