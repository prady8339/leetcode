class Solution {
private:
    vector<vector<vector<int>>> dp;
    int solve(vector<int>& jobDifficulty, int idx, int days, int maxDiff) {
        if (idx == jobDifficulty.size()) {
            return days ? 1e5 : 0;
        }
        if(!days) {
            return 1e5;
        }
        maxDiff = max(maxDiff, jobDifficulty[idx]);
        if (dp[idx][days][maxDiff] != -1) {
            return dp[idx][days][maxDiff];
        }
        int finish = maxDiff + solve(jobDifficulty, idx + 1, days - 1, 0);
        int keepGoing = solve(jobDifficulty, idx + 1, days, maxDiff);
        return dp[idx][days][maxDiff] = min(finish, keepGoing);
    }

public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        dp.resize(jobDifficulty.size(), vector<vector<int>>(d + 1, vector<int>(1001, -1)));
        int result = solve(jobDifficulty, 0, d, 0);
        return result >= 1e5 ? -1 : result;
    }
};
