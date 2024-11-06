class Solution {
public:
    bool canSortArray(vector<int>& v) {
        int n = v.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                int vb = __builtin_popcount(v[j]);
                int vxb = __builtin_popcount(v[j + 1]);
                if (v[j] > v[j + 1]) {
                    if (vb != vxb)
                        return false;
                    swap(v[j], v[j + 1]);
                }
            }
        }
        return true;
    }
};