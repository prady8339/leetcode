class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for (auto& x : chalk) {
            sum += x;
        }
        k %= sum;
        int idx = 0;
        while (chalk[idx] <= k) {
            k -= chalk[idx];
            idx++;
        }
        return idx;
    }
};