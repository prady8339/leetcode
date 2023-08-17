class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<vector<int>> q;
        int m = mat.size(),n = mat[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n));
        vector<pair<int,int>> dirs {{1,0},{0,1},{-1,0},{0,-1}}; 
        auto bounds = [&](int x,int y)->bool{
            return  x>=0 && y>=0 && x<mat.size() && y<mat[0].size();
        };

        for(int i = 0 ; i < m  ;i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j]==0){
                   q.push({i,j,0});
                    vis[i][j] = true;
                }
            }
        }
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            mat[curr[0]][curr[1]] = curr[2];
            for(auto dir:dirs){
                int x = curr[0]+dir.first;
                int y = curr[1]+dir.second;
                if(bounds(x,y) && !vis[x][y]) {
                    vis[x][y] = true;
                    q.push({x,y,curr[2]+1});
                }
            }
        }

        return mat;
    }
};