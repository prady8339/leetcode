class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int fidx = -1;
        int lidx = -1;
        int n = nums.size();
        int l = 0, r = n-1;
        while(l <= r){
            int mid = l + (r - l)/2;
            if(nums[mid] < target){
                l = mid + 1;
            }else{
                 if(nums[mid]==target)
                fidx = mid;
                r = mid - 1;
            }
        }
        l = 0 , r = n-1;
        while(l <= r){
            int mid = l + (r - l)/2;
            if(nums[mid] > target){
                r = mid - 1;
            }else{
                if(nums[mid]==target)
                lidx = mid;
                l = mid + 1;
            }
        }
        return {fidx,lidx};
    }
};