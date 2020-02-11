#include <iostream>
using namespace std;
int firstInstance, lastInstance;

void binarySearch(int arr[], int high, int low, int key, int j){
    int mid;
    while(low<=high){
        mid = (high+low)/2;
        if(arr[mid] == key){
            cout<<"Found "<<key<<" at "<<"arr["<<mid<<"]"<<endl;

            if(j==0)
                firstInstance = lastInstance = mid;
            else{
                if(mid < firstInstance) firstInstance = mid;
                if(mid > lastInstance) lastInstance = mid;
            }
            j++;

            binarySearch(arr, mid-1, low, key, j);

            binarySearch(arr, high, mid+1, key, j);
            break;
        }
        else if(arr[mid] > key)
            high = mid-1;
        else 
            low = mid+1;
    }
}

int main(){
    int n, high, low, key;
    cout<<"Length: ";
    cin>>n;

    int arr[n];
    cout<<"Enter "<<n<<" elements";
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<"Enter key:";
    cin>>key;

    binarySearch(arr, n-1, 0, key, 0);
    cout<<"First Instance: "<<firstInstance<<endl;
    cout<<"Last Instance: "<<lastInstance<<endl;

    return 0;
}
