class Solution {
    int solve(int idx,int prev,vector<vector<int>>& pairs,vector<int> &dp){
        if(idx>=pairs.size()) return 0;

        if(dp[idx] != -1) return dp[idx];
        
        int pick = 0 , npick = 0;
        if(pairs[idx][0]>prev){
            pick = 1 + solve(idx+1 , pairs[idx][1] , pairs, dp);
        }
        npick = solve(idx+1 , prev , pairs, dp);

        return dp[idx] = max(pick , npick);
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
         std::sort(pairs.begin(), pairs.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });
        vector<int> dp(n,-1);
        return solve(0,-1001,pairs,dp);
    }
};