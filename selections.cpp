#include <iostream>
using namespace std;

int main()
{
    int T,n;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        cin>>n;
        int *arr=new int[n];
        int compare=0,swap=0;
        for(int j=0;j<n;j++)
        cin>>arr[j];
        for(int j=0;j<n-1;j++)
        {
            int min=j;
            for(int k=j+1;k<n;k++)
            {
                compare++;
                if(arr[k]<arr[min])
                min=k;
            }
            int temp=arr[min];
            arr[min]=arr[j];
            arr[j]=temp;
            swap++;
        }
        cout<<"Output: ";
        for(int j=0;j<n;j++)
        cout<<arr[j]<<" ";
        cout<<endl;
        cout<<"Comparisions= "<<compare<<endl;
        cout<<"Swaps= "<<swap<<endl;
        delete[] arr;
    }


    return 0;
}
