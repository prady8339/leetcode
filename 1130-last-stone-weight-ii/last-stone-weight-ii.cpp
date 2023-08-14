class Solution {

public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0 , n = stones.size();
        for(auto x:stones) sum+=x;
        int target = sum/2;
        vector<vector<int>> dp(n+1,vector<int> (target+1));

        for(int i = 1; i < n+1 ; i++){
            for(int j = 1; j < target+1 ; j++){
                if(j>=stones[i-1]){
                    dp[i][j]=max(stones[i-1]+dp[i-1][j-stones[i-1]],dp[i-1][j]);
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }       

        int res = dp[n][target];
        return (sum-2*res);
    }
};