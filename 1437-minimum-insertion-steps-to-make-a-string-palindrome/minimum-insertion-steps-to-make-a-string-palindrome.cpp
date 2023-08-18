class Solution {
public:
    int minInsertions(string s) {
        string temp = s;
        int n = temp.size();
        reverse(s.begin(),s.end());
        vector<vector<int>> dp(n+1,vector<int> (n+1));

        for(int i = 1 ; i < n+1 ; i++){
            for(int j = 1 ; j < n+1 ; j++){
                if(temp[i-1]==s[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else {
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }

        return n - dp[n][n];
    }
};