class Solution {

public:
int uniquePathsWithObstacles(vector<vector<int>>& og) {
    int n = og.size(), m = og[0].size();
    vector<int> dp(m);

    dp[0] = 1;

    for (int i = 0; i < n; i++) 
    {
        vector<int> ndp = dp;
        for (int j = 0 ; j < m ; j++) 
        {
            if(j > 0 )
            {
                ndp[j] += ndp[j-1];
            }
            if(og[i][j] == 1)
            { 
                ndp[j] = 0;
            }
        }
        dp = ndp;
    }

    return dp[m - 1];

    }
};