class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(auto &x: nums){
            freq[x]++;
        }
        vector<pair<int,int>> v;
        for(auto &[k,val] : freq){
            v.push_back({val,k});
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        for(int i = v.size() - 1 ; i >=0 && (v.size() - i) <= k ; i--){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};