class Solution {
private:
    vector<vector<int>> dirs{{1,0},{0,1},{-1,0},{0,-1}};
    
    void solve(vector<vector<int>>& grid, int i, int j, int& perimeter, unordered_set<string>& vis) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            perimeter++;
            return;
        }

        if (grid[i][j] == 0) {
            perimeter++;
            return;
        }

        string key = to_string(i) + "_" + to_string(j);
        if (vis.count(key)) return;
        vis.insert(key);

        for (auto& d : dirs) {
            int x = d[0] + i;
            int y = d[1] + j;
            solve(grid, x, y, perimeter, vis);
        }
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        unordered_set<string> vis;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[i].size() ; j++){
                if(grid[i][j] == 1){
                    solve(grid,i,j,perimeter,vis);
                    break;
                }
            }
        }
        return perimeter;
    }
};