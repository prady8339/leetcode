class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> um1,um2;
        for(auto &element : s){
            um1[element]++;
        }
        for(auto &element : t){
            um2[element]++;
        }
        return um1==um2;
    }
};