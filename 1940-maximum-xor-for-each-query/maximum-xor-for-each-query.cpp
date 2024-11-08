class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
      int n = nums.size();
        vector<int> ans(n);
        
        int maxXor = (1 << maximumBit) - 1;
        
        int mask = 0;
        for (int x : nums) {
            mask ^= x;
        }
        
        for (int i = 0; i < n; ++i) {
            ans[i] = mask ^ maxXor;
            mask ^= nums[n - i - 1]; 
        }
        
        return ans;
    }
};