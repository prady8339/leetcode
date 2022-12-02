class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length()) return 0;
        unordered_map<char,int> f1,f2,f3,f4;
        for(auto x:word1){
            f1[x]++;
        }
        for(auto x:word2){
            f2[x]++;
            auto y = f1.find(x);
            if(y==f1.end()) return 0;
        }
        for(auto x=f1.begin() ; x!=f1.end() ; x++){
            f3[x->second]++;
        }
        for(auto x=f2.begin() ; x!=f2.end() ; x++){
            f4[x->second]++;
        }
        for(auto x=f3.begin() ; x!=f3.end() ; x++){
            auto y = f4.find(x->first);
            if(y==f4.end() || y->second!=x->second){
                return 0;
            }
            
        }
        return 1;
    }
};