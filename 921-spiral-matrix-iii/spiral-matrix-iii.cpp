class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int r, int c) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        auto valid = [&](int &row,int &col,int &r,int &c) -> bool {
            return !(r < 0 || r >= row || c < 0 || c >= col);
        };

        int total = rows * cols;
        vector<vector<int>> ans;
        int x = 0;
        int y = 1;
        int a = 1;
        int round = 0;

        while(total){
            for(int i = 0 ; i < a ; i++){
                if(valid(rows,cols,r,c)){ ans.push_back({r,c}); total--; }
                r+=x; c+=y;
            }
            if(x == 1){ x = 0; y = -1; }
            else if(y == -1) { x = -1; y = 0; }
            else if(x == -1){ y = 1; x = 0; }
            else if(y == 1) { y = 0; x = 1; }
            round++;
            if(round % 2 == 0) a++;
        }

        return ans;
    }
};
