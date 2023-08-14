class Solution {
private:
int solve(vector<int>& nums, int target,int idx,int exp,vector<unordered_map<int,int>> &dp){
    if(idx>=nums.size()){
        return exp==target?1:0;
    }
    if(dp[idx].count(exp)) return dp[idx][exp];

    int neg = solve(nums,target,idx+1,exp-nums[idx],dp);
    int pos = solve(nums,target,idx+1,exp+nums[idx],dp);

    return dp[idx][exp] = neg+pos;

}

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //idx,exp
        int n = nums.size();
        vector<unordered_map<int,int>> dp(n+1);
        return solve(nums,target,0,0,dp);
    }
};