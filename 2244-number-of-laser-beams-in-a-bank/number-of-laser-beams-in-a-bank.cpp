class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
         int beam = 0;
         int prev = 0;
         for(auto &b : bank){
             int ct = 0;
             for(auto &ch : b){
                 if(ch == '1') ct++;
             }
             beam += ct * prev;
             if(ct != 0)
             prev = ct;
         }
         return beam;
    }
};