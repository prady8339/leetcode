class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            auto mini = lower_bound(nums.begin(), it, lower - *it);
            auto maxi = upper_bound(nums.begin(), it, upper - *it);
            int dist = distance(mini, maxi);
            ans += dist;
        }
        return ans;
    }
};