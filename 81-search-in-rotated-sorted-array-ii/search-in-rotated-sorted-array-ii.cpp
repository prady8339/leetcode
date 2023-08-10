class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0,end = nums.size()-1;
        while(start<=end){
            int mid = start+(end-start)/2;

            if(nums[mid]==target) return true;
            else if(nums[mid]==nums[start] && nums[start]==nums[end]) {
                start=start+1; 
                continue;
            }
            else if(nums[mid]>=nums[start]){
                // 1st part sorted
                if(target>=nums[start] && target<=nums[mid]){
                   end=mid-1;
                }else{
                   start=mid+1;
                }
            }else{
                //second part sorted
                if( target >= nums[mid] && target <= nums[end] ){
                    start=mid+1;
                }else{
                    end=mid-1;
                }        
            }
        }
        return 0;
    }
};