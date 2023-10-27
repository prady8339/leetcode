class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,int> dp;
        int mod = 1e9+7;
        int n = arr.size();
        for(auto &x:arr){
            dp[x]=1;
        }
        for(int i = 0 ; i < n ; i++){
            int curr = arr[i];
            for(int j = 0 ; 1 ; j++){
                int prevs = arr[j];
                if(prevs > sqrt(curr)) break;
                long long temp = (long long) dp[prevs] * dp[curr / prevs];
                if(curr % prevs == 0 && dp.count(prevs)){
                    if(curr/prevs==prevs){
                        dp[curr] = (dp[curr] + temp) % mod;
                    }else{
                        dp[curr] = (dp[curr] + temp * 2 ) % mod;
                    }
                }
            }
        }
        int res = 0;
        for(auto &[_,val]:dp){
            res = (res + val) % mod;
        }

        return res;
    }
};
