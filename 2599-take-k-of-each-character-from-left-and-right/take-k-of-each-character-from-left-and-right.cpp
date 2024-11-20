class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> v(3, 0);

        for (auto& x : s)
            v[x - 'a']++;

        auto is_valid = [&]() -> bool { return min({v[0], v[1], v[2]}) >= k; };

        if (!is_valid()) {
            return -1;
        }

        int n = s.size();
        int l = 0, r = 0;
        int ans = 0;
        while (r < n) {
            v[s[r] - 'a']--;
            while (!is_valid()) {
                v[s[l] - 'a']++;
                l++;
            }
            ans = max(ans, (r - l + 1));
            r++;
        }
        return n - ans;
    }
};