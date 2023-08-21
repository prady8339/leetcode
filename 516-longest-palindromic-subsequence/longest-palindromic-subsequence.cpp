class Solution {
public:
    int longestPalindromeSubseq(string s) {
        //first make new reverse string of s then lcs will be the answer
        // or u can find lcs with two s taking n-i index so it will be the same thing
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1));

        for(int i = 1  ; i < n+1 ; i++){
            for(int j = n-1 ; j>=0 ; j--){
                if(s[i-1] == s[j]){
                    dp[i][j] = 1+dp[i-1][j+1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j+1]);
                }
            }
        }


        // for(int i = 0  ; i < n+1 ; i++){
        //     for(int j = 0 ; j < n+1 ; j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }


        return dp[n][0];
    }
};