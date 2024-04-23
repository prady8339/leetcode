class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> ans;
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        queue<int> leaves;
        for(int i  = 0 ; i < n ; i++){
            if(degree[i] == 1) leaves.push(i);
        }
        int remNodes = n;
        while(remNodes > 2){
            int lcnt = leaves.size();
            remNodes -= lcnt;
            for(int i = 0 ; i < lcnt ; i++){
                auto leaf = leaves.front();
                leaves.pop();
                for(auto ne : adj[leaf]){
                    degree[ne]--;
                    if(degree[ne] == 1){
                        leaves.push(ne);
                    }
                }
            }
            
        }
        while(!leaves.empty()){
            ans.push_back(leaves.front());
            leaves.pop();
        }
        return ans;
    }
};