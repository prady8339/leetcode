class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
         int j = 0;
         int sum = 0;
         int count = 0;
         unordered_map<int,int> prefixSum;
        prefixSum[0]=1;
         while(j<nums.size()){
            sum+=nums[j];
            if(prefixSum.count(sum-k)){
                count+=prefixSum[sum-k];
            }
            prefixSum[sum]++;
            j++;
           }
           return count;
        }  
};