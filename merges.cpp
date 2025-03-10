#include <iostream>
using namespace std;

void merge(int a[],int lb,int mid,int ub) 
{
    int k=0,j=mid+1,i=lb,t[ub-lb+1];
    while(i<=mid && j<=ub)
    {
        if(a[i]<a[j])
        t[k++]=a[i++];
        else
        t[k++]=a[j++];
    }
    while(i<=mid)
    t[k++]=a[i++];
    while(j<=ub)
    t[k++]=a[j++];
    k=0;
    for(i=lb;i<=ub;i++)
    a[i]=t[k++]; 
}

void mergesort(int a[],int lb,int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub); 
        merge(a,lb,mid,ub);
    }
}

int main()
{
    int T,n;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        cin>>n;
        int *arr=new int[n];
        int flag=0;
        for(int j=0;j<n;j++)
        cin>>arr[j];
        mergesort(arr,0,n-1);
        for(int j=0;j<n-1;j++)
        {
            if(arr[j]==arr[j+1])
            {
                cout<<"YES"<<endl;
                flag=1;
                break;
            }
        }
        if(flag==0)
        cout<<"NO"<<endl;
        delete[] arr;
    }
    return 0;
}