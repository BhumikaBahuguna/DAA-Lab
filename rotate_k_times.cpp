#include<iostream>
using namespace std;
void rotate_array(int a[],int n,int k);
int main(){
    int a[30],n,k,i;
    cout<<"enter n :";
    cin>>n;
    cout<<"enter elements :";
    for(i=0;i<n;i++){
    cin>>a[i];
    }
    cout<<"enter how many times to rotate :";
    cin>>k;
    rotate_array(a,n,k);
    return 0;
}
//reverse complete array
void rotate_array(int a[],int n,int k){       
    int i,j,temp;
    for(i=0,j=n-1;i<n/2;i++,j--){
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
//reverse first k elements
    for(i=0,j=k-1;i<k/2;i++,j--){
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
//reverse last n-k elements
    for(i=k,j=n-1;i<n-k/2;i++,j--){
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    cout<<"rotated array :";
    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
