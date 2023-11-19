class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int prev = nums[0];
        int ct = 0;
        int factor = 0;
        int ans = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] != prev){
                ans += ct * factor;
                factor++;
                ct = 0;
            } 
            ct++;
            prev  = nums[i];
        }
        ans += ct * factor;
        return ans;
    }
};