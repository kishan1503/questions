// insert element in an array.....
int insert(int arr[],int n, int x, int cap, int pos)
{
    if(n==cap)
    return n;

    int index=pos-1;

    for(int i=n-1;i>=index;i-- )
    {
        arr[i+1]=arr[i];
        arr[index]=x;
    }
    return(n+1);
}

// deletion of an array
int delete(int arr[], int n, int x)
{ int i;
    for( i=0;i<n;i++)
    {
        if(arr[i]==x)
        break;
    }
    if(n==x)
    return n;

    for(int j=i;j<n-1;j++)
    {
       arr[j]=arr[j+1];
    }
    return(n-1);
}
// second largest element in an array.....

int fn(int a[], int n)
{
    int max=a[0];
    int smax=-1;

    for(int i=1;i<n;i++)
    {
        if(a[i]>max)
        {
            smax=max;
            max=a[i];
        }
        else if(max>a[i] and a[i]>smax )
        {
            smax=a[i];
        }
    }
    return smax;
}
// remove duplicates from an array...
    int remove_duplicate(int a[],int n){
        int temp[n];
        temp[0]=a[0];
        int res=1;
        for(int i=1;i<n;i++)
        {
            if(temp[res-1]=!a[i])
            {
                temp[res]=a[i];
            }
        }
        for(int i=0;i<res;i++)
        {
            a[i]=temp[i];
        }
        return res;
    }

// efficient approach..........    

int remdub(int arr[], int n)
{
  int res=1;
  for(int i=1;i<n;i++)
  {
    if(arr[i]!=arr[res-1])
    {
        arr[res]=arr[i];
        res++;
    }
  }
  return res;  //res contains no of distinct elements....
}

// move zeroes to end............
int zte(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            for(int j=i;j<n;j++)
            {
                if(a[j]!=0)
                {
                    swap(a[i],a[j]);
                }
            }
        }
    }
}
// efficient solution....

int zth(int a[], int n)
{
    int count=0;    // for knowing the index of zero we keep a track of non zero elements.
    for(int i=0;i<n;i++)
    {
        if(a[i]!=0)
        {
            swap(a[i],a[count]);
            count++;
        }
    }
}

// search in a 2D matrix......
// 1. leetcode...(imaginary binary search)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if(!matrix.size()) return false;
        
        int n=matrix.size();
        int m=matrix[0].size();

        int low=0;
        int high=(n*m)-1;

        while(low<=high)
        {
            int mid=(low+high)/2;
            if(matrix[mid/m][mid%m]== target)
            return true;
            else if(matrix[mid/m][mid%m]> target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return false;
    }

// 2. gfg........
	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	   int i=0,j=M-1;
	   while(i<N and j>=0)
	   {
	       if(mat[i][j]== X)
	       return 1;
	       if(mat[i][j]> X)
	       j--;
	       else
	       i++;
	   }
	   return 0;
    }

// stock buy and sell...
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxpro=0;
        int minprice=INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            minprice=min(minprice,prices[i]);
            maxpro=max(maxpro,(prices[i]-minprice));
        }
    return maxpro;    
    }
};  // we are keeping a track of minimal on the left side...




//rearrange array elements by sign..

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pi=0,ni=1;
        vector<int> ans(nums.size());
        for(auto &ele : nums)
        {
            if(ele>=0)
            {
               ans[pi]=ele;
               pi+=2;
            }
            else{
            ans[ni]=ele;
            ni+=2;}
        }
        return ans;
    }
};

// longest consecutive sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s;
        for(int x: nums)
        {
            s.insert(x);
        }
        int longeststreak=0;
        for(int x: nums)
        {
            if(!s.count(x-1))
            {
                int currnum=x;
                int currstreak=1;

                while(s.count(currnum+1))
                {
                    currnum +=1;
                    currstreak += 1;
                }
                longeststreak=max(currstreak,longeststreak);
            }
            
        }
      return longeststreak;  
    }
};




















