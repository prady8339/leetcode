class Solution {
private:
    void dfs(vector<vector<int>> &nx, int i, int j){
        int n = nx.size();
        if(i < 0 || i >= n || j < 0 || j >= n || nx[i][j]) return ;

        nx[i][j] = 1;
        dfs(nx, i + 1, j);
        dfs(nx, i - 1, j);
        dfs(nx, i, j + 1);
        dfs(nx, i, j - 1);

        return ;
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int N = n * 3;
        vector<vector<int>> nx(N, vector<int> (N,0)); 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char c = grid[i][j];
                if (c == '/') {
                    nx[i * 3][j * 3 + 2] = 1;
                    nx[i * 3 + 1][j * 3 + 1] = 1;
                    nx[i * 3 + 2][j * 3] = 1;
                } else if (c == '\\') {
                    nx[i * 3][j * 3] = 1;
                    nx[i * 3 + 1][j * 3 + 1] = 1;
                    nx[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }

        int ans = 0;

        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                if(nx[i][j]) continue;
                dfs(nx, i, j);
                ans++;
            }
        }

        return ans;
    }
};