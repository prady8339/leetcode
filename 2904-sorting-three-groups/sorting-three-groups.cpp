class Solution {
    
     int solve(int idx,int grp,vector<int> &nums,vector<vector<int>> &dp){
        
        if(idx>=nums.size()) return 0;
        if(grp>3) return 1e5;
       
        int curr = nums[idx];

        if(dp[idx][grp]!=-1) return dp[idx][grp];

        int res = 1e5;

        if(nums[idx]==grp) res = solve(idx+1,grp,nums,dp);
        else{
            if(nums[idx] > grp) res = min(res,solve(idx+1,nums[idx],nums,dp));
            res = min(res,1+solve(idx+1,grp,nums,dp));
            res = min(res,1+solve(idx+1,grp+1,nums,dp));
        }

        return dp[idx][grp] = res;
        
    }
public:
    int minimumOperations(vector<int>& nums) {
       int n = nums.size();
        if(n==1 || n==0) return 0;
        //n+1x4 dp
        int grp = 1;
        vector<vector<int>> dp(n+1,vector<int> (4,-1));
        int ans = solve(0,grp,nums,dp);
        return ans;
    }
};