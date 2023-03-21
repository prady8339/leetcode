class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
       unsigned long long ans=0;
       int n = nums.size();
        stack<long long> st;
        long long ct = 0;
        for(int i = 0 ;i < n ; i++){
            while(i<n && nums[i]==0){
                
                ct++;
                i++;
            }
            //cout<<ct<<endl;
            if(i<n && nums[i]!=0 && ct!=0){
            st.push(ct);
            ct = 0;
            }
        }
         
        if(ct!=0) st.push(ct);
        ct = 0;
       // cout<<st.size();
        while(!st.empty()){
            ans += st.top()*(st.top()+1)/2;
            st.pop();
        }
        
        return ans;
    }
};