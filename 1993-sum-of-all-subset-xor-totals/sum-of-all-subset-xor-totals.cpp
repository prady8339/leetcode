class Solution {
private:
    int solve(vector<int>& nums,int i,int mask){
        if (i == nums.size()) return mask;
        return solve(nums,i + 1, mask ^ nums[i]) + solve(nums,i + 1,mask);
    } 
public:
    int subsetXORSum(vector<int>& nums) {
        return solve(nums,0,0);
    }
};