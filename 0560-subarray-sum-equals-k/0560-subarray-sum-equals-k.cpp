class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ct = 0;
        int psum = 0;
        unordered_map<int,int> un;
        un[0]++;
        for(auto x:nums){
            psum+=x;
            if(un.count(psum-k)){
                ct+=un[psum-k];
            }
            un[psum]++;
        }
        return ct;
    }
};
