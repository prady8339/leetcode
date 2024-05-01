class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx = 0, n = word.size();
        while(idx < n && word[idx] != ch){
            idx++;
        }
        if(idx == n) return word;
        int l = 0;
        while(l < idx){
            swap(word[idx],word[l]);
            idx--;
            l++;
        }
        return word;
    }
};