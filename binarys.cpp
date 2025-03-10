#include<iostream>
using namespace std;

int bs(int a[],int lb,int ub,int key,int* c)
{
    while(lb<=ub)
    {
        int mid=(lb+ub)/2;
        (*c)++;
        if(a[mid]==key)
            return 1;
        else if(a[mid]>key)
            ub=mid-1;
        else
            lb=mid+1;
    }
    return -1;
}
int main()
{
    int key,n,t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int c=0;
        cin>>n;
        int *arr=new int[n];
        for(int j=0;j<n;j++)
            cin>>arr[j];
        cin>>key;
        int lb=0;
        int ans=bs(arr,lb,n,key,&c);
        if(ans!=-1)
            cout<<"Present "<<c;
        else
            cout<<"Not Present";
        delete[] arr;
    }
    return 0;
}