class Solution {
private:
    bool isVowel(char &ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        int left = 0, right = 0;
        for(int i = 0 ; i < n ; i++){
            s[i] = tolower(s[i]);
            if(isVowel(s[i])){
                if(i < n/2){
                    left++;
                }else{
                   right++;
                }
            }
            
        }
        return left == right;
    }
};