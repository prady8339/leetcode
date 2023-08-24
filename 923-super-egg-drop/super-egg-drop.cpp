class Solution {
private:
    int solve(int e, int f, vector<vector<int>> &dp) {
        if (f == 0 || f == 1)
            return f;

        if (e == 1)
            return f;

        if (dp[e][f] != -1)
            return dp[e][f];

        int mini = 1e9;

        int low = 1, high = f;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int left = solve(e - 1, mid - 1, dp); 
            int right = solve(e, f - mid, dp);
            int temp = 1 + max(left, right);
            
            if (left < right) {
                 low = mid + 1;
            } else {
                high = mid - 1;

            }
            mini = min(temp,mini);
        }

        return dp[e][f] = mini;
    }

public:
    int superEggDrop(int e, int f) {
        vector<vector<int>> dp(e + 1, vector<int>(f + 1, -1));
        return solve(e, f, dp);
    }
};
