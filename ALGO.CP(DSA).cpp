// ARRAYS
// 1.DUTCH NATIONAL FLAG 
// SORT 0,1,2 'S IN AN ARRAY OR SORTING COLOURS

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=0;
        int high= nums.size()-1;
        while(mid<=high)
        {
            switch(nums[mid])
            {
                case 0: swap(nums[low++], nums[mid++]);
                break;
                case 1: mid++;
                break;
                case 2: swap(nums[mid],nums[high--]);
                break;

            }
        }
        
    }
};

//2. moose voting algorithm.......
// majority element(apperas > n/2)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int candidate=0;
        for(int num: nums)
        {
            if(count==0)
            {
                candidate=num;
            }
            if(num==candidate)
            count+=1;
            else
            count-=1;
        }

        return candidate;
    }
};

//3. KADANE'S algorithm (for maximum subarray sum)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi=INT_MIN;
        for(int x: nums)
        {
            sum+= x;
            maxi=max(sum,maxi);
            if(sum <0)
            sum=0;  // as written.
        }
    return maxi;
    }
};
// we are not carrying negative sum to the array(we carry the sum as long as it gives us a positive sum)