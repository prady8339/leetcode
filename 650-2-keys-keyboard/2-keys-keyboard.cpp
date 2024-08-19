class Solution {
public:
    int minSteps(int n) {
        int res = 0;
        int d = 2;
        while (n > 1) {
            if ((n % d) == 0) {
                res += d;
                n /= d;
            } else {
                d++;
            }
        }
        return res;
    }
};
