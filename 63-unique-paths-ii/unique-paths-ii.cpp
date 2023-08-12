class Solution {
    private:
    int solve(vector<vector<int>>& og,vector<vector<int>>& dp,int i,int j){
        if(i>=og.size() || j>=og[0].size()) return 0;
        if(og[i][j]==1) return 0;
        if(i==og.size()-1 && j==og[0].size()-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int down = solve(og,dp,i+1,j);
        int right = solve(og,dp,i,j+1);
        return dp[i][j] = down + right;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int n = og.size(),m=og[0].size();
        //if(og[0][0]==1) return 0;
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return solve(og,dp,0,0);
    }
};