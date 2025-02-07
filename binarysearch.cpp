#include<iostream>
using namespace std;
int binary_search(int [],int ,int);
int main(){
    int a[50],n,i,key,res;
    cout<<"enter no to elements to store:";
    cin>>n;
    cout<<"enter elements(in sorted order):";
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"enter number to be searched:";
    cin>>key;
    res=binary_search(a,n,key);
    if(res==-1)
    cout<<"not found";
    else
    cout<<"Element found at index:"<< res ;
    return 0;
}
int binary_search(int a[],int n,int key){
    int l=0,r=n-1,mid=0;
    while(l<=r){
    mid=(l+r)/2;
    if(key==a[mid])
    return mid;
    else if(key<a[mid])
    r=mid-1;
    else
    l=mid+1;
    }
    return -1;
}
