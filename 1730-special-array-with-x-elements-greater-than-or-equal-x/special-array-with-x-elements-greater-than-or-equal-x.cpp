class Solution {
public:
    int specialArray(vector<int>& nums) {
       int freq[1002] = {0};
       int maxi = 0;
       for(int i = 0 ; i < nums.size() ; i++){
        freq[nums[i]]++;
        maxi = max(maxi, nums[i]);
       } 
       for(int i = maxi ; i >= 0 ; i--){
        freq[i] += freq[i + 1];
        if(freq[i] == i) return i;
       }
       return -1;
    }
};