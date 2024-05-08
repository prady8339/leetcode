class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);
        vector<pair<int,int>> clone;
        for(int i = 0 ; i < score.size() ; i++){
            pair p = {score[i], i};
            clone.push_back(p);
        }
        sort(clone.begin(),clone.end());
        reverse(clone.begin(),clone.end());
        for(int i = 0 ; i < clone.size() ; i++){
            int idx = clone[i].second;
            if(i == 0) ans[idx] = "Gold Medal";
            if(i == 1) ans[idx] = "Silver Medal";
            if(i == 2) ans[idx] = "Bronze Medal";
            if(i > 2)
            ans[idx] = to_string(i + 1);
        }
        return ans;
    }
};