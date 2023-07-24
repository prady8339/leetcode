class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> un;
        int ct = 0;
        for(auto i:nums1){
            for(auto j:nums2){
                un[i+j]++;
            }
        }
        
        for(auto k:nums3){
            for(auto l:nums4){
                if(un.count(-(k+l))) ct+=un[-(k+l)];
            }
        }
        return ct;
    }
};