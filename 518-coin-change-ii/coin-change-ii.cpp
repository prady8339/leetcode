class Solution {
private:
    int solve(int amt,vector<int> &coins,vector<int> &dp){
        if(amt==0) return 1;
        int sum = 0;
        for(auto coin:coins){
            if(amt-coin>=0)
            sum+=solve(amt-coin,coins,dp);
        }
        return sum;
    }

public:
    int change(int amt, vector<int>& coins) {
       int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int> (amt+1));
        for(int i = 0 ; i < n+1 ; i++){
            dp[i][0]=1;
        }
        
        for(int i = 1 ; i < n+1 ; i++){
            for(int j = 1 ; j < amt+1 ; j++){
                if(j>=coins[i-1]){
                    dp[i][j] = dp[i][j-coins[i-1]]+dp[i-1][j];
                }else{
                dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][amt];
    }
};