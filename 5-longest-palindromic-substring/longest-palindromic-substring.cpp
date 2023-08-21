class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int pal_pos = 0;
        int pal_len = 0;

        for(int i = 0 ; i < n ; i++){
            // expand from middle
            int left = i , right = i;
            //odd length palindrom 
            while(left >= 0 && right < n && s[left]==s[right]){
                if(right - left + 1 > pal_len ){
                    pal_len = right - left + 1;
                    pal_pos = left;
               
                }
                left--; right++;
            }
            //even length palindrom
            left = i , right = i+1;
            while(left >= 0 && right < n && s[left]==s[right]){
                if(right - left + 1 > pal_len ){
                    pal_len = right - left + 1;
                    pal_pos = left;
                }
                left--; right++;
            }
        }
        return s.substr(pal_pos,pal_len);
 
    }
    
};