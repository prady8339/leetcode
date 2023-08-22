class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n ,vector<int> (n));
        for(int i = 0 ; i < n ; i++){
            dp[i][i] = 0;
        }

        for(int i = n-1 ; i >= 1 ;i--){
            for(int j = i+1 ; j < n ; j++){
                int mini = 1e9;
                for(int k = i ; k < j ; k++){
                    int temp_ans = dp[i][k] + dp[k+1][j] + values[i-1]*values[k]*values[j];
                    if(temp_ans < mini){
                        mini = temp_ans;
                    }
                }
                dp[i][j] = mini;
            }
        }

        return dp[1][n-1];
    }
};