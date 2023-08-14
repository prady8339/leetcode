class Solution {
private:
    int solve(vector<int> &stones,vector<vector<int>> &dp,int i,int target){
        if(target==0) return 0;
        if(i>=stones.size()) return 0;

        if(dp[i][target]!=-1) return dp[i][target];
        int pick = 0,npick = 0;
        if(target-stones[i]>=0){
            pick = stones[i]+solve(stones,dp,i+1,target-stones[i]);
        }
        npick = solve(stones,dp,i+1,target);
        return dp[i][target] = max(pick,npick);
    }
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0 , n = stones.size();
        for(auto x:stones) sum+=x;
        int target = sum/2;
        vector<vector<int>> dp(n+1,vector<int> (target+1,-1));
        int res = solve(stones,dp,0,target);
        return (sum-2*res);
    }
};