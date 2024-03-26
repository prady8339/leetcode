class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int,int> mp;
        vector<int> ans;
            for(auto &x:nums){
                mp[x]++;
            }
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second>1) ans.push_back(it->first);
        }
        return ans;
    }
};