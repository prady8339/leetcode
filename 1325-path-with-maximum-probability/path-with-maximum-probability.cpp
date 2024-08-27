class Solution {
private:
    void dj(vector<vector<pair<int, double>>>& adj, vector<double>& maxPro,
            int start) {
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start});
        maxPro[start] = 1.0;

        while (!pq.empty()) {
            auto [prob, node] = pq.top();
            pq.pop();

            if (prob < maxPro[node])
                continue;

            for (auto& [nextNode, edgeProb] : adj[node]) {
                double newProb = prob * edgeProb;
                if (newProb > maxPro[nextNode]) {
                    maxPro[nextNode] = newProb;
                    pq.push({newProb, nextNode});
                }
            }
        }
    }

public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {
        vector<vector<pair<int, double>>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }

        vector<double> maxPro(n, 0.0);
        dj(adj, maxPro, start_node);

        return maxPro[end_node];
    }
};
