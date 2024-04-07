class Solution {
public:
    bool checkValidString(string s) {
        stack<pair<char,int>> st;
        stack<int> stars;
        int n = s.size();
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){
                st.push({s[i],i});
                continue;
            }else if(s[i] == ')'){
                if(st.empty() || st.top().first == ')'){
                    st.push({s[i],i});
                }else{
                    st.pop();
                }
            }else{
                stars.push(i);
            }
        }
        if(st.size() == 0) return true;
        if(st.size() > stars.size()) return false;

        while(!st.empty() && !stars.empty()){
            int starIdx = stars.top();
            auto x = st.top();
            bool c1 = x.first == '(' && starIdx > x.second ;
            bool c2 = x.first == ')' && starIdx < x.second ;
            if(c1 || c2) {
                st.pop();
                stars.pop();
                continue;
            }
            stars.pop();
        }
        return st.empty();
        

    }
};