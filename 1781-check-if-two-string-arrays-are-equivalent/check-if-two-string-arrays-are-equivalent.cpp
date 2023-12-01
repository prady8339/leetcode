class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
       string s1,s2;
       for(auto &strs : word1){
           for(auto &ch : strs){
               s1+= ch;
           }
       }
       for(auto &strs : word2){
           for(auto &ch : strs){
               s2+= ch;
           }
       }
       return s1 == s2;
    }
};