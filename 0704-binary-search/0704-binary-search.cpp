class Solution {
    private:
    int bs(int l,int r,vector<int> &nums,int &t){
        if (l > r) return -1;
        int mid = (l+r)/2;
        if(t<nums[mid]){
           return bs(l,mid-1,nums,t);
        }else if(t>nums[mid]){
           return bs(mid+1,r,nums,t);
        }else{
            return mid;
        } 
    }
public:
    int search(vector<int>& nums, int target) {   
        int n = nums.size();
        if(n==1) return ((nums[0]==target) ? 0 : -1);
       return bs(0,nums.size(),nums,target);
    }
};