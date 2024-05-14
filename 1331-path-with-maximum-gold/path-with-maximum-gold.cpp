class Solution {
private:
    vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
    int dfs(vector<vector<int>> &grid,int i,int j,vector<vector<bool>> &vis){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0 || vis[i][j]) return 0;
        int sum = 0;
        vis[i][j] = true;
        for(auto &dir : dirs){
            sum = max(sum, grid[i][j] + dfs(grid, i + dir[0], j + dir[1], vis));
        }
        vis[i][j] = false;
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
                    vector<vector<bool>> vis(n,vector<bool> (m,false));
                    int score = dfs(grid,i,j,vis);
                    ans = max(ans, score);
                    vis.clear();
                }
            }
        }
        return ans;
    }
};