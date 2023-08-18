// binary search....
#include<iostream>
using namespace std;

int fn(int a[] ,int n, int key)
{
    int low=0,high=n-1;
    int mid;
    int ans=-1;
    while(low<=high)
    {
        mid=(high+low)/2;
            if(a[mid]==key)
            {
                ans=mid;
                break;
            }
            else if(a[mid]<key)
            {
                low=mid+1;
            }
            else(a[mid]>key);
            {
                high=mid-1;
            }

    }
    return ans;
}

//recursively........
#include<iostream>
using namespace std;
int bs(int a[], int low, int high, int x)
{
   if(low>high)
   {
    return -1;
   }
    int mid=(low+high)/2;
    if(a[mid]==x)
    return mid;

    else if(a[mid]<x)
    return bs(a,mid+1,high,x);

    else(a[mid]>x);
    return bs(a,low,mid-1,x);

}
// occurance of first index..........

int firstoccu(int a[], int n, int x)
{ 
   int low=0;
   int high=n-1;
   while(low<=high)
   {
    int mid=(low+high)/2;
    if(a[mid]>x)
    {
        high=mid-1;
    }
    else if(a[mid]<x)
    {
        low=mid+1;
    }
    else // for(a[mid]==x)
    {
        if(a[mid]==0 || a[mid-1]!=a[mid])  // first occurance
        return mid;
        else  // if second occurance then first occurance should be in the left side....
        high=mid-1;
    }

   }
   return -1;
}

//2.






















// index of last occurance.......
#include<iostream>
using namespace std;
 int lastoccu(int a[], int n, int x, int low, int high)
 {
   
    if(low>high) 
    return -1;

    int mid=(low+high)/2;

    if(a[mid]>x)
    return lastoccu(a,n,x,low,mid-1);

    else if(a[mid]<x)
    return lastoccu(a,n,x,mid+1,high);
    
    else{
    if(mid==n-1|| a[mid] != a[mid+1])  // last occurance condition
    return mid;
    else
    return lastoccu(a,n,x,mid+1,high);
    }
 }
int main(int argc, char const *argv[])
{
    int n=7;
    int a[n]={5,10,10,10,10,20,20};
    int low=0;
    int high=n-1;
    int x=10;
    int res= lastoccu(a,n,x,low,high);
    cout<<res<<" ";

    return 0;
}







   while(low<=high)
   {
    int mid=(low+high)/2;
    if(a[mid]>x)
    {
        high=mid-1;
    }
    else if(a[mid]<x)
    {
        low=mid+1;
    }
    else // for(a[mid]==x)
    {
        if(mid=n-1|| a[mid]!=a[mid+1])  
        return mid;
        else  
        low=mid+1;
    }

   }




// first and last occurance of an element in sorted array....

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        v.push_back(-1);
        v.push_back(-1);
        int st=0;int end=nums.size()-1;
        while(st<=end){
           int mid=(st+end)/2;
           if(nums[mid]==target){
               v[0]=mid;
               end=mid-1;
           }else if(nums[mid]<target){
               st=mid+1;
           }else{
               end=mid-1;
           }
          
        }
         st=0;end=nums.size()-1;
         while(st<=end){
           int mid=(st+end)/2;
           if(nums[mid]==target){
               v[1]=mid;
               st=mid+1;
           }else if(nums[mid]<target){
               st=mid+1;
           }else{
               end=mid-1;
           }
        }
        return v;
    }
};

// count 1s in a sorted binary array........

int countones(int arr[], int n)
{
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid= (low+high)/2;
        if(arr[mid]==0)
        {
           low=mid+1;
        }
        else
        {
            if(mid==0 || arr[mid-1] != arr[mid])  // condition for index of first occurance..2.(arr[mid-1]==0)then also FO.
            return (n-mid);
            else
            high=mid-1;  // if another index then search should be on left side...
        }
    }
    return 0;
}

// square root........
#include<iostream>
using namespace std;
 int sqr(int x)
 {
    int low=0,ans=-1;
    int high=x;
    while(low<=high)
    {
        int mid= (low+high)/2;
        int smid= mid*mid;

        if(smid==x)
        return mid;

        else if(smid>x)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
            ans=mid;
        }
    }
    return ans;

 }
int main(int argc, char const *argv[])
{
    int x;
    cout<<"x"<<endl;
    cin>>x;
    int res =sqr(x);
    cout<<res<<" ";
    return 0;
}

// PEAK ELEMENT USING BIANRY SEARCH..
class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int ans=0;
        int n=nums.size();
        if(n==1) return ans;

        //check if first or last element are peak
         if(nums[0]>nums[1]) return 0;
         if(nums[n-1]>nums[n-2]) return n-1;

         //search in the remaining array
            int start=1;
            int end=n-2;

            while(start<=end)
            {
                int mid=start+(end-start)/2;
                if(nums[mid]>nums[mid+1] && nums[mid]> nums[mid-1])  return mid; //if index found
                else if(nums[mid]<nums[mid+1])   start=mid+1; //search in upward slope
                else if(nums[mid]>nums[mid+1])   end=mid;//search in downward slope
            }
        return ans;
        
    }
};


       int ans=0;
       if(n==1) return ans;
       if(arr[0]>arr[1]) return 0;
       if(arr[n-1]>arr[n-2]) return n-1;
       int low=1,high=n-2;
       while(low<=high)
       {
           int mid=(low+high)/2;
           if(arr[mid]>arr[mid+1] and arr[mid]>arr[mid-1])
           return mid;
           
           else if(arr[mid]>arr[mid+1])
           high=mid;
           
           else(arr[mid]<arr[mid+1]);
           low=mid+1;
       }
       
      return ans; 



// search in rotated and sorted array........

int rss(int a[], int target)
{
    int n=a.size();
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]==target)
        return mid;

        // left side is sorted
        if(a[low]<=a[mid])
        {
           if(target>=a[low] && target<=a[mid])
           {
            high=mid-1;
           }
           else
           {
            low=mid+1;
           }
        }
        // right half is sorted...
        else{
            if(target>=a[mid] && target<=a[high])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
    }
    return -1;

}
// minimum element in sorted array.....

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        if(nums[low]<=nums[high])
        return nums[0];
        while(low<=high)
        {
            int mid=(low+high)/2;

            //if(n==1)
            //return nums[0];

             if(nums[mid]>nums[mid+1])
            return nums[mid+1];            

            if(nums[mid]<nums[mid-1])
            return nums[mid];            

            else if(nums[low]<=nums[mid])
            {
                low=mid+1;
            }

            else(nums[mid]<=nums[high]);
            {
                high=mid-1;
            }
        }
        return -1;
    }
};


#include<iostream>
using namespace std;

    int findMin(int nums[],int n) {
        int low=0,high=n-1;
        if(nums[low]<=nums[high])
        return nums[0];
        while(low<=high)
        {
            int mid=(low+high)/2;

            //if(n==1)
            //return nums[0];

             if(nums[mid]>nums[mid+1])
            return nums[mid+1];            

            if(nums[mid]<nums[mid-1])
            return nums[mid];            

            else if(nums[low]<=nums[mid])
            {
                low=mid+1;
            }

            else(nums[mid]<=nums[high]);
            {
                high=mid-1;
            }
        }
        return -1;
    }

int main(int argc, char const *argv[])
{
    int n=5;
    int nums[n]={2,3,4,5,1};
    int res= findMin(nums,n);
    cout<<res<<" ";
    return 0;
}

// find median of a 2d row wise sorted matrix...


class Solution{   
    private:
    int countsmallerthanequaltomid(vector<int>&arr, int mid)
    {
        int l=0;
        int h=arr.size()-1;
        while(l<=h)
        {
           int m=(l+h)/2;
           // we are looking for a value greater than mid // > mid
           if(arr[m]<=mid)
           l=m+1;
           else
           {
               h=m-1;
           }
           
        }
        return l;
    }
public:
    int median(vector<vector<int>> &matrix, int n, int m){  // n--R and m--C
        int low=1;
        int high=1e9;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int count=0; // we have to count numbers smaller than equal to mid
            for(int i=0;i<n;i++)
            {
                count+= countsmallerthanequaltomid(matrix[i],mid); // to find a[ind]>mid;
            }
            if(count <= (m*n)/2)
            low=mid+1;
            else
            high=mid-1;
        }
        return low;
    }
};

// for median the idea is we have to find a number which (https://www.youtube.com/watch?v=63fPPOdIr2c&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=63).




























