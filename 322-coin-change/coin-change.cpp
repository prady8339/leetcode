class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int> (amt+1));
  
        for(int j = 0 ; j < amt+1 ; j++){
            dp[0][j]=1e5;
        }

        for(int i = 1 ; i < n+1 ; i++){
            for(int j = 1; j < amt+1 ; j++){
                if(j>=coins[i-1]){
                    dp[i][j] = min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][amt]==1e5?-1:dp[n][amt];
    }
};