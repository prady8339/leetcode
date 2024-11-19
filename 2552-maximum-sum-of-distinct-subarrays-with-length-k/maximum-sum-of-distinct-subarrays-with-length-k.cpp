class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        long long ans = 0;
        long long sum = 0;
        for (int i = 0; i < k; i++) {
            mp[nums[i]]++;
            sum += nums[i];
        }
        if (sum >= ans && mp.size() == k) {
            ans = sum;
        }
        for (int i = k; i < nums.size(); i++) {
            mp[nums[i]]++;
            mp[nums[i - k]]--;
            if (mp[nums[i - k]] <= 0)
                mp.erase(nums[i - k]);
            sum += nums[i];
            sum -= nums[i - k];
            if (sum >= ans && mp.size() == k) {
                ans = sum;
            }
        }
        return ans;
    }
};