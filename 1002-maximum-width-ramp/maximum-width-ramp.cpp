class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> mono;
        int maxi = nums.back(), n = nums.size();
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] >= maxi) {
                maxi = nums[i];
                mono.push(maxi);
            }
        }
        int ans = 0;
        int l = 0, r = 1;
        cout << mono.size() << endl;
        while (r < n) {
            if (mono.empty())
                break;
            int tp = mono.top();
            if (nums[l] <= tp) {

                ans = max(ans, r - l);
            } else {
                l++;
            }
            if (nums[r] >= tp) {
                mono.pop();
            }
            r++;
        }
        return ans;
    }
};