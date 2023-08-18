#include<iostream>
using namespace std;
int min(int a[],int n)
{
    
    if(n==0)
    {
        return -1;
    }
    if(n==1)
    {
        return a[0];
    }
    if(a[0]<a[1])
    {
        return a[0];
    }
    int ans=min(a+1,n-1);
    
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int minimum=min(a,n);
    cout<<minimum;
}