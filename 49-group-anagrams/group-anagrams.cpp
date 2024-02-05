class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> ds;
        for(auto &s : strs){
            string key = s;
            sort(key.begin(),key.end());
            ds[key].push_back(s);
        }
        vector<vector<string>> res;
        for(auto &[k, v] : ds){
            vector<string> make;
            for(auto &s : v){
                make.push_back(s);
            }
            res.push_back(make);
        }
        return res;
    }
};