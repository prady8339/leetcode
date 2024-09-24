class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
       unordered_set<string> st; 
       for(auto &num: arr1){
        string s = to_string(num);
        string prx;
        for(auto &c : s){
            prx += c;
            st.insert(prx);
        }
       }
       int mxlen = 0;
       for(auto &num: arr2){
        string s = to_string(num);
        string prx;
        for(auto &c : s){
            prx += c;
            if(st.count(prx)){
                int n = prx.size();
                mxlen = max(n, mxlen);
            }
        }
       }
       return mxlen;
    }

};