class Solution {
private:
    void helper(vector<vector<int>> &ans,vector<int> &nums,vector<int> &ds,vector<bool> &vis){
       
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return ;
        }

        for(int i = 0 ; i < nums.size() ; i++){
            if(!vis[i]){
                ds.push_back(nums[i]);
                vis[i] = 1;
                helper(ans,nums,ds,vis);
                ds.pop_back();
                vis[i] = 0;
            }
        }

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> ds;
        vector<vector<int>> ans;
        vector<bool> vis(n);
        helper(ans,nums,ds,vis);
        return ans;
    }
};