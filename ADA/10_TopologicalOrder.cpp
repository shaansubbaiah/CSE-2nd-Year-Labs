#include <iostream>
#include <stack>
using namespace std;
stack<int> s;

void topo(int v, int visited[], int n, int a[][20]){
	visited[v] = 1;
	for(int i=1; i<=n; i++){
		if(a[v][i]==1 && !visited[i])
			topo(i, visited, n, a);
	}
	s.push(v);
}

int main(){
    int n, a[20][20];
    int visited[30] = {};

	cout<<"No of vertices: ";
	cin>>n;

	cout<<"Enter Adjacency matrix:\n";
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++)
			cin>>a[i][j];
	}
	
	for(int i=1; i<=n; i++){
		if(!visited[i])
			topo(i, visited, n, a);
	}
	
	cout<<"Topological Ordering: "<<endl;

	while(s.empty()==false){
		cout<<s.top()<<" ";
		s.pop();
	}
    cout<<"\n";
	
    return 0;
}