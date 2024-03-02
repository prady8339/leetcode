class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int mid = 0;
        while( mid < n && nums[mid] < 0) mid++;
        vector<int> ans;
        int l = mid-1;
        int r = mid;
        while(l >= 0 && r < n){
            if(nums[l] * -1  <= nums[r]){
                ans.push_back(nums[l] * nums[l]);
                l--;
            }else{
                ans.push_back(nums[r] * nums[r]);
                r++;
            }
        }
        while( l >= 0){
            ans.push_back(nums[l] * nums[l]);
                l--;
        }
        while( r < n ){
            ans.push_back(nums[r] * nums[r]);
                r++;
        }
        return ans;
    }
};