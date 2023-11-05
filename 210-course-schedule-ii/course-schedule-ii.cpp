class Solution {
private:
    bool dfs(vector<vector<int>> &adj,vector<bool> &vis,vector<bool> &vis2,vector<int> &ans,int course){
        if(vis[course]) return false;
        if(adj[course].size()==0){ 
            if(!vis2[course]) 
                ans.push_back(course); 
            vis2[course] = true; 
            return true;
        }
        vis[course] = true;
        for(auto &preReq : adj[course]){
            if(!dfs(adj,vis,vis2,ans,preReq)) return false;
        }
        vis[course] = false;
        vis2[course] = true;
        ans.push_back(course);
        adj[course] = {};
        return true;
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for(auto &e : prerequisites){
            adj[e[0]].push_back(e[1]);
        }
        vector<bool> vis(n);
        vector<bool> vis2(n);
        vector<int> ans;
        for(int i = 0 ; i < n ; i++){
            if(!dfs(adj,vis,vis2,ans,i)) return {};
        }
        return ans;
    }
};