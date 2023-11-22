class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int,vector<int>> ds;
        for(int i= 0 ; i < nums.size() ; i++){
            for(int j = 0 ; j < nums[i].size() ; j++){
                ds[i+j].push_back(nums[i][j]);
            }
        }
        vector<int> ans;
        for(auto &[key, dia] : ds){
            reverse(dia.begin(),dia.end());
            for(auto &x : dia)
                ans.push_back(x);
        }
        return ans;
    }
};