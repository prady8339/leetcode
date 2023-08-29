class Solution {

    vector<vector<int>> dirs{{1,0},{-1,0},{0,1},{0,-1}};
private:
    bool solve(vector<vector<char>>& board, string word,vector<vector<bool>>& vis,int i,int j,int k){
        if(k>=word.size()) return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size())
            return false;
        if(vis[i][j]) return false;
        if(board[i][j]!=word[k]) return false;
        vis[i][j] = true;

        bool cal = 0;
        for(auto &dir : dirs){
            int x = i+dir[0];
            int y = j+dir[1];
            if(solve(board,word,vis,x,y,k+1)) return true;
        }

        // bool c1 = solve(board,word,vis,i+1,j,k+1);
        // bool c2 = solve(board,word,vis,i-1,j,k+1);
        // bool c3 = solve(board,word,vis,i,j+1,k+1);
        // bool c4 = solve(board,word,vis,i,j-1,k+1);
        
        vis[i][j] = false;

        return false;

    }
void setvals(vector<vector<bool>>& vis){
    for(int i = 0 ; i< vis.size() ; i++){
        for(int j = 0 ; j < vis[i].size() ; j++){
            vis[i][j]=0;
        }
    }
}
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> vis(board.size(),vector<bool> (board[0].size()));
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[i].size() ;j++){
                setvals(vis);
                if(board[i][j]==word[0]){
                    if(solve(board,word,vis,i,j,0)) return true;
                }
            }
        }
        return false;
    }
};

// 20 mimn