class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> f1(26, 0), f2(26, 0);
        if(word1.size() != word2.size()) return false;
        int n = word1.size();
        string a,b;
        for(int i = 0 ; i < n ; i++){
            f1[word1[i] - 'a']++;
            if(f1[word1[i] - 'a'] == 1){
                a.push_back(word1[i]);
            }
            f2[word2[i] - 'a']++;
            if(f2[word2[i] - 'a'] == 1){
                b.push_back(word2[i]);
            }
        }
        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());
        for(int i = 0 ; i < 26 ; i++){
            if(f1[i] != f2[i]){
                return false;
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        // cout<<a<<endl<<b<<endl;
        return a == b;
    }
};