class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> st;
        for(auto &x: arr){
            st[x]++;
        }
        for(auto &x : arr){
            if(st[x] == 1) k--;
            if(k == 0) return x;
        }
        return "";
    }
};