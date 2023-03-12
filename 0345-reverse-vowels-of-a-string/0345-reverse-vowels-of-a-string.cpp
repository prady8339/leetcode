class Solution {
    private:
    bool isVowel(char c){
        if( c=='a' || c=='e' || c =='i' || c == 'o' || c == 'u' || c=='A' || c=='E' || c =='I' || c == 'O' || c == 'U'  ) return 1;
        return 0;
    }
public:
    string reverseVowels(string s) {
        stack<char> st;
        for(auto x:s){
            if(isVowel(x)) st.push(x);
        }
        cout<<st.size();
        for(int i = 0 ; i < s.length() ; i++){
            if(isVowel(s[i])){
                s[i] = st.top();
                st.pop();
            }
        }
        return s;
    }
};