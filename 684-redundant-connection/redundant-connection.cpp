class DSU{
    public:
    vector<int> parent,rank;
    void init(int n){
        parent.resize(n+1);
        for(int i = 0 ; i <= n ;i++){
            parent[i] = i;
        }
        rank.resize(n+1);
    }
    bool join(int u, int v){
        int pu = find(u);
        int pv = find(v);

        if(pu == pv ) return false;
        if(rank[pv] > rank[pu]){
            parent[pu] = pv;
            rank[pv] += rank[pu];
        }else{
            parent[pv] = pu;
            rank[pu] += rank[pv];
        }
        return true;
    }
    int find(int node){
        if(parent[node] == node) return node;
        return find(parent[node]);
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu;
        dsu.init(n);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            if (!dsu.join(u, v)) return {u, v};
        }
        return {};
    }
};