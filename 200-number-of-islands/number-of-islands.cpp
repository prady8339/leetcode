class Solution {
private:
    void travel(unordered_set<string> &us,vector<vector<char>> &grid,int i,int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()) return ;

        string key = to_string(i)+"_"+to_string(j);

        if(!us.count(key) && grid[i][j]=='1'){
            us.insert(key);
            travel(us,grid,i+1,j);
            travel(us,grid,i-1,j);
            travel(us,grid,i,j+1);
            travel(us,grid,i,j-1);
        }else{
            return ;
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        unordered_set<string> us;
        int ans = 0;
        for(int i  = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                string key = to_string(i)+"_"+to_string(j);
                if(!us.count(key) && grid[i][j]=='1'){
                    travel(us,grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};