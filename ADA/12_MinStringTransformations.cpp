#include <iostream>
using namespace std;

int getLen(char str[]){
    int i=0;
    while(str[i]!='\0')
        i++;
    return i;
}

int getMin(int a, int b, int c){
    return (a<b?a:b)<c?a:c;
}

int edit(char s1[], char s2[], int l1, int l2){
    if(l1==0)
        return l2;
    if(l2==0)
        return l1;
    if(s1[l1-1]==s2[l2-1])
        return edit(s1,s2,l1-1,l2-1);

    return 1+getMin(edit(s1, s2, l1, l2-1), edit(s1, s2, l1-1, l2), edit(s1, s2, l1-1, l2-1));
}

int main(){
    char s1[10], s2[10];
    int l1,l2;
    cout<<"Enter string1: ";
    cin>>s1;
    cout<<"Enter string2: ";
    cin>>s2;

    l1 = getLen(s1);
    l2 = getLen(s2);

    cout<<"Distance = "<<edit(s1,s2,l1,l2);
}