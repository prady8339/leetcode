class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> store(26,0);
        int ans = 0;
        for(int i = 0 ; i < s.size() ; i++){
            store[s[i] - 'a']++;
            store[t[i] - 'a']--;
        }
        for(auto &x : store){
            if(x > 0){
                ans += x;
            }
        }
        return ans;
    }
};