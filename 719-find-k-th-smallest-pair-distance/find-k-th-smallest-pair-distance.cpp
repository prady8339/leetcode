class Solution {
private:
    int windowSolve(vector<int> &nums, int size){
       int ans = 0;
        int n = nums.size();
        int l = 0;
        for(int r = 0; r < n; r++){
            while(nums[r] - nums[l] > size) l++;
            ans += r - l;
        }
        return ans;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
       int maxi = abs(nums[0] - nums.back());
       int l = 0, r = maxi;
       
       while( l < r){
        int mid = l + (r - l) / 2;

        int res = windowSolve(nums, mid);
        
        if(res < k) l = mid + 1;
        else r = mid;

       }
       return l;
    }
};