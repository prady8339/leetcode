class Solution {

public:
    int takeCharacters(string s, int k) {
        map<char, int> mp;

        for (auto& x : s)
            mp[x]++;

        auto is_valid = [&]() -> bool {
            return min({mp['a'], mp['b'], mp['c']}) >= k;
        };

        if (!is_valid()) {
            return -1;
        }

        int n = s.size();
        int l = 0, r = 0;
        int ans = 0;
        while (r < n) {
            mp[s[r]]--;
            while (!is_valid()) {
                mp[s[l]]++;
                l++;
            }
            ans = max(ans,(r - l + 1));
            r++;
        }
        return n - ans;
    }
};