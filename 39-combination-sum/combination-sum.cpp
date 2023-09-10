class Solution {
private:
    void helper(vector<vector<int>> &ans,vector<int> &nums,vector<int> &ds,int sum,int &target,int i){
        if(i>=nums.size()){
            if(target == sum) ans.push_back(ds);
            return ;
        }
        if(sum>target) return;

        helper(ans,nums,ds,sum,target,i+1);
        ds.push_back(nums[i]);
        helper(ans,nums,ds,sum+nums[i],target,i);
        ds.pop_back();
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        helper(ans,candidates,ds,0,target,0);
        return ans;
    }
};