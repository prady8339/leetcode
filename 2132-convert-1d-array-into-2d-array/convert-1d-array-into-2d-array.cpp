class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
       int sz = original.size();
        if(n * m != sz) return {};
        vector<vector<int>> ans;
        vector<int> t;
        for(int i = 0 ; i < sz ; i++){
            t.push_back(original[i]);
            if((i + 1 ) % n == 0){
                ans.push_back(t);
                t.clear();
            }
        }
        if(t.size() > 0)
        ans.push_back(t);

        return ans;
    }
};