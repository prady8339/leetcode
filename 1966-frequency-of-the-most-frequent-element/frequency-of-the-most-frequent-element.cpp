class Solution {

int solve(vector<int>& nums, int k,int idx){
    int x = nums[idx];
    int ct = 1;
    for(int i = idx-1 ; i >= 0 ; i--){
        if(abs(nums[i]-x) <= k){
            ct++;
            k-=abs(nums[i]-x);
        }else break;
    }
    return ct;
}
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int maxi = 0;
        int n = nums.size();
        int prev = INT_MAX;
        for(int i = n-1 ; i >= 0 ; i--){
            if(prev != nums[i]){
                int res = solve(nums,k,i);
                if(res > maxi){
                    maxi = res;
                }
            }
            prev = nums[i];
        }
        return maxi;
    }
};