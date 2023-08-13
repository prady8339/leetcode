class Solution {
private:
    bool solve(vector<int> &nums,int idx,vector<int> &dp){
        int n = nums.size();

        if(idx==n) 
        return true;

        if(dp[idx] != -1) return dp[idx];

        if(idx+1 < n && nums[idx]==nums[idx+1]){
            if(solve(nums,idx+2,dp))
            return dp[idx] = true;
        }
        if(idx+2 < n && nums[idx] == nums[idx+1] && nums[idx] == nums[idx+2]){
            if(solve(nums,idx+3,dp))
            return dp[idx] = true;
        }
        if(idx+2 < n && nums[idx]+1 == nums[idx+1] && nums[idx]+2 == nums[idx+2]){
            if(solve(nums,idx+3,dp))
            return dp[idx] = true;
        }

        return dp[idx] = false;
    }
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return solve(nums, 0, dp);
    }
};
