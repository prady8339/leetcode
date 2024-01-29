class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> prefix_sum(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int top = i > 0 ? prefix_sum[i - 1][j] : 0;
                int left = j > 0 ? prefix_sum[i][j - 1] : 0;
                int top_left = (i > 0 && j > 0) ? prefix_sum[i - 1][j - 1] : 0;
                prefix_sum[i][j] = matrix[i][j] + top + left - top_left;
            }
        }

        int count = 0;
        for (int r1 = 0; r1 < n; r1++) {
            for (int r2 = r1; r2 < n; r2++) {
                unordered_map<int,int> un;
                un[0] = 1;
                for (int c = 0; c < m; c++) {
                    int cur_sum = prefix_sum[r2][c] - (
                        r1 > 0 ? prefix_sum[r1 - 1][c] : 0
                    );
                    int diff = cur_sum - target;
                    count += un[diff];
                    un[cur_sum]++;
                }
            }
        }

        return count;
    }
};
