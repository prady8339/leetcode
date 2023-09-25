class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freq(26),freq2(26);
        for(int i = 0 ; i < s.size() ; i++){
            freq[s[i]-'a']++;
        }
        for(int i = 0 ; i < t.size() ; i++){
            freq2[t[i]-'a']++;
        }
        char ans = 'a';
        for(int i = 0 ; i < 26 ; i++){
            if(freq[i]!=freq2[i]){
                ans = i+'a';
                break;
            }
        }
        return ans;
    }
};