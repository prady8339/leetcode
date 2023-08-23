class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        int sum1 = 0;
        for(int i = n ; i >= 0 ; i--){
            dp[i][m] = sum1;
            if(i>0)
            sum1+=s1[i-1];
        }
        int sum2 = 0;
        for(int j = m ; j >= 0 ; j--){
            dp[n][j] = sum2;
            if(j>0)
            sum2+=s2[j-1];
        }
        dp[n][m]=0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    int del1 = s1[i] + dp[i + 1][j]; // Update with ASCII value
                    int del2 = s2[j] + dp[i][j + 1]; // Update with ASCII value
                    dp[i][j] = min(del1, del2);
                }
            }
        }

        return dp[0][0];
    }
};
