class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ones = "", zeroes = "";
        for(auto &x : s){
            if(x == '0') zeroes += x;
            else ones += x;
        }
        ones.pop_back();
        return ones + zeroes + "1";
    }
};