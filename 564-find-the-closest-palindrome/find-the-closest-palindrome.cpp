class Solution {
public:
    long long c(long long& n) {
        string s = to_string(n);
        int l = (s.size() - 1) / 2, r = s.size() / 2;
        while (l >= 0) s[r++] = s[l--];
        return stoll(s);
    }
    long long p(long long n) {
        long long l = 0, r = n, a = LLONG_MIN;
        while (l <= r) {
            long long m = (r - l) / 2 + l, t = c(m);
            if (t < n) a = t, l = m + 1;
            else r = m - 1;
        }
        return a;
    }
    long long q(long long n) {
        long long l = n, r = 1e18, a = LLONG_MIN;
        while (l <= r) {
            long long m = (r - l) / 2 + l, t = c(m);
            if (t > n) a = t, r = m - 1;
            else l = m + 1;
        }
        return a;
    }
    string nearestPalindromic(string n) {
        long long x = stoll(n), a = p(x), b = q(x);
        return abs(a - x) <= abs(b - x) ? to_string(a) : to_string(b);
    }
};
