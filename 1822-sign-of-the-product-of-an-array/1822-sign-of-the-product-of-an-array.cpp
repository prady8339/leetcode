class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ct = 0,z=0;
        for(auto x:nums){ if(x<0) ct++; if(x==0) z = 1; }
        if(z) return 0;
        if(ct%2==0) return 1;
        else return -1;
    }
};