class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int pos = 0, neg = 0, zer = 0;
        long long sum = 0;
        int mini = INT_MAX;
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[i].size() ; j++){
                mini = min(abs(matrix[i][j]),mini);
                sum += abs(matrix[i][j]);
                if(matrix[i][j]>0) pos++;
                else if(matrix[i][j]<0) neg++;
                else zer++;
            }
        }
        // cout<<mini;
        if(zer || neg%2 == 0) return sum;
        else return sum - 2*mini;
    }
};