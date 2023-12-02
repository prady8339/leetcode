class Solution {
    int minGrps(int &grpSz, unordered_map<int, int> &freq) {
        int ans = 0;
        if (grpSz <= 0) return INT_MAX;
        
        for (auto &[_, val] : freq) {
            int remainder = val % grpSz;
            int times = val / grpSz;
            if (remainder > times) return INT_MAX;
            ans += ceil((float)val / (grpSz + 1));
        }
        
        return ans;
    }

public:
    int minGroupsForValidAssignment(vector<int> &nums) {
        unordered_map<int, int> freq;
        int smallestGrp = INT_MAX;
        int ans = INT_MAX;
        
        for (auto &num : nums) freq[num]++;
        
        for (auto &[key, value] : freq) smallestGrp = min(smallestGrp, value);
        
        for (int grpSz = 1; grpSz <= smallestGrp; grpSz++) {
            ans = min(ans, minGrps(grpSz, freq));
        }
        
        return ans;
    }
};
