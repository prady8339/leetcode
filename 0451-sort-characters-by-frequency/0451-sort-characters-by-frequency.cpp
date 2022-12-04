class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> un;
        for(auto &su:s){
            un[su]++;
        }
       map<int, string> mp;
        for(auto v : un) {
            char c = v.first;
            int n = v.second;
            mp[n] += string(n, c);
        }
        
        string res;
        for(auto rit = mp.rbegin(); rit != mp.rend(); ++rit) {
            res += rit->second;
        }
        return res;
        
    }
};