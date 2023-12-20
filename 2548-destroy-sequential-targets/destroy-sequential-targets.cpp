class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int,pair<int,int>> mp;
        for(auto &x : nums){
            int curr = x % space;
            if(mp.count(curr))
                mp[curr] = { min(mp[curr].first, x), mp[curr].second + 1 };
            else
                mp[curr] = { x , 1};
        }
        int maxi = -1;
        for(auto &[key, p] : mp){
            if(p.second > maxi){
                maxi = p.second;
            }
        }
        int ans = INT_MAX;
        for(auto &[key, p] : mp){
            if(p.second != maxi) continue;
            ans = min(p.first, ans);
        }
        return ans;
    }
};