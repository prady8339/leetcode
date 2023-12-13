class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        unordered_map<int,int> row,col;
        int count = 0;
        for(int i = 0 ; i < mat.size() ; i++){
            for(int j = 0 ; j < mat[i].size() ; j++){
                if(mat[i][j] == 1){
                    row[i]++;
                    col[j]++;
                }
            }
        }

        for(int i = 0 ; i < mat.size() ; i++){
            for(int j = 0 ; j < mat[i].size() ; j++){
                if(mat[i][j] == 1){
                    if(row[i] == 1 && col[j] == 1){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};