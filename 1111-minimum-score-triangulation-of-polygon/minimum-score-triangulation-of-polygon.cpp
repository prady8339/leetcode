class Solution {
private:
    int solve(vector<int> &values,int i,int j,vector<vector<int>> &dp){
        if(i >= j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int mini = INT_MAX;
        for(int k = i ; k < j ; k++){
            int temp_ans = solve(values,i,k,dp) + solve(values,k+1,j,dp) + values[i-1] * values[k] * values[j];
            mini = min(temp_ans,mini);
        }
        
        return dp[i][j] = mini;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp( n+1 , vector<int> (n+1,-1));
        return solve(values,1,n-1,dp);
    }
};