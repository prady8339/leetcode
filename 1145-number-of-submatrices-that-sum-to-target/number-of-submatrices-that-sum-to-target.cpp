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
                for (int c1 = 0; c1 < m; c1++) {
                    for (int c2 = c1; c2 < m; c2++) {
                        int top = r1 > 0 ? prefix_sum[r1 - 1][c2] : 0;
                        int left = c1 > 0 ? prefix_sum[r2][c1 - 1] : 0;
                        int top_left = r1 > 0 && c1 > 0 ? prefix_sum[r1 - 1][c1 - 1] : 0;
                        int sum = prefix_sum[r2][c2] - top - left + top_left;
                        if(sum == target){
                            count++;
                        }
                    }
                }
            }
        }

        return count;
    }
};
