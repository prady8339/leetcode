class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
       vector<int> pref(n,0); 
       pref[0] = arr[0];
       for(int i = 1; i < n ; i++){
        pref[i] = arr[i] ^ pref[i-1];
       }
       vector<int> ans;
       for(auto &q : queries){
        int l = q[0];
        int r = q[1];
        if(l > 0){
            ans.push_back(pref[l - 1] ^ pref[r]);
        }else{
            ans.push_back(pref[r]);
        }
       }
       return ans;
    }
};