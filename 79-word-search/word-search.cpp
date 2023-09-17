class Solution {
private:
    vector<vector<int>> dirs{{1,0},{-1,0},{0,1},{0,-1}};
    bool check(vector<vector<char>>& board, string &word,int idx,int i,int j){
        int n = board.size();
        int m = board[0].size();
        if(idx>=word.size()) return true;
        if(i >= n || i<0 || j >= m || j < 0) return false;
        if(board[i][j] != word[idx]) return false;
        if(board[i][j]=='#') return false;

        bool ans = false;
        for(auto &dir : dirs){
            char preserve = board[i][j];
            board[i][j] = '#';
            ans = ans | check(board,word,idx+1,i+dir[0],j+dir[1]);
            board[i][j] = preserve;
        }
        return ans;
    }
public: 
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(word[0]==board[i][j]){
                    if(check(board,word,0,i,j)) return true;
                }
            }
        }
        
        return false;
    }
};