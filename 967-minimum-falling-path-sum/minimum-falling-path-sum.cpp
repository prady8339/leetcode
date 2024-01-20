class Solution {
    private:
    int minpath(vector<vector<int>>& matrix,vector<vector<int>>& dp,int i,int j){
        if(j<0 || j>=matrix.size()){
            return INT_MAX;
        }
        if(dp[i][j]!=INT_MAX) return dp[i][j];

        if(i==matrix.size()-1 ) return dp[i][j]=matrix[i][j];

            int l=minpath(matrix,dp,i+1,j-1);
            int c=minpath(matrix,dp,i+1,j);
            int r=minpath(matrix,dp,i+1,j+1);
            dp[i][j]=matrix[i][j]+min(min(l,c),r);
         return dp[i][j];
        
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(int j = 0 ; j< n ; j++){
                ans = min(ans,minpath(matrix,dp,0,j));
        }
       return ans;
    }
};