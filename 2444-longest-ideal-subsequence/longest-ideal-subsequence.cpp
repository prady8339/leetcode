class Solution {
public:
int longestIdealString(string s, int k) {
        vector<int> dp(27, 0); 
        int n = s.size();
        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];
            int idx = c - 'a';
            int maxi = 0;

            int left = max(idx - k, 0);
            int right = min(idx + k, 26);

            for (int j = left; j <= right; j++) {
                maxi = max(maxi, dp[j]);
            }

            dp[idx] = maxi + 1;
        }

        return *max_element(dp.begin(), dp.end());
    }
};