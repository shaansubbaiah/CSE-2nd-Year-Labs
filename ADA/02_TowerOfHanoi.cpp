#include <iostream>
using namespace std;

void TOH(int n, char fromTower, char usingTower, char toTower){
    if(n==1)
        cout<<"Move disk 1 from "<<fromTower<<" to "<<toTower<<endl;
    else{
        TOH(n-1, fromTower, toTower, usingTower);
        cout<<"Move disk "<<n<<" from "<<fromTower<<" to "<<toTower<<endl;
        TOH(n-1, usingTower, fromTower, toTower);
    }
}

int main(){
    int num;
    cout<<"Enter no. of disks:";
    cin>>num;
    TOH(num, 'A', 'B', 'C');

    return 0;
}