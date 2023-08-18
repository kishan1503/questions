#include<bits/stdc++.h>
using namespace std;

// hashing means in simple terms: 
// processing the given values and getting a corresponding hashValue
// Processing can be thought of for every value (x) in array, we pass it to some f(x) and get some value. This is called 
// HashValue
// Now, if I'm asked whether some value x exists in my array.
// I can pass this x to f(x) and get it's corresponding hashValue
// Now, if this hashValue is already present in my hashMap then I can immediately say yes else no

// arr of size 5
// F(x) -> x % len -> (0, len-1)
// arr= {11, 14, 10, 2, 3}
// F(11) -> 11 % 5 = 1
// F(14) -> 14 % 5 = 4
// F(10) -> 10 % 5 = 0
// F(2) -> 2 % 5 = 2
// F(3) -> 3 % 5 = 3
// hashArray[5] = { 1, 1, 1, 1, 1}
// Hey kishan, tell me if 14 is present in your array?
// F(14) = 4 
// Now, check the 4th index in array if it's true.
// But there is a problem.
// If i have a value like 24,
// F(24) = 4
// So, this gives true. But 24 is not present in our array.
// So, choosing a good hashing function is very important.
// Hashing function: F(s) -> ASCII -> s[0]*P^0 + s[1]*p^1 + s[2]*p^2 + ... s[n-1]*p^(n-1)
// F(s) -> unique integer
int main(){
    auto start=clock();
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    int q;
    cin>>n>>q;
    vector<int>a(n);
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]=true;
    }
    while(q--){
        int x;
        cin>>x;
        bool flag=mp.count(x);
        cout<<((flag)?"YES":"NO")<<endl;
    }
    auto end=clock();
    cout<<"Time Taken: "<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
}

// REST PART IS IN THE NOTES....

// unordered_map and unordered_set (in hashing)....SIGNIFICANCE....

// unique no of occurences...
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        unordered_set<int>s;
        for(auto x: mp)
        {
            int freq=x.second;
            s.insert(freq);
        }
        return s.size()==mp.size();

    }
};

// count distinct elements.........

int cd(int arr[], int n)
{
    int res=0;
    for(int i=0;i<n;i++)
    {
        bool flag=false;
        for(int j=0;j<i;j++) // checking left side of arr[i]; for(int j=i-1;j<=0;j--)
        {
            if(arr[i]==arr[j])
            {
                 flag=true;
                 break;
            }
        }
        if(flag==false)
        {
            res++;
        }
    }
    return res;
}
 // efficient...

 int cd(int arr[], int n)
 {
    unordered_set<int>s;
    for(int i=0;i<n;i++)
    {
        s.insert(arr[i]);  // bcoz set stores only unique keys...
    }
    return s.size();
 }

 //2.
 int cd(int arr[], int n)
 {
    unordered_set<int>s(arr,arr+n);
    return s.size();
 }
// count frequency of the distinct element..........
#include<iostream>
using namespace std;

void printfreq(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        bool flag=false;
        for(int j=0;j<i;j++)
            if(arr[i]==arr[j])
            {
                flag=true;
                break;
            }
            if(flag==true)
            continue;
        
            int freq=1;
            for(int j=i+1;j<n;j++)
                if(arr[i]==arr[j])
                {
                    freq++;
                }
            cout<<arr[i]<<" "<<freq<<endl;                
    }
}
int main(int argc, char const *argv[])
{
    int arr[6]={10,20,10,20,30,40};
    printfreq(arr,6);

    return 0;
}
// efficient(using hash map)
#include<iostream>
using namespace std;
void pf(int arr[], int n)
{
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    for(auto x: mp)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }
}































