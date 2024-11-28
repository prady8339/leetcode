class Solution {
    struct Compare {
        bool operator()(const pair<int, pair<int, int>>& a,
                        const pair<int, pair<int, int>>& b) {
            return a.first > b.first;
        }
    };

public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, Compare>
            pq;
        pq.push({0, {0, 0}});
        vector<vector<int>> dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        vector<vector<int>> vis;
        vis.resize(n, vector<int>(m, 0));
        auto isValid = [&](int x, int y) -> bool {
            return !(x < 0 || x >= n || y < 0 || y >= m);
        };
        while (!pq.empty()) {
            auto [cost, cord] = pq.top();
            auto [i, j] = cord;
            pq.pop();
            if(i == n-1 && j == m - 1) return cost;
            for (auto& d : dirs) {
                int x = d[0] + i;
                int y = d[1] + j;
                if (isValid(x, y) && vis[x][y] == 0) {
                    vis[x][y] = 1;
                    pq.push({grid[x][y] + cost, {x, y}});
                }
            }
        }
        return n * m;
    }
};