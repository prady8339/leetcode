class Solution {
private:
    int solve(vector<int> &nums,int idx,int sz){
        if(idx == nums.size() - 1 )
            if(sz < 2)
                return nums[nums.size()-1] - 1;
            else return 1;

        if(idx >= nums.size()){
            return 0;
        }
        int pick = 1,npick = 1;
        if(sz < 2)
        pick = (nums[idx]-1) * solve(nums,idx + 1, sz + 1);
        npick = solve(nums,idx + 1, sz);

        return max(pick, npick);
    }
public:
    int maxProduct(vector<int>& nums) {
       return solve(nums,0,0);
    }
};