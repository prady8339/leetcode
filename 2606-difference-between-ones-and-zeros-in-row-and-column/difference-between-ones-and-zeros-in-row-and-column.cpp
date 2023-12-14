class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        unordered_map<int,int> rows,cols;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j]==1){
                    rows[i+1]++;
                    cols[j+1]++;
                }else if(grid[i][j]==0){
                    rows[-(i+1)]++;
                    cols[-(j+1)]++;
                }
            }
        }
        vector<vector<int>> ans(n, vector<int> (m));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                ans[i][j] = rows[i+1] + cols[j+1] - rows[-(i+1)] - cols[-(j+1)];
            }
        }

        return ans;
    }
};