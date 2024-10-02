class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       set<int> st(arr.begin(),arr.end());
       unordered_map<int,int> mp;
       int it = 1;
       for(auto &x : st){
        mp[x] = it;
        it++;
       }
       for(auto &x : arr){
        x = mp[x];
       }
       return arr;
    }
};