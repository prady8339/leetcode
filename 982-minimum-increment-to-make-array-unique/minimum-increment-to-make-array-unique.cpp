class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int ans = 0;
       sort(nums.begin(),nums.end()); 
       unordered_map<int,int> mp;
       int mini = INT_MAX,maxi = INT_MIN;
       for(auto &x: nums){ 
        mp[x]++;
        mini = min(mini,x);
        maxi = max(maxi,x);
       }
       for(int i = mini ; i <= maxi ; i++){
            if(mp[i] > 1){
                ans += mp[i] - 1;
                mp[i + 1] += mp[i] - 1;
            }
       }
       if(mp.count(maxi + 1)){
            ans += ((mp[maxi + 1] - 1) * (mp[maxi + 1] )) / 2;
       }
       return ans;
    }
};