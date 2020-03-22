#include <iostream>
using namespace std;

void checkCycles(int g[][20], int n, int v, int vis[]){
    for(int i=0; i<n; i++){
        if(g[v][i]==1 && !vis[i]){
            vis[i] = 1;
            checkCycles(g, n, i, vis);
        }
    }
}


int main(){
    int n, v, grph[20][20];

    cout<<"No. of vertices:";
    cin>>n;

    cout<<"Enter Adjacency Matrix:";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>grph[i][j];
        }
    }

    cout<<"Starting Vertex:";
    cin>>v;

    int visitedDFS[n] = {};
    visitedDFS[v-1] = 1;

    int queueDFS[n], r, f;
    r = f = 0;
    checkCycles(grph, n, v, visitedDFS);

    for(int i=0; i<n; i++){
        if(!visitedDFS[i]){
            cout<<"Not Connected.";
            return 0;
        }
    }
    cout<<"Connected";

    return 0;
}
