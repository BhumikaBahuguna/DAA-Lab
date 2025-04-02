#include <iostream>
using namespace std;

int main()
{
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int n,key,pair=0;
        cin>>n;
        int *arr=new int[n];
        for(int j=0;j<n;j++)
        cin>>arr[j];
        cin>>key;
        for(int j=0;j<n-1;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if((arr[j]-arr[k]==key) || (arr[k]-arr[j]==key))
                pair++;
            }
        }
        cout<<pair<<endl;
        delete[] arr;
    }


    return 0;
}
