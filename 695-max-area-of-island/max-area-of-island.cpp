class Solution {
private:
    bool outOfBounds(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        return i < 0 || j < 0 || i >= m || j >= n;
    }

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if(outOfBounds(grid, i, j) || grid[i][j] == 0) {
            return 0;
        }
        grid[i][j] = 0;
        return 1 + dfs(grid, i + 1, j) + dfs(grid, i - 1, j) + dfs(grid, i, j + 1) + dfs(grid, i, j - 1);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0, m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    result = max(result, dfs(grid, i, j));
                }
            }
        }
        return result;
    }
};