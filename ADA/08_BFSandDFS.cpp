#include <iostream>
using namespace std;

void findNodesReachable(int g[][20], int n, int v, int vis[], int f, int r, int q[]){
    for(int i=0; i<n; i++){
        if(g[v][i]==1 && !vis[i]){
            q[r++] = i;
            vis[i] = 1;
        }
        if(f<r)
            findNodesReachable(g, n, q[f++], vis, f, r, q);
    }
}

void checkConnectivity(int g[][20], int n, int v, int vis[]){
    for(int i=0; i<n; i++){
        if(g[v][i]==1 && !vis[i]){
            vis[i] = 1;
            checkConnectivity(g, n, i, vis);
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

    /*
        Check all nodes reachable using BFS
    */

    int visitedBFS[n] = {};
    visitedBFS[v-1] = 1;

    int queueBFS[n], r, f;
    r = f = 0;

    findNodesReachable(grph, n, v, visitedBFS, f, r, queueBFS);

    cout<<"Nodes visitable from "<<v<<": "; 
    for(int i=0; i<n; i++){
        if(queueBFS[i])
            cout<<queueBFS[i];
    }

    /*
        Check Connectivity using DFS
    */

    int visitedDFS[n] = {};
    visitedDFS[v-1] = 1;

    int queueDFS[n];
    r = f = 0;
    checkConnectivity(grph, n, v, visitedDFS);

    for(int i=0; i<n; i++){
        if(!visitedDFS[i]){
            cout<<"Not Connected.";
            return 0;
        }
    }
    cout<<"Connected";

    return 0;
}
