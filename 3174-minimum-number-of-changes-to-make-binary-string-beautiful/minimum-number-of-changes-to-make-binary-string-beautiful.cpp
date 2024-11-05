class Solution {
public:
    int minChanges(string s) {
        int count = 0;
        int ans = 0;
        char prev = 'x';
        for (auto& c : s) {
            if (c == prev) {
                count++;
            } else {
                if (count % 2 != 0) {
                    ans++;
                    count = 2;
                } else {
                    count = 1;
                }
            }
            prev = c;
        }
        if (count % 2 != 0)
            ans++;
        return ans;
    }
};
