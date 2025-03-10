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
        int compare=0,shift=0;
        for(int j=0;j<n;j++)
        cin>>arr[j];
        for(int j=1;j<n;j++)
        {
            int temp=arr[j];
            int k=j-1;
            while(k>=0)
            {
                //compare++;
                if(arr[k]>temp)
                {
                    compare++;
                    arr[k+1]=arr[k];
                    shift++;
                    k--;
                }
                else
                break;
            }
            arr[k+1]=temp;
            shift++;
        }
        cout<<"Output: ";
        for(int j=0;j<n;j++)
        cout<<arr[j]<<" ";
        cout<<endl;
        cout<<"Comparisions= "<<compare<<endl;
        cout<<"Shifts= "<<shift<<endl;
        delete[] arr;
    }


    return 0;
}