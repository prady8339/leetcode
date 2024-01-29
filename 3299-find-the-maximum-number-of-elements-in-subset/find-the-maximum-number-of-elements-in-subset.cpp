class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = 0;
        for(auto &x : nums){
            mp[x]++;
            if(x==1) ans++;
        }
        if(ans % 2 == 0) ans--;
        for(auto &[i, freq] : mp){
            int count = 0;
            int k = 1;
            long long key = i;
            while(mp.count((int) key)){
                count++;
                if(mp[(int) key] <= 1 || i== 1){
                    break;
                }
                k *= 2;
                key = pow(i, k);
                if(key > 1e9) break;
            }
            int val = count  * 2 - 1;
            if(val % 2 == 0){
                val++;
            }
            ans = max(ans, val);
        }
        return ans;
    }
};