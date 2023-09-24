class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> cups(query_row+1,vector<double> (query_row+1,0));
        
        if(query_row == 0){ 
            return (double) poured > 1 ? 1 : (double) poured;
            }

        cups[0][0] = (double) poured;
        for(int i = 1 ; i <= query_row ;i++){
            for(int j = 0 ; j <= i ; j++){
                 if(j-1>=0 && cups[i-1][j-1]>1){
                    cups[i][j] += (cups[i-1][j-1] - 1) / 2;
                }
                if(cups[i-1][j]>1){
                    cups[i][j] += (cups[i-1][j] - 1) / 2;
                }
                
            }
        }

        if(cups[query_row][query_glass]>1) return 1;
        return cups[query_row][query_glass];
    }
};