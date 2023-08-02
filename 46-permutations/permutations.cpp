class Solution {
    void solve(int idx,vector<int> &nums,vector<int> &ds,vector<bool> &check,vector<vector<int>> &ans){
            if(ds.size()==nums.size()){
                ans.push_back(ds);
                return;
            }

            for(int i = idx ; i < nums.size(); i++){
                    if(check[i]){
                      continue;
                    }

                     ds.push_back(nums[i]);
                     check[i]=1;
                     solve(idx,nums,ds,check,ans);  
                     ds.pop_back();
                     check[i]=0;
                    
            }
          
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> ans;
       vector<bool> check(nums.size(),0);
        vector<int> ds; 
        solve(0,nums,ds,check,ans);
        return ans;
    }
};