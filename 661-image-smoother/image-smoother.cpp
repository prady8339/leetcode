class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        vector<vector<int>> res(n, vector<int>(m, 0));
        vector<vector<int>> dirs{
            {1, 1},  {-1, -1}, {1, 0},  {0, 1}, {-1, 0},
            {0, -1}, {-1, 1},  {1, -1}, {0, 0},
        };
        auto is_valid = [&](int i, int j) -> bool {
            return (i >= 0 && i < n && j >= 0 && j < m);
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int sum = 0;
                int e = 0;

                for (auto& d : dirs) {
                    int x = d[0] + i;
                    int y = d[1] + j;
                    if (is_valid(x, y)) {
                        e++;
                        sum += img[x][y];
                    }
                }
                res[i][j] = (int)(sum / e);
            }
        }

        return res;
    }
};