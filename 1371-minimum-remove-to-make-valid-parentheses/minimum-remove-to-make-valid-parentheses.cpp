class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> st;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '('){
                st.push({s[i],i});
            }else if(s[i] == ')'){
                if(st.empty() || st.top().first == ')'){
                    st.push({s[i],i});
                }else{
                    st.pop();
                }
            }
        }
        string ans;
        unordered_set<int> rm;
        while(!st.empty()){
            rm.insert(st.top().second);
            st.pop();
        }
        for(int i = 0 ; i < s.size() ; i++){
            if(rm.count(i)) continue;
            ans+=s[i];
        }
        return ans;
    }
};