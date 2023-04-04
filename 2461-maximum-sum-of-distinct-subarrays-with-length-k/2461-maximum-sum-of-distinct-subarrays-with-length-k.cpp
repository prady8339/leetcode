class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
      int n = nums.size();
      if(n<k) return 0;
      unordered_map<int,int> um;
      unordered_set<int> us;
      long long sum = 0,maxi=0;
      for(int i = 0 ;i < k ; i++){
        um[nums[i]]++;
        if(um[nums[i]]>1) us.insert(nums[i]);
        sum+=nums[i];
      }

      if(us.empty()) maxi = sum;
      
        for(int i = k ;i < n; i++){
          um[nums[i-k]]--; sum-=nums[i-k];
          if(um[nums[i-k]]<2 && us.count(nums[i-k])){
            us.erase(nums[i-k]);
          }
          um[nums[i]]++; sum+=nums[i];
         if(um[nums[i]]>1) us.insert(nums[i]);
          if(us.empty()) maxi = max(maxi,sum);
        }
        return maxi;
    }
};