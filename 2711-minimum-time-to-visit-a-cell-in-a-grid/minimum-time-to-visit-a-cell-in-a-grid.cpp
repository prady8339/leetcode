class Solution {
    struct Compare {
        bool operator()(const pair<int, pair<int, int>>& a,
                        const pair<int, pair<int, int>>& b) {
            return a.first > b.first;
        }
    };

public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, Compare>
            pq;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;
        pq.push({0, {0, 0}});
        vector<vector<int>> dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        auto isValid = [&](int time, int& x, int& y) -> bool {
            return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] <= time);
        };
        while (!pq.empty()) {
            auto [time, cord] = pq.top();
            auto [i, j] = cord;
            pq.pop();
            if (i == n - 1 && j == m - 1)
                return time;

            if (vis[i][j])
                continue;
            vis[i][j] = 1;

            for (auto& d : dirs) {
                int x = d[0] + i;
                int y = d[1] + j;
                if (isValid(time, x, y)) {
                    pq.push({time + 1, {x, y}});
                } else if (isValid(1e6, x, y)) {
                    int diff = abs(grid[x][y] - time);
                    if (diff % 2 == 0) {
                        pq.push({1 + grid[x][y], {x, y}});
                    } else {
                        pq.push({grid[x][y], {x, y}});
                    }
                }
            }
        }
        return -1;
    }
};