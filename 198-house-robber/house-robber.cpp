class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int r1 = 0, r2 = 0;
        for(int i = 0 ; i < n ; i++){
            int curr = max( r1, nums[i] + r2);
            r2 = r1;
            r1 = curr;
        }
        return r1;
    }
};