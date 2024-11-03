class Solution {
public:
    bool rotateString(string g, string s) {
        int n = g.size(), m = s.size();
        if (m != n) return false;
        int j = 0;
        s += s;
        for (int i = 0; i < m * 2; i++) {
            if (j < n && s[i] == g[j]) {
                j++;
            } else {
                if (j == n)
                    return true;
                i -= j;
                j = 0;
            }
        }
        return j == n;
    }
};

// "ceeb bbbacddceeb bbbacdd"
// "bbbacddceeb"
// abcdeabcde
// cdeab
