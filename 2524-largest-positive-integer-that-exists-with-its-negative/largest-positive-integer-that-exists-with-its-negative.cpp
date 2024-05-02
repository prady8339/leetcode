class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> state;
        int ans = -1;
        for(auto &x : nums) state.insert(x);
        for(int i = 0 ; i < nums.size() ; i++){
            if(state.count(nums[i] * -1) && state.count(nums[i])){
                if(abs(nums[i]) > ans) ans = abs(nums[i]);
            }
        }
        return ans;
    }
};