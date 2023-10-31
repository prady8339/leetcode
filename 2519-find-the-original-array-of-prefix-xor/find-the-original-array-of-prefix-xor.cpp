class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans;
        ans.push_back(pref[0]);
        int mask = pref[0];
        for(int i = 1 ; i < pref.size() ; i++){
            ans.push_back(mask ^ pref[i]);
            mask ^= ans[i];
        }
        return ans;
    }
};