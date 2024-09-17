class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mp;
        string word = "";
        for(int i = 0; i < s1.size() ; i++){
            if(s1[i] == ' '){
                mp[word]++;
                word = "";
                continue;
            }
            word+=s1[i];

        }
        mp[word]++;
        word = "";
        for(int i = 0; i < s2.size() ; i++){
            
            if(s2[i] == ' '){
                mp[word]++;
                word = "";
                continue;
            
            }
            word+=s2[i];
        }
        mp[word]++;
        word = "";
        vector<string> ans;
        for(auto &[k, v]: mp){
            if(v == 1) ans.push_back(k);
        }
        return ans;
            
    }
};