class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> un;
        for(auto &x : nums){
            un[x]++;
        }
        for(auto &[k, v]: un){
            if(v >= 2) return true;
        }
        return false;
    }
};