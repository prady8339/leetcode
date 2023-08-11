class Solution {
    private:
    bool solve(vector<int> &nums,vector<vector<int>> &dp,int idx,int target){
        if(idx>=nums.size() || target<0) return 0;
        if(target==0) return 1;
        if(dp[idx][target]!=-1) return dp[idx][target];
        bool pick = solve(nums,dp,idx+1,target-nums[idx]);
        bool npick = solve(nums,dp,idx+1,target);
        return dp[idx][target]=(pick)||(npick);
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
        }
        if(sum % 2 != 0) return false;

        int target = sum / 2;

        vector<vector<int>> dp(nums.size()+1,vector<int> (target+1,-1));
       return solve(nums,dp,0,target);
    }
};