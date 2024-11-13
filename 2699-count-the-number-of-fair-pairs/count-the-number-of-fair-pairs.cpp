class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {

        // 0 1 4 4 5 7
        // 3 6
        // if(x > lower) continue
        // min req find -> lower - x = 3; lower_bound()
        // max req find -> upper - x = 6; upper_bound() - 1;
        // ans += maxIdx - minIdx
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int i = 0;
        for(auto &x: nums){
            auto mini = lower_bound(nums.begin(), nums.begin() + i, lower - x);
            auto maxi = upper_bound(nums.begin(), nums.begin() + i, upper - x);
            int dist = distance(mini, maxi);
            i++;
            ans += dist;
        }
        return ans;
    }
};