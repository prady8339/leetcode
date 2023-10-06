class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        vector<int> dp(60,0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        
        for(int i = 4; i <= n ; i++){
            int maxi = 0;
            for(int j = 1; j < i ; j++){
                int prod = dp[j] * dp[i-j];
                maxi = max(maxi,prod);
            }
            dp[i] =  maxi;
        }
        return dp[n];
    }
};