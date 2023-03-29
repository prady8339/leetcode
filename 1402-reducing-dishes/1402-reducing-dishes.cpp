class Solution {
    private:
    int solve(vector<int> &s,int idx,int f, vector<vector<int>>& dp){
        if(idx==s.size() -1) {
            return f*s[idx];
        }
        if(dp[idx][f]!=-1) return dp[idx][f];
        int take = INT_MIN;
        int nt_take = INT_MIN;
        take = f* s[idx] + solve(s,idx+1,f+1,dp);
        nt_take = solve(s,idx+1,f,dp);
        return dp[idx][f] = max(take , nt_take);
    }
public:
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(),s.end());
        int n = s.size();
        if(s[n-1]<=0) return 0;
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return solve(s,0,1,dp);
    }
};