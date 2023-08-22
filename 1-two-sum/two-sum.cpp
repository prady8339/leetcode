class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> um;

        for(int i = 0 ; i < nums.size() ; i++){
            int ele = target - nums[i];
            if(um.count(ele)){
                if(um[ele]==i) continue;
                return {um[ele],i};
            }
            um[nums[i]] = i;
        }
        return {};
    }
};