class Solution {
   
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
         int n = og.size(), m = og[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m, 0));

        // Initialize the first cell to 1 if it's not an obstacle
        if (og[0][0] == 0)
            dp[0][0] = 1;

        // Initialize the first column
        for (int i = 1; i < n; i++) {
            if (og[i][0] == 0)
                dp[i][0] = dp[i - 1][0];
        }

        // Initialize the first row
        for (int j = 1; j < m; j++) {
            if (og[0][j] == 0)
                dp[0][j] = dp[0][j - 1];
        }

        // Fill in the dp matrix using dynamic programming
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (og[i][j] == 0)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[n - 1][m - 1];
    
    }
};