class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long total = 0,n=nums.size();
        for(auto x:nums){
            total+=x;
        }
         long long left = 0,right = total,avg = total,ans = 0;
        for(int i = 0 ; i < n ; i++){
            int localAvg = 0;
           left += nums[i];
           right = total - left;
            if(n-i-1>0)
           localAvg = left/(i+1) - right/(n-i-1);
            else
                localAvg = left/(i+1);
            if(localAvg<0){ 
                localAvg*=-1;
            }
            if(localAvg<avg) {
                avg=localAvg;
                ans = i;             
                             }
        }
        return ans;
    }
};