#include<iostream>
using namespace std;
int odd_occur(int a[],int n);
int main(){
    int a[60],n,i,odd;
    cout<<"enter n : ";
    cin>>n;
    cout<<"enter elements : ";
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    odd=odd_occur(a,n);
    cout<<"element with odd occurence is:"<<odd;
}
int odd_occur(int a[],int n){
    int result=0;
    for(int i=0;i<n;i++){
        result=result^a[i];
    }
    return result;
}
