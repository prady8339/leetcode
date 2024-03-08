class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 1, maxi = 1;
        for(int i = 1; i < nums.size() ; i++){
            int ct = 1;
            while(i < nums.size() && nums[i]==nums[i-1]){
                ct++;
                i++;
            }
            if(ct > maxi){
                count = 1;
                maxi = ct;
            }else if(ct == maxi){
                count++;
            }
        }
        return maxi * count;
    }
};