class Solution {
public:
    int solve(vector<vector<int>>&grid,int i,int pc,vector<vector<int>>&dp){
        if(i >= grid.size()) return 0;
        if(dp[i][pc] != INT_MAX)return dp[i][pc];
        int mini = INT_MAX;
        for(int j=0;j<grid.size();j++){
            if(j == pc) continue;
            int a = grid[i][j] + solve(grid,i+1,j,dp);
            mini=min(mini,a);
   
        }
        return dp[i][pc] = mini;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dp(201,vector<int>(201,INT_MAX));
        return solve(grid, 0, n, dp);
    }
};
