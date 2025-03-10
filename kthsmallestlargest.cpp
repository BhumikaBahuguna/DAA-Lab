#include<iostream>
using namespace std;
void swap(int *n1,int *n2)
{
    int temp=*n1;
    *n1=*n2;
    *n2=temp;
}

int partition(int *arr,int l,int r)
{
    int i=l, j=l-1, x=rand()%(r-l+1)+l, pivot=arr[x];
    swap(&arr[x], &arr[r]);
    while(i<r)
    {
        if(arr[i]<pivot)
        {
            j++;
            if(arr[i]!=arr[j])
            swap(&arr[j],&arr[i]);
        }
        i++;
    }
    swap(&arr[j+1],&arr[r]);
    return j+1;
}

void QuickSort(int *arr,int l,int r,int k)
{
    if(l<=r)
    {
        int p=partition(arr,l,r);
        if(p==k){
        cout<<arr[k]<<endl;
        return;}
        if(p>k)
        QuickSort(arr,l,p-1,k);
        else
        QuickSort(arr,p+1,r,k);
    }
}



#include<iostream>
using namespace std;
int main()
{
    int T,n,k;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        cin>>n;
        int *arr=new int[n];
        for(int j=0;j<n;j++)
        cin>>arr[j];
        cin>>k;
        if(k<=0 || k>n)
        {
            cout<<"Not present"<<endl;
            continue;
        }
        QuickSort(arr,0,n-1,k-1); //For kth smallest
        QuickSort(arr,0,n-1,n-k); //For kth largest
        delete[] arr;
    }
    return 0;
}