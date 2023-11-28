class DSU {
    vector<int> rank, parent;

public:
    DSU() : rank(26, 1), parent(26) {
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void join(char uu, char vv) {
        int u = uu - 'a', v = vv - 'a';
        int pu = find(u), pv = find(v);
        if (pu == pv) return;
        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DSU d;
        for (int i = 0; i < s1.size(); i++) {
            d.join(s1[i], s2[i]);
        }

        unordered_map<int, char> grpMin;

        for (int i = 0; i < s1.size(); i++) {
            int p1 = d.find(s1[i] - 'a');
            int p2 = d.find(s2[i] - 'a');

            if (grpMin.count(p1))
                grpMin[p1] = min(grpMin[p1], s1[i]);
            else
                grpMin[p1] = s1[i];

            if (grpMin.count(p2))
                grpMin[p2] = min(grpMin[p2], s2[i]);
            else
                grpMin[p2] = s2[i];
        }

        string res;
        for (auto &base : baseStr) {
            int parent = d.find(base - 'a');
            if (grpMin.count(parent)) {
                char val = grpMin[parent];
                res += val;
            } else {
                res += base;
            }
        }

        return res;
    }
};
