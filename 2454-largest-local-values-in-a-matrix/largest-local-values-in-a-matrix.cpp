class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2,vector<int> (n-2,0));
        for(int i = 0 ; i < n-2 ; i++){
            for(int j = 0 ; j < n-2 ; j++){
                for(int x = i ; x < 3 + i ; x++){
                    for(int y = j; y < 3 + j ; y++){
                        ans[i][j] = max(ans[i][j], grid[x][y]);   
                    }
                }
            }
        }
        return ans;
}
};