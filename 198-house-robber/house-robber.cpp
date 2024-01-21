class Solution {
private:
    int solve(vector<int> &nums,int idx,vector<int> &dp){
        if(idx < 0) return 0;
        if(dp[idx] != -1) return dp[idx];
        int a = nums[idx] + solve(nums, idx - 2 , dp);
        int b = solve(nums, idx - 1, dp);
        return dp[idx] = max(a,b);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums,n-1,dp);
    }
};