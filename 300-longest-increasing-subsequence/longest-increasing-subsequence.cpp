class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp = {nums[0]};
        int ans = 1, n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(nums[i] > temp.back()){
                ans++;
                temp.push_back(nums[i]);
            }else{
                auto it = lower_bound(temp.begin(),temp.end(),nums[i]);
                *it = nums[i];
            }
        }
        return ans;
    }
};