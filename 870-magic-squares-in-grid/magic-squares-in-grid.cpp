class Solution {
    bool isValid(int x, int y, vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (x + 2 >= n || y + 2 >= m) return false;

        vector<int> count(10, 0);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int val = grid[x + i][y + j];
                if (val < 1 || val > 9 || ++count[val] > 1) {
                    return false;
                }
            }
        }
        
        int sum1 = grid[x][y] + grid[x][y+1] + grid[x][y+2];
        int sum2 = grid[x+1][y] + grid[x+1][y+1] + grid[x+1][y+2];
        int sum3 = grid[x+2][y] + grid[x+2][y+1] + grid[x+2][y+2];
        int col1 = grid[x][y] + grid[x+1][y] + grid[x+2][y];
        int col2 = grid[x][y+1] + grid[x+1][y+1] + grid[x+2][y+1];
        int col3 = grid[x][y+2] + grid[x+1][y+2] + grid[x+2][y+2];
        int diag1 = grid[x][y] + grid[x+1][y+1] + grid[x+2][y+2];
        int diag2 = grid[x][y+2] + grid[x+1][y+1] + grid[x+2][y];
        
        return sum1 == 15 && sum2 == 15 && sum3 == 15 &&
               col1 == 15 && col2 == 15 && col3 == 15 &&
               diag1 == 15 && diag2 == 15;
    }
    
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m - 2; j++) {
                if (isValid(i, j, grid)) ans++;
            }
        }
        return ans;
    }
};
