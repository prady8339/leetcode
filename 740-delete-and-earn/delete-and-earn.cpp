class Solution {
    int solve(vector<int> &freq,vector<int> &dp,int idx){
        if(idx > 10000) return 0;
        if(dp[idx] != -1) return dp[idx];
        int c1 = idx * freq[idx] + solve(freq,dp,idx+2);
        int c2 = solve(freq,dp,idx+1);
        return dp[idx] = max(c1,c2);
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> freq((int) 10001),dp((int) 10001,-1);
        for(auto &x : nums){
            freq[x]++;
        }
        return solve(freq,dp,0);
    }
};