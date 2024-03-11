class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> v(26,0);
        for(int i = 0 ; i < s.size() ; i++){
            v[ s[i] - 'a' ]++;
        }
        string ans;
        for(auto &x : order){
            int ct = v[ x - 'a'];
            while(ct){
                ans.push_back(x);
                ct--;
            }
            v[ x - 'a'] = 0;
        }
        for(int i = 0 ; i < 26; i++){
            if(v[i] > 0){
                int ct = v[i];
                while(ct){
                    ans.push_back('a' + i);
                    ct--;
                }
                v[i] = 0;
            }
        }
        return ans;
    }
};