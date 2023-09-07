class Solution {
private:
    void solve(vector<vector<int>> &ans,vector<int> &nums,vector<int> &ds,int idx){
        if(idx>=nums.size()){
            ans.push_back(ds);
            return ;
        }
   
            solve(ans,nums,ds,idx+1);
            ds.push_back(nums[idx]);
            solve(ans,nums,ds,idx+1);
            ds.pop_back();
   
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(ans,nums,ds,0);
        return ans;
    }
};