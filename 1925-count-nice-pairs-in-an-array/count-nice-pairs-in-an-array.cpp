class Solution {
private:
    int rev(int n){
        string temp = to_string(n);
        reverse(temp.begin(), temp.end());
        return stoi(temp);
    }
public:
    int countNicePairs(vector<int>& nums) {
        int mod = 1e9 + 7;
        unordered_map<int,int> un;
        for(auto &num : nums){
            un[num - rev(num)]++;
        }
        int ans = 0;
        for(auto &[_, val] : un){
            int pairs = (1ll * val * (val - 1) / 2) % mod;
            ans = (ans + pairs) % mod;
        }
        return ans;
    }
};  