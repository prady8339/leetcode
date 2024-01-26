class Solution {
vector<vector<int>> dir{{0,1},{1,0},{-1,0},{0,-1}};
unordered_map<string,int> cache;
int MOD = 1e9 + 7;
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if(startRow >= m || startRow < 0 || startColumn >= n || startColumn < 0){
            return 1;
        }
        string key = to_string(startRow) + "_" + to_string(startColumn) + "_" + to_string(maxMove);
        if(cache.count(key)){
            return cache[key];
        }
        int paths = 0;
        for(auto &d : dir){
            if(maxMove > 0)
            paths =( paths + 1LL * findPaths(m, n, maxMove - 1, startRow + d[0], startColumn + d[1])) % MOD;
        }
        return cache[key] = paths;
    }
};