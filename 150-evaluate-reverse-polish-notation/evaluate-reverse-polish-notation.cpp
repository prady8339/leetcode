class Solution {
private:
    bool isNum(string &s){
        char c = s[0];
        if(s.size() > 1) return true;
        if(c >= '0' && c <= '9') return true;
        return false;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        int i = 0;
        while(i < n){
            if(isNum(tokens[i])){
                st.push(stoi(tokens[i]));
            }else{
                int t1 = 0, t2 = 0;
                if(!st.empty()){
                    t1 = st.top();
                    st.pop();
                }
                if(!st.empty()){
                    t2 = st.top();
                    st.pop();
                }
                int res ;
                if(tokens[i] == "+"){
                    res = t1 + t2;
                }else if(tokens[i] == "-"){
                    res = t2 - t1;
                }else if(tokens[i] == "*"){
                    res = t1 * t2;
                }else if(tokens[i] == "/"){
                    res = t2 / t1;
                }else {
                    cout<<"some error";
                    break;
                }
                st.push(res);
            }
            i++;
        } 
        if(st.empty()) return 0;
        
        return st.top();

    }
};