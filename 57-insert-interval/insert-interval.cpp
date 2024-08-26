class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& ni) {
        int n = intervals.size();
        bool f = false;
        bool merge = false;
        vector<vector<int>> ans;
        
        for (auto& i : intervals) {

            if(!f && (ni[0] < i[0] && ni[1] < i[0])){
                ans.push_back(ni);
                f = true;
            }else if (!f && (ni[0] <= i[1] || ni[1] <= i[0])) {
                i[1] = max(i[1], ni[1]);
                i[0] = min(i[0], ni[0]);
                ans.push_back(i);
                f = true;
                merge = true;
            }

            int last = ans.size() - 1;
            if (merge && ans[last][1] >= i[0]) {
                ans[last][1] = max(ans[last][1], i[1]);
                continue;
            }
            ans.push_back(i);
        }
        if(!f) ans.push_back(ni);

        return ans;
    }
};