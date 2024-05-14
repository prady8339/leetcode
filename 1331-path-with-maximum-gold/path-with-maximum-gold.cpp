class Solution {
private:
    vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
    int dfs(vector<vector<int>> &grid,int i,int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) return 0;
        int sum = 0;
        int curr = grid[i][j];
        grid[i][j] = 0;
        for(auto &dir : dirs){
            sum = max(sum, curr + dfs(grid, i + dir[0], j + dir[1]));
        }
        grid[i][j] = curr;
        return sum;
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] != 0){
                    int score = dfs(grid, i, j);
                    ans = max(ans, score);
                }
            }
        }
        return ans;
    }
};