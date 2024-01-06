class Solution {
private:
    int dfs(vector<vector<int>> &ds,int idx,vector<int>& dp){
        if(idx >= ds.size()){
            return 0;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        int a = dfs(ds, idx + 1, dp);
          int j = std::lower_bound(ds.begin(), ds.end(), ds[idx][1],[](const std::vector<int>& a, int val) { return a[0] < val; }) - ds.begin();
        int b = ds[idx][2] + dfs(ds, j, dp);
        
        return dp[idx] = max(a, b);
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> ds;
        int n = profit.size();
        for(int i = 0 ; i < n ; i++){
            vector<int> v {startTime[i], endTime[i], profit[i]};
            ds.push_back(v);
        }
        sort(ds.begin(), ds.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        });
        vector<int> dp(n, -1);
        return dfs(ds, 0, dp);
    }
};