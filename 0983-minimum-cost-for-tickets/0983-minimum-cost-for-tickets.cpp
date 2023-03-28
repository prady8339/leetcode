class Solution {
public:
    int dp[366];
    int f(vector<int> &nums,int ind,vector<int> &cost,int n){
        
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        
        int way1 = cost[0] + f(nums,ind+1,cost,n);
        int tempInd = ind;
        while(tempInd<n && nums[tempInd]-nums[ind]<7){
            tempInd++;
        }
        int way2 = cost[1] + f(nums,tempInd,cost,n);
        tempInd = ind;
        while(tempInd<n && nums[tempInd]-nums[ind]<30){
            tempInd++;
        }
        int way3 = cost[2] + f(nums,tempInd,cost,n);
        return dp[ind] = min(way1,min(way2,way3));
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return f(days,0,costs,days.size());
    }
};