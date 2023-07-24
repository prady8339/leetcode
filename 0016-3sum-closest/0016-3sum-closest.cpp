class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 1e9;
        for(int i = 0 ; i < n ;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j = i+1,k = n-1;
            while(j<k){
                long long sum = nums[i]+nums[j];
                sum+=nums[k];
          
                if(abs(sum-target)<abs(ans-target)){
                    ans = sum;
                }
                
                if (sum > target) {
                    k--;
                } else if (sum < target) {
                    j++;
                } else {
                    return sum;
                }
            }
        }
        return ans;
    }
};