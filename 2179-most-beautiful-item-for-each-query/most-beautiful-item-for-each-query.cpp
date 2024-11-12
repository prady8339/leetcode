class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        int n = items.size();
        sort(items.begin(), items.end());
        vector<int> ans;
        vector<int> pref(n, 0);
        int prev = 0, it = 0;
        for (auto& v : items) {
            int price = v[0];
            int beauty = v[1];
            prev = max(prev, beauty);
            pref[it++] = prev;
        }
        for (auto& q : queries) {
            auto idx =
                upper_bound(items.begin(), items.end(), vector<int>{q, 0},
                            [](const vector<int>& a, const vector<int>& b) {
                                return a[0] < b[0];
                            });

            if (idx != items.begin()) {
                idx--;
                int pos = distance(items.begin(), idx);
                ans.push_back(pref[pos]);
            } else {
                ans.push_back(0);
            }
        }
        return ans;
    }
};