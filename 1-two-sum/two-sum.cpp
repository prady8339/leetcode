class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> un;
        int n = nums.size();
        for(int i = 0 ; i < n ;i++){
            un[nums[i]]=i;
        }
        for(int i = 0 ;i < n ;i++){
            if(un.count(target-nums[i]) && i!=un[target-nums[i]]){
                return {i,un[target-nums[i]]};
            }
        }
        return {};
    }
};