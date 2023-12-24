class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int ans = 0;
        int ct = 1;
        for(int i = 1 ; i < word.size() ; i++){
            if(abs(word[i] - word[i-1]) <= 1){
                ct++;
            }else{
                ans += ct / 2;
                ct = 1;
            }
        }
        ans += ct / 2;
        return ans;
    }
};