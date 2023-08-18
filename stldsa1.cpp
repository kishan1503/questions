// check if x exists in the sorted array or not ?
a[]={1,4,5,8,9};

bool res= binary_search(a, a+n, 3);

bool res= binary_search(a, a+n, 4);

// stl lower bound ...
// for arrays...
 a[]={1,4,5,6,9,9,};

int ind= lower_bound(a, a+n, 4)-a;  // returns 1
int ind= lower_bound(a, a+n, 7)-a; // returns 4
int ind= lower_bound(a, a+n, 10)-a; // returns 6

// for vector 
int ind= lower_bound(a.begin(), a.end(), a) -a.begin();

// lower bound is that stl which returns first occ. of ele is it occurs, if not it returns
// iterator pointing to the ele which is immediate next greater of the given element.


// stl upper bound...
// for arrays..
 a[]={1,4,5,6,9,9,};

int ind= upper_bound(a, a+n, 4)-a;  // returns index 2
int ind= upper_bound(a, a+n, 7)-a; // 4
int ind= upper_bound(a, a+n, 10)-a; // 6

// upper bound is that stl which returns the iterator to the next immediate greater element.
// for vector..

int ind= upper_bound(a.begin(), a.end(), a) -a.begin();  
 // TC - log(n);


// QUESTIONS........
 //1. first occurance of a x in a sorted array if not print -1.

 a[]={1,4,4,4,4,9,9,10,11};

 int ind= lower_bound(a, a+n, x) -a;

 if(ind!=n && a[ind]=x) cout<<ind;  // ALWAYS TAKE CARE OF THE EDGE CASES..(while applying these stl).
 else cout<<-1 ;


 //2. last occurance of a x in a sorted array, if not present return -1;

  a[]={1,4,4,4,4,9,9,10,11};

 int ind= upper_bound(a, a+n, x) -a;
 ind--; // last occ= upeer_bound index - 1; 

 if(ind>=0 && a[ind]==x) cout<<ind;
 else cout<<-1;

 
 //3. find the largest number smaller than x in a sorted array.if no print -1;   floor of a sorted array

  a[]={1,4,4,4,4,9,9,10,11};

 int ind= lower_bound(a, a+n, x) -a;
 ind--;

 if(ind>=0) cout<<a[ind];
 else cout<<-1; 
// ex- for x=4 and should be 1. 


//4. find the smallest number greater than x in a sorted array..else print -1;  ceil of a sorted array

  a[]={1,4,4,4,4,9,9,10,11};

 int ind= upper_bound(a, a+n, x) -a;

 if(ind<n) cout<<a[ind]; // for ub point (ex-11)there no such g ele so ind<n. 
 else cout<<-1; 


 //ADVANTAGE--- REDUCES TIME IN CODING CONTEST (AVOID MANY KINES IF CODES).




 // ceil of a sorted array....(smallest number greater than x)
 int ceilingInSortedArray(int n, int x, vector<int> &arr){
    int low=0,high=n-1;
    int ans=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==x)
        return mid;
        else if(arr[mid]>x)
        {
            ans=mid;
            high=mid-1;
        }
        else(arr[mid]<x);
        {
            low=mid+1;
        }
        return ans;
    }
}

// floor of a sorted array(largest number smaller than x).
    int findFloor(vector<long long> v, long long n, long long x){
        long long start=0;
       long long  end= n-1;
       long long result=-1;
       while(start<=end){
           long long mid=start+((end-start)/2);
           if(v[mid]==x){
               result=mid;
               return mid;
               break;
           }
           else if(v[mid]<x){   

               result=mid;

               start=mid+1;
           }
           else
           end=mid-1;
       }
       return result;
    }
