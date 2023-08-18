#include<iostream>
using namespace std;

int insert(int arr[],int n, int x, int cap, int pos)
{
    if(n==cap)
    return n;

    int ind= pos-1;

    for(int i=n-1; i>=ind; i--)
    {
        arr[i]=arr[i+1];
        arr[pos]=x;
    }
    return (n+1);
}

int fn(int arr[], int n)
{
    int max=arr[0];
    int smax=-1;
    for(int i=1;i<n-1;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
            smax=max;
        }
        else if(arr[i]<max and arr[i]>smax)
        {
            smax=arr[i];
        }
        
    }
    return smax;


}












































