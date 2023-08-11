class Solution {
    // private:
    // bool solve(vector<int> &nums,vector<vector<int>> &dp,int idx,int target){
    //     if(idx>=nums.size() || target<0) return 0;
    //     if(target==0) return 1;
    //     if(dp[idx][target]!=-1) return dp[idx][target];
    //     bool pick = solve(nums,dp,idx+1,target-nums[idx]);
    //     bool npick = solve(nums,dp,idx+1,target);
    //     return dp[idx][target]=(pick)||(npick);
    // }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0,n=nums.size();
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
        }
        if(sum % 2 != 0) return false;

        int target = sum / 2;

    // dfs set dp
    // unordered_set<int> dp;
    //     dp.insert(0);
    //     int target = sum / 2;
        
    //     for(int i=nums.size()-1; i>=0; i--)
    //     {
    //         unordered_set<int> temp;
    //         for(int j: dp)
    //         {
    //             temp.insert(j);
    //             if(j + nums[i] == target) return true;
    //             temp.insert(j + nums[i]);
    //         }
    //         dp=temp;
    //     }
        
    //     return false;

    // bottom up dp
    //   vector<vector<int>> dp(n+1,vector<int> (target+1,-1));
    //    return solve(nums,dp,0,target);

    // top down dp

    vector<vector<int>> dp(n+1,vector<int> (target+1));

   
    for(int j = 0 ; j < target+1 ; j++){
        dp[0][j]=0;
    }
     for(int i = 0 ; i < n+1 ; i++){
        dp[i][0]=1;
    }

    for(int i = 1 ; i < n+1 ; i++){
        for(int j = 1 ; j < target+1 ; j++){
            if(j>=nums[i-1]){
                dp[i][j]=(dp[i-1][j-nums[i-1]])||(dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[n][target];
    }
};