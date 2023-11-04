class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int n = nums.size();
        int curr = 0;
        for(int i = 1 ; i < n ; i++){
            while(i < n && nums[i]-nums[curr] <= k) i++;
            if(i < n) 
            curr = i;
            ans++;
        }
        if(curr == n-1 ) ans++;
        return ans;
    }
};