class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totalOne = 0;
        for(auto &x : nums) if(x) totalOne++;
        int n = nums.size(), l = 0;
        while(nums.size() != 2 * n) nums.push_back(nums[l++]);
        int ans = totalOne;
        int  r = 0,zc = 0;
        l = 0;
        while(r < totalOne){
            if(nums[r++]);
            else zc++;
        }
        ans = min(zc, ans);
        while(r < 2 * n){
            if(nums[l++]); 
            else zc--;
            if(nums[r++]);
            else zc++;
            ans = min(zc,ans);
        }
        return ans;
    }
};