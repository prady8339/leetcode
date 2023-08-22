class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> um;
        for(auto &num : nums){
            um[num]++;
            if(um[num]>1) return true;
        }
        return false;
    }
};