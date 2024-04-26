class Solution {
public:
    int solve(vector<vector<int>>&grid,int i,int pc,vector<vector<int>>&dp){
        if(i >= grid.size()) return 0;
        if(dp[i][pc]!=-1)return dp[i][pc];
        int mini=1e8;
        for(int j=0;j<grid.size();j++){
            if(j == pc) continue;
            int a = grid[i][j] + solve(grid,i+1,j,dp);
            mini=min(mini,a);
   
        }
        return dp[i][pc] = mini;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(grid,0,n,dp);
    }
};
