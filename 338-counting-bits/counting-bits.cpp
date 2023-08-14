class Solution {

public:
    vector<int> countBits(int n) {
       vector<int> dp(n + 1);
        for(int i = 0; i < n+1; i++) {
            if(i&1){
            dp[i] = dp[i >> 1] + 1;
            }else{
            dp[i]=dp[i >> 1];
        }
        }
        return dp;
    }

};