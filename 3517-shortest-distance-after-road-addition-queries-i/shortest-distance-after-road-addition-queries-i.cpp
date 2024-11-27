class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& q) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }
        vector<int> ans(q.size(), 0);
        for (int i = 0; i < q.size(); i++) {
            adj[min(q[i][0],q[i][1])].push_back(max(q[i][0],q[i][1]));
            vector<bool> visited(n, false);
            queue<pair<int,int>> q;
            q.push({0,0});
            int dist = n;
            while(!q.empty()){
                auto [t, cost] = q.front();
                q.pop();
                if(t == n - 1) dist = min(cost, dist);
                for(auto &ne : adj[t]){
                    if(!visited[ne]){
                        visited[ne] = true;
                        q.push({ne, cost + 1});
                    }
                }
            }
            ans[i] = dist;
        }
        return ans;
    }
};