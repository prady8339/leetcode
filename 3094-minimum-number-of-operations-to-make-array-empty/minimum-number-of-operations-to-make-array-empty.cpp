class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> un;
        for(auto &n : nums) un[n]++;
        int res = 0;
        for(auto &[k, v]: un){
            if(v < 2) return -1;
            else if(v == 2 || v ==3){
                res += 1;
            }else{
                res += v / 3;
                if(v % 3 != 0){
                    res += 1;
                }
            }
        }
        
        return res;
    }
};