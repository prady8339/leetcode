class Solution {
unordered_map<int,int> freq;
int solve(vector<int>& nums, int k,int idx){
    int x = nums[idx];
    int ct = 1;
    if(freq.count(x)) return freq[x];
    for(int i = idx-1 ; i >= 0 ; i--){
        if(abs(nums[i]-x) <= k){
            ct++;
            k-=abs(nums[i]-x);
        }else break;
    }
    return freq[x] = ct;
}
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int maxi = 0;
        int n = nums.size();
        for(int i = n-1 ; i >= 0 ; i--){
            int res = solve(nums,k,i);
            if(res > maxi){
                maxi = res;
            }
        }
        return maxi;
    }
};