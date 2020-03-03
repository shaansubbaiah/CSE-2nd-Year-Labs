#include <iostream>
using namespace std;

void maxMeeting(int a[][3], int n){
    int totalMeets = 1;
    cout<<"\nMeetings: 0 ";

    for(int i=0; i<n-1; i++){
        int j = i+1;
        // check if end iTH <= start (i+1)TH
        while(j<n){
            if(a[i][2] <= a[j][1]){
                cout<<a[j][0]<<" ";
                totalMeets++;
                i=j;
            }
            j++;
        }
    }

    cout<<"\nMax Meetings: "<<totalMeets<<endl;
}

void insertionSort(int a[][3], int n){
    for(int i=1; i<n; i++){
        int tempEnd = a[i][2];
        int tempStart = a[i][1];
        int tempNum = a[i][0];

        int j = i;
        while(tempEnd<a[j-1][2] && j>0){
            a[j][2] = a[j-1][2];
            a[j][1] = a[j-1][1];
            a[j][0] = a[j-1][0];

            j--;
        }
        a[j][0] = tempNum;
        a[j][1] = tempStart;
        a[j][2] = tempEnd;
    }
}

int main(){
    int n, i;
    cout<<"Total Meetings: ";
    cin>>n;

    // meetingNumber, start, final stored in every row
    int a[n][3];
    cout<<"Enter start and end time for each meeting.\n";
    for(i=0; i<n; i++){
        cout<<"Meeting "<<i<<": ";
        a[i][0] = i;
        cin>>a[i][1]>>a[i][2];
    }

    insertionSort(a, n);

    cout<<"\nMeetings:\n";
    for(i=0; i<n; i++){
        cout<<"Meeting "<<a[i][0]<<" S:"<<a[i][1]<<" F:"<<a[i][2]<<endl;
    }

    maxMeeting(a, n);

    return 0;
}
