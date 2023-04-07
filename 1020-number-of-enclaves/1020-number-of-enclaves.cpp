class Solution {
private:
    void move(vector<vector<int>>& grid, int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) {
            return;
        }
        grid[i][j] = 0;
        move(grid, i - 1, j, n, m);
        move(grid, i + 1, j, n, m);
        move(grid, i, j - 1, n, m);
        move(grid, i, j + 1, n, m);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            move(grid, i, 0, n, m);
            move(grid, i, m - 1, n, m);
        }
        for (int j = 0; j < m; j++) {
            move(grid, 0, j, n, m);
            move(grid, n - 1, j, n, m);
        }
        int sum = 0;
        for (auto x : grid) {
            for (auto y : x) {
                sum += y;
            }
        }
        return sum;
    }
};
