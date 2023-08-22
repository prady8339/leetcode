class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> um;
        for(auto &element : s){
            um[element]++;
        }
        for(auto &element : t){
            um[element]--;
        }
        for(auto &it : um){
            if(it.second != 0 ) return false;
        }
        return true;
    }
};