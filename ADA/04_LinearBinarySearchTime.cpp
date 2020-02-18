#include <iostream>
#include <ctime>
using namespace std;

int binarySearch(int arr[], int high, int low, int key){
    int mid;
    while(low<=high){
        mid = (high+low)/2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] > key)
            return binarySearch(arr, mid-1, low, key);
        else 
            return binarySearch(arr, high, mid+1, key);
    }
    return -1;
}

int linearSearch(int arr[], int key, int i, int n){
    while(i<n){
        if(arr[i] == key)
            return i;
        else
            return linearSearch(arr, key, i+1, n);
    }
    return -1;
}

int main(){
    int n, high, low, i, key;
    cout<<"Length: ";
    cin>>n;

    int arr[n];
    // cout<<"Enter "<<n<<" elements";
    for(int i=0; i<n; i++)
        // cin>>arr[i];
        arr[i] = i;

    cout<<"Enter key:";
    cin>>key;

    clock_t timeTaken;

    // BINARY SEARCH
    timeTaken = clock();
    cout<<"At:"<<binarySearch(arr, n-1, 0, key)<<endl;
    timeTaken = clock() - timeTaken;
    cout<<"Binary Search: "<<timeTaken<<"clocks\n";

    // LINEAR SEARCH
    timeTaken = clock();
    cout<<"At:"<<linearSearch(arr, key, 0, n)<<endl;
    timeTaken = clock() - timeTaken;
    cout<<"Linear Search: "<<timeTaken<<"clocks\n";

    return 0;
}
