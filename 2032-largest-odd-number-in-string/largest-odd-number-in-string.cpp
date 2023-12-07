class Solution {
public:
    string largestOddNumber(string num) {
        string ans;
        bool f = 0;
        int n = num.size();
        int i = n-1;
        for( ; i>= 0 ; i--){
            if( (int)(num[i]-'0') % 2 != 0){
                break;
            }
            
        }
        return num.substr(0,i+1);
    }
};