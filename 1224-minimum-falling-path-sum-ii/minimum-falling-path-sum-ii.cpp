class Solution {
public:
    int getAns(vector<vector<int>>&grid,int n,int prev,vector<vector<int>>&dp){
        if(n==0){
            int mini=1e8;
            for(int i=0;i<grid.size();i++){
                    if(prev == i) continue;
                    mini=min(mini,grid[n][i]);
     
            }
            return mini;
        }
        if(dp[n][prev]!=-1)return dp[n][prev];
        int mini=1e8;
        for(int j=0;j<grid.size();j++){
            if(j == prev) continue;

            int a =grid[n][j] +getAns(grid,n-1,j,dp);
            mini=min(mini,a);
   
        }
        return dp[n][prev] = mini;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return getAns(grid,n-1,n,dp);
    }
};