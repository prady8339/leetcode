class Solution {
public:
    string largestOddNumber(string num) {
        string ans;
        bool f = 0;
        int n = num.size();
        for(int i = n-1 ; i>= 0 ; i--){
            if( (int)(num[i]-'0') % 2 != 0){
                f = 1;
            }
            if(f){
                ans.push_back(num[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};