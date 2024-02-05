class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> prev;
        for(int i = 0 ; i < nums.size() ; i++){
            if(prev.count(target - nums[i])){
                return {prev[target - nums[i]], i};
            }
            prev[nums[i]] = i;
        }
        return {};
    }
};