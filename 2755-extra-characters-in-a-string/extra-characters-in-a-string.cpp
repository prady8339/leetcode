class Solution {
private:
    int solve(string &s,unordered_set<string> &cache,vector<int> &dp,int idx){
        if(idx >= s.size()){
            return 0;
        }

        if(dp[idx]!=-1) return dp[idx];

        int mini = s.size();
        string curr ;
        for(int i = idx ; i < s.size() ; i++){
            curr.push_back(s[i]);
            int ct = ( cache.count(curr) ? 0 : curr.size() ) + solve(s,cache,dp,i+1);
            mini = min(ct,mini);
        }
        return dp[idx] = mini;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_set<string> cache(dictionary.begin(),dictionary.end());
        vector<int> dp(n+1,-1);
        int ans = solve(s,cache,dp,0);
        return ans;
    }
};