class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
       int cost = 0;
       int maxlen = 0;
       int l = 0, r = 0, n = s.size();
       while(r < n){
        int diff = abs(s[r] - t[r]);
        if(cost + diff <= maxCost){
            cost += diff;
            r++;
        }else{
            cost -= abs(s[l] - t[l]);
            l++;
        }
        maxlen = max(maxlen, r - l);
       } 
       return maxlen;
    }
};