class Solution {
public:
    int solve(vector<int> &coins,int amt,vector<int> &dp){
        if(amt==0)
        return 0;
        
        if(dp[amt]!=-1)
        return dp[amt];
        
        int ans=1e9;
        for(auto it:coins){
            if(amt>=it){
                ans=min(ans,solve(coins,amt-it,dp)+1);
            }
        }

        return dp[amt] = ans;
    }
    int coinChange(vector<int>& coins, int amt) {
        vector<int> dp(amt+1,-1);
        int ans=solve(coins,amt,dp);
        return ans==(1e9)?-1:ans;
    }
};