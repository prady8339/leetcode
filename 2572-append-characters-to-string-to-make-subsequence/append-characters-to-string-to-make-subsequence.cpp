class Solution {
public:
    int appendCharacters(string s, string t) {
        int l = 0;
        int i = 0;
        while(i < s.size() && t.size() ){
            if(s[i] == t[l]){
                l++;
            }
            i++;
        }
        return (t.size() - l);
    }
};