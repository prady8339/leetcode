class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> thatArr;
        int mod = 1e9 + 7;

         for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum = (sum + nums[j]) % mod;
                thatArr.push_back(sum);
            }
        }

        sort(thatArr.begin(),thatArr.end());

        left--;
        int ans = 0;
        for(int i = left ; i < right ; i++){
            ans = (ans + thatArr[i]) % mod;
        }
        return ans;
    }
};