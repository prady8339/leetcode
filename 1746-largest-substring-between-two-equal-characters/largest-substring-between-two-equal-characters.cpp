class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<int,int> un;
        int ans = -1;
        for(int i = 0 ; i < s.size() ; i++){
            if(un.count(s[i])){
                ans = max(ans,i-un[s[i]]-1);
                continue;
            }
            un[s[i]] = i;
        }
        return ans;
    }
};