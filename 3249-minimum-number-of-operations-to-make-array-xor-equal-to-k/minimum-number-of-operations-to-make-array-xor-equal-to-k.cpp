class Solution {

public:
    int minOperations(vector<int>& nums, int k) {
        int sumXor = k;
        for(auto &x : nums) sumXor ^= x;
        return __builtin_popcount(sumXor);;
    }
};