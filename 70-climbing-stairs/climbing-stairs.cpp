class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n; // There are n ways for n=1 and 2 ways for n=2
        }
        
        int prev1 = 1, prev2 = 2;
        for (int i = 3; i <= n; ++i) {
            int temp = prev2;
            prev2 = prev1 + prev2;
            prev1 = temp;
        }
        
        return prev2;
    }
};