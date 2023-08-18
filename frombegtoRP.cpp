// 1. TWO SUM ----- leetcode
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int>mp; // key is element value and index is corr.value(key pair values).
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(target - nums[i]) != mp.end()) // means if value(target-nums[i]) is present it will never point to the end of hash table.
            {
               ans.push_back(mp[target-nums[i]]);
               ans.push_back(i);
               return ans;
            }
            mp[nums[i]]=i;  // means nums[i]== as key and i as its value.// if element is not present assign in hashtable.
        }
        return ans;
        
    }