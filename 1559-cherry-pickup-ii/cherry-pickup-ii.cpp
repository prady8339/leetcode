class Solution {
private:
    vector<vector<vector<int>>> memo;
    int solve(vector<vector<int>> &grid,int i,int j,int depth){
        if( min(i,j) < 0 || max(i,j) >= grid[0].size() || depth >= grid.size() ){
            return 0;
        }
        if(memo[i][j][depth] != -1) return memo[i][j][depth];
        int ans = 0;
        for(int a = -1 ; a < 2; a++){
            for(int b= -1; b < 2; b++)
                ans = max(ans, solve(grid, i + a, j + b, depth + 1));
        }
        if(i == j){
            ans -= grid[depth][i];
        }
        return memo[i][j][depth] = ans + grid[depth][i] + grid[depth][j];
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        this->memo.resize(grid[0].size(),vector<vector<int>> (grid[0].size(), vector<int> (grid.size(), -1)));
        
       
        return solve(grid,0,grid[0].size()-1,0);
    }
};