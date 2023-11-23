class Solution {
private:
    bool isAP(vector<int>& nums, int start, int end) {
        vector<int> subArray(nums.begin() + start, nums.begin() + end + 1);
        int n = subArray.size();
        if (n <= 1) return true;
        std::sort(subArray.begin(), subArray.end());
        int diff = subArray[1] - subArray[0];
        int prev = subArray[1];
        for (int i = 2; i < n; i++) {
            if (subArray[i] - prev != diff) return false;
            prev = subArray[i];
        }
        return true;
    }

public:
    vector<bool> checkArithmeticSubarrays(std::vector<int>& nums, std::vector<int>& l, std::vector<int>& r) {
        vector<bool> ans;
        int queries = l.size();
        for (int i = 0; i < queries; i++) {
            if (isAP(nums, l[i], r[i])) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};