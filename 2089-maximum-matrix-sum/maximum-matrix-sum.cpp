class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int n = matrix.size(), m = matrix[0].size();
        int neg = 0,zero = 0,mini = INT_MAX;
        for(int i= 0; i < n ; i++){
            for(int j = 0; j < m ; j++){
                int val = matrix[i][j];
                if(val < 0) {
                    neg++;
                    val *= -1;
                }else if(val == 0){
                    zero++;
                }
                mini = min(val, mini);
                sum += val; 
            }
        }
        if(zero > 0 || neg % 2 == 0) return sum;
        return sum - 2 * mini;
    }
};