class Solution {
private:
    bool isPal(string s){
        int l = 0, r = s.size()-1;
        while(l<r){
            if(s[l]!=s[r]) return 0;
            l++; r--;
        }
        return 1;
    }
public:
    string longestPalindrome(string s) {
           int n = s.size();
           string ans ;
           int maxi = 0;
           for(int i = 0 ; i < n ; i++){
               int l = i, r = i;
               while(r < n && l>=0 && s[l]==s[r]){
                   if(r-l+1 > maxi){
                       maxi = r-l+1;
                       ans = s.substr(l,r-l+1);
                   }
                   l--; r++;

               }
               l=i,r = i+1;
               while(r < n && l>=0 && s[l]==s[r]){
                   if(r-l+1 > maxi){
                       maxi = r-l+1;
                       ans = s.substr(l,r-l+1);
                   }
                    l--; r++;
               }

           }

           return ans;                      
    }
};