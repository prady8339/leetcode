class Solution {
private:
    void helper(vector<vector<int>> &ans,vector<int> &nums,vector<int> &ds,unordered_map<int,int> &um){
        
            if(ds.size() == nums.size()){
                ans.push_back(ds);
                return ;
            }
            
            for(auto &x:um){
                if(um[x.first] > 0){
                    ds.push_back(x.first);
                    um[x.first]--;
                    helper(ans,nums,ds,um);
                    ds.pop_back();
                    um[x.first]++;
                }
            }


        }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int> ds;
        vector<vector<int>> ans;
        unordered_map<int,int> um;
        for(auto &x:nums) um[x]++;

        helper(ans,nums,ds,um);
        return ans;
    }
};