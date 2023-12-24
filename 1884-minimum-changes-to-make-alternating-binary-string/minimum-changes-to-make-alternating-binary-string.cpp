class Solution {
public:
    int minOperations(string s) {
        int a = 0, b = 0;
        for(auto &c : s){
            (a+b & 1) ? 
               ( c == '1' ? a++ : b++ ) 
            :
               ( c == '0' ? a++ : b++ );
        }
        return min(a, b);
    }
};