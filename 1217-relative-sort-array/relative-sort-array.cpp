class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp;
        for(auto &x: arr1) mp[x]++;
        vector<int> ans;
        int l = 0;
        for(auto &x: arr2){
            while(mp[x] > 0){
                ans.push_back(x);
                mp[x]--;
            }
        }
        sort(arr1.begin(), arr1.end());
        for(auto &x : arr1){
            if(mp[x] > 0) ans.push_back(x);
        }
        return ans;
    }
};