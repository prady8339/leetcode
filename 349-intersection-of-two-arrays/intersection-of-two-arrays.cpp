class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> un;
        for(auto &x : nums1){
            if(un.count(x)) continue;
            else un[x]++;
        }
        for(auto &x : nums2){
            if(un[x]==1) un[x]++;
        }
        vector<int> ans;
        for(auto &[k, f]: un){
            if(f == 2) ans.push_back(k);
        }
        return ans;
    }
};