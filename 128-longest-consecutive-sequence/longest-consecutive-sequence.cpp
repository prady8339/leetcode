class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(auto x:nums) st.insert(x);
        int maxi = 0;
        for(auto x:nums){
            if(!st.count(x-1)){
                int temp = x,ct=0;
                while(st.count(temp)){
                    ct++;
                    temp++;
                }
                maxi = max(maxi,ct);
            }
        }
        return maxi;
    }
};