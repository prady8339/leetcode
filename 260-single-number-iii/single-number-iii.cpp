class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       int mask = 0;
       for(auto &x : nums) mask ^= x;
       int a = 0, b = 0;
       int diffBit = 1;
        while ((mask & diffBit) == 0) {
            diffBit <<= 1;
        }
       for(auto &x : nums){
        if(x  & diffBit ) a ^= x;
        else b ^= x;
       }
       return {a,b}; 
    }
};