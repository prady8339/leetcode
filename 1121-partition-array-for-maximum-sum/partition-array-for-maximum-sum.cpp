class Solution {
private:
    int solve(vector<int> &arr,int i,int k,vector<int> &memo){
        int n = arr.size();
        if(i >= n){
            return 0;
        }
        if(memo[i] != -1) return memo[i];
        int curr_max = 0;
        int res = 0;
        for(int j = i ;j < n && j < i + k ; j++){
            curr_max = max(curr_max , arr[j]);
            int ws = j - i + 1;
            res = max(res,
                curr_max * ws + solve(arr,j + 1, k, memo)
            );
        }
        return memo[i] = res;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> memo(n, -1);
        return solve(arr,0,k,memo);
    }
};