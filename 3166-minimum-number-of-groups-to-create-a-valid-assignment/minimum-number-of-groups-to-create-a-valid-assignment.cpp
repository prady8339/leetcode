class Solution {
int minGrps(int &x,unordered_map<int,int> &freq){
    int ans = 0;
    if(x <= 0) return INT_MAX;
    for(auto &[_, val]: freq){
        int remainder = val % x;
        int times = val / x;
        if(remainder > times) return INT_MAX;
        ans += ceil((float) val / (x + 1));
    }
    return ans;
}
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto &num : nums){
            freq[num]++; 
        }
        int smallestGrp = INT_MAX;
        for(auto &[key, value]: freq){
            smallestGrp = min(smallestGrp, value);
        }
        int ans = INT_MAX;
        for(int i = 1 ; i <= smallestGrp ; i++){
            ans = min(ans, minGrps(i,freq));
        }
        return ans;
    }
};