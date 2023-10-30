class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        multiset<pair<int,int>> st;
        for(auto &x : arr){
            st.insert({__builtin_popcount(x),x});
        }
        vector<int> ans;
        for(auto &[_,x] : st){
            ans.push_back(x);
        }
        return ans;
    }
};