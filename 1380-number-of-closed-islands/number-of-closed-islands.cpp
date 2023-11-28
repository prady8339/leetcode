class Solution {
private:
vector<pair<int, int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool dfs(vector<vector<int>>& grid,int i,int j,vector<vector<bool>> &vis){
    int n = grid.size(), m = grid[0].size();
    if(i < 0 || i >= n || j < 0 || j >= m) return false;
    if(grid[i][j] == 1 || vis[i][j]) return true;

    vis[i][j] = true;
    bool verdict = true;
    for(auto &dir : dirs){
        int x = i + dir.first;
        int y = j + dir.second;
        verdict &= dfs(grid,x,y,vis);
    }
    return verdict;
}
public:
    int closedIsland(vector<vector<int>>& grid) {
        int ct = 0;
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(!vis[i][j] &&grid[i][j] == 0 && dfs(grid,i,j,vis)) ct++;
            }
        }
        return ct;
    }
};