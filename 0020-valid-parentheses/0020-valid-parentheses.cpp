class Solution {  
private:
    bool isMatchingPair(char opening, char closing) {
        return (opening == '(' && closing == ')') || 
               (opening == '{' && closing == '}') ||
               (opening == '[' && closing == ']');
    }
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto x:s){
            if(x=='(' || x=='{' || x=='['){
                st.push(x);
            }
            else{
                if(st.empty() || !isMatchingPair(st.top(), x)) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }

};
