class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
       unordered_set<char> st(allowed.begin(),allowed.end());
       int count = 0;
       for(int i = 0 ; i < words.size() ; i++){
        bool f = true;
        for(auto &c : words[i]){
            if(st.count(c)) continue;
            f = false;
        }
        if(f) count++;
       } 
       return count;
    }
};