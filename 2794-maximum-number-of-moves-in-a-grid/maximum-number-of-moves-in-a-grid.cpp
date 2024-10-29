class Solution {
private:
    int maxJ = 0;
    set<tuple<int,int,int>> st;
    void solve(vector<vector<int>> &grid, int i, int j, int prev){
        if(i >= grid.size() || j < 0 || j >= grid[0].size() || i < 0 ) return ;
        int curr = grid[i][j];
        st.insert(make_tuple(i,j,prev));
        for(int x = -1 ; x <= 1 ; x++){
            if( (i + x) >= 0 && curr > prev && !st.count(make_tuple(i + x, j + 1, curr)) )
            solve(grid, i + x, j + 1, curr);
        }
        if(curr > prev)
        maxJ = max(j, maxJ);
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        for(int i = 0 ; i < grid.size(); i++){
            solve(grid, i, 0, 0);
            if(maxJ == grid[0].size()) return maxJ;
        }
        return maxJ;
    }
};