class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0) return target==0;
        if(n==1) return target==nums[0] || target== -1*nums[0];
        int sum = 0;
        for (auto x : nums) sum += x;

        if(target > sum  || target < -sum) return 0;
        
        if((sum+target) % 2 != 0) return 0;

        int req = (sum + target) / 2;

        vector<vector<int>> dp(n + 1, vector<int>(req + 1));
        dp[0][0] = 1;

        for (int i = 1; i < n + 1; i++) {
            for (int j = 0; j < req + 1; j++) {
                dp[i][j] = dp[i - 1][j];  // Initialize with previous value

                if (j - nums[i - 1] >= 0) {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]]; // Update with adding current number
                }

            }
        }

        return dp[n][req];
    }
};
