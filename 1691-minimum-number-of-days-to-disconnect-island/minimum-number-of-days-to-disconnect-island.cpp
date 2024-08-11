class Solution {

    void dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            grid[i][j] != 1)
            return;
        grid[i][j] = 0;
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    int countIsland(vector<vector<int>> grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }

public:
    int minDays(vector<vector<int>>& grid) {
        if (countIsland(grid) != 1)
            return 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j]) {
                    grid[i][j] = 0;
                    if (countIsland(grid) != 1)
                        return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};