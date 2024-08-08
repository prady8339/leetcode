class Solution {

private:
    bool valid(int row,int col,int r,int c){
        if(r < 0 || r >= row || c < 0 || c >= col) return false;
        return true;
    }
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int total = rows * cols;

        vector<vector<int>> ans;

        int x = 0;
        int y = 1;

        int r = rStart;
        int c = cStart;

        int aukat = 1;
        int round = 0;

        while(ans.size() != total){
            for(int i = 0 ; i < aukat ; i++){
                if(valid(rows,cols,r,c)) ans.push_back({r,c});
                r+=x; c+=y;
            }
            if(x == 1){ x = 0; y = -1; }
            else if(y == -1) { x = -1; y = 0; }
            else if(x == -1){ y = 1; x = 0; }
            else if(y == 1) { y = 0; x = 1; }
            round++;
            if(round % 2 == 0) aukat++;
        }
        return ans;
    }
};


// x+
// y-
// x-
// y+
