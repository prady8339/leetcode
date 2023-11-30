class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> groups;
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            groups[nums[i]].push_back(i);
        }

        for (auto &[_, idx_arr] : groups) {
            int l = 0, r = 0;
            int sz = idx_arr.size();
            while(r < sz) {
                while((idx_arr[r] - idx_arr[l]) - (r - l) > k) {
                    l++;
                }
                r++;
                ans = max(ans, r - l);
            }
        }
        return ans;
    }
};