class Solution {
private:
    bool isValid(vector<int> &q, int d, int n) {
        int sum = 0;
        for(auto &x : q) {
            sum += (x + d - 1) / d;
            if (sum > n) return false; 
        }
        return true;
    }

public:
    int minimizedMaximum(int n, vector<int>& q) {
        int l = 1, r = 1e5; 
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (isValid(q, mid, n)) {
                r = mid; 
            } else {
                l = mid + 1; 
            }
        }
        return l;
    }
};
