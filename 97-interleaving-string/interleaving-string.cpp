class Solution {
private:
    bool solve(string &s1, string &s2, string &s3, int n1, int n2, int n3, unordered_map<int, int> &dp) {
        if (n3 < 0) {
            return true;
        }
        
        int key = n1 * 100 + n2  ;  // Create a unique key for memoization
        
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }
        
        bool c1 = false, c2 = false;

        if (n1 >= 0 && s3[n3] == s1[n1]) {
            c1 = solve(s1, s2, s3, n1 - 1, n2, n3 - 1, dp);
        }
        if (n2 >= 0 && s3[n3] == s2[n2]) {
            c2 = solve(s1, s2, s3, n1, n2 - 1, n3 - 1, dp);
        }

        return dp[key] = c1 || c2;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();

        if (n1 + n2 != n3) {
            return false;
        }

        unordered_map<int, int> dp;
        
        return solve(s1, s2, s3, n1 - 1, n2 - 1, n3 - 1, dp);
    }
};
