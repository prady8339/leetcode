class Solution {
private:
    vector<vector<int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void mark(vector<vector<int>>& g, vector<vector<int>> &gx, int i, int j,
              bool& isValid) {
        if (i < 0 || i >= g.size() || j < 0 || j >= g[0].size() || g[i][j] != 1)
            return;
        if (gx[i][j] != 1)
            isValid = false;
        g[i][j] = 0;
        for (auto& d : dirs) {
            mark(g, gx, i + d[0], j + d[1], isValid);
        }
    }

public:
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        int n = grid1.size(), m = grid1[0].size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bool isValid = true;
                if (grid2[i][j] == 1) {
                    mark(grid2, grid1, i, j, isValid);
                    if (isValid)
                        res++;
                }
            }
            cout << endl;
        }
        return res;
    }
};