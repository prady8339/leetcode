class Solution {
private:
    bool dfs(vector<vector<int>> &adj,vector<bool> &vis,int course){
        if(vis[course]) return false;
        if(adj[course].size()==0) return true;
        vis[course] = true;
        for(auto &preReq : adj[course]){
            if(!dfs(adj,vis,preReq)) return false;
        }
        vis[course] = false;
        adj[course] = {};
        return true;
    }
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for(auto &e : prerequisites){
            adj[e[0]].push_back(e[1]);
        }
        vector<bool> vis(n);
        for(int course = 0 ; course < n ; course++){
            if(!dfs(adj,vis,course)) return false;
        }
        return 1;
    }
};