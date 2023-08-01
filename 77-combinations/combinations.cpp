class Solution {
    private: 
    void solve(int n,int k,int idx,vector<int> &ds,vector<vector<int>> &ans){
        if(idx>=n){
            if(ds.size()==k)
            ans.push_back(ds);
            return;
        }
        solve(n,k,idx+1,ds,ans);
        ds.push_back(idx+1);
        solve(n,k,idx+1,ds,ans);
        ds.pop_back();
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(n,k,0,ds,ans);
        return ans;
    }
};