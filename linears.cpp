#include<iostream>
using namespace std;

int ls(int a[],int n,int key,int* c)
{
    for(int i=0;i<n;i++)
    {
        (*c)++;
        if(a[i]==key)
        return 1;
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
        int ans=ls(arr,n,key,&c);
        if(ans==1)
            cout<<"Present "<<c;
        else
            cout<<"Not Present";
        delete[] arr;
    }
    return 0;
}