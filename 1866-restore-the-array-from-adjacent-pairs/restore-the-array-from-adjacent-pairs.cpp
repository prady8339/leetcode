class Solution {
private:
    void dfs(vector<int> &ans,unordered_map<int,vector<int>> &adj,unordered_set<int> &vis,int curr){
        if(vis.count(curr)) return ;
        vis.insert(curr);
        ans.push_back(curr);
        for(auto x:adj[curr]){
            dfs(ans,adj,vis,x);
        }
    }
public:
    vector<int> restoreArray(vector<vector<int>>& adjPairs) {
        int n = adjPairs.size()+1;
        unordered_map<int,vector<int>> adj;
        for(auto &e : adjPairs){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> ans; 
        int first = -1;
        for(auto &[val,arr] : adj){
            if(arr.size()==1){ first = val; break;}
        }
        unordered_set<int> vis;
        dfs(ans,adj,vis,first);
        return ans;
    }
};