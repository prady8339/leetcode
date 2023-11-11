class Graph {
public:
    vector< vector<pair<int,int>> > adj;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto &e : edges){
            adj[e[0]].push_back({e[1],e[2]});
        }
    }
    
    void addEdge(vector<int> e) {
        adj[e[0]].push_back({e[1],e[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> vis(adj.size());
        pq.push({0,node1});
        while(!pq.empty()){
            auto [cost, node] = pq.top();
            pq.pop();
            vis[node] = true;
            if(node == node2) return cost;
            for(auto [next, weight] : adj[node]){
                if(!vis[next])
                pq.push({cost + weight, next});
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */