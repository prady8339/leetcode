class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // n * n+ 1 / 2 sum of n nums;
        int sum = 0, n = nums.size();
        for(auto &x : nums) sum+=x;
        int shouldBe = (n * (n + 1) ) / 2;
        return shouldBe - sum;
    }
};