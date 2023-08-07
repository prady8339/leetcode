class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
          if(!matrix.size()) return false;

        int n = matrix.size();
        int m = matrix[0].size();

        int l = 0;
        int r=(n*m)-1;

        while(l<=r){
            int mid = l+(r-l)/2;
            if(matrix[mid/m][mid%m]==target){
                return 1;
            }else if(matrix[mid/m][mid%m]<target){
                   l=mid+1;
            }else{
                 r=mid-1;
            }

        }
         return 0;
        
    }
};