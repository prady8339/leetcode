class Solution {
    int mod = 1e9 + 7;

    // long long fact(int n) {
    //     long long result = 1LL;
    //     for (int i = 1; i <= n; ++i) {
    //         result = (result * i) % mod;
    //     }
    //     return result;
    // }

    // long long pow(int n) {
    //     long long result = 1LL;
    //     for (int i = 0; i < n; ++i) {
    //         result = (result * 2) % mod;
    //     }
    //     return result;
    // }

public:
    int countOrders(int n) {
        long long count = 1;
        for (int i = 2; i <= n; ++i) {
            count = (count * (2 * i - 1) * i) % mod;
        }
        return (int)count;
    }
};
