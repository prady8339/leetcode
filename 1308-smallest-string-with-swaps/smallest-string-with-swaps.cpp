class DSU {
    vector<int> rank, parent;

public:
    DSU(int n) : rank(n, 1), parent(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        int p = u;
        while(p != parent[p]){
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }

    void join(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return;

        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
            rank[pu] += rank[pv];
        } else{
            parent[pu] = pv;
            rank[pv] += rank[pu];
        }
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        DSU d(n);
        for (auto &par : pairs) {
            int u = par[0], v = par[1];
            d.join(u, v);
        }
        string ans;
        unordered_map<int,vector<char>> ds;
        for(int i = 0 ; i < n ; i++){
            int par = d.find(i);
            ds[par].push_back(s[i]);
        }
        for(auto &[_, arr] : ds){
            cout<<arr.size()<<endl;
            sort(arr.begin(),arr.end(),greater<char> ());
        }
        for(int i = 0 ; i < n ; i++){
            int par = d.find(i);
            if(ds.count(par) && ds[par].size() > 0){
                ans += ds[par].back();
                ds[par].pop_back();
            }
            else {
                ans += s[i];
            }
        }
        return ans; 
    }
};