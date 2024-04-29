class Solution {

public:
    int minOperations(vector<int>& nums, int k) {
        int sumXor = 0;
        for(auto &x : nums) sumXor ^= x;
        sumXor ^= k;
        return __builtin_popcount(sumXor);;
    }
};