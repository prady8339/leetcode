class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int frontSum = 0, backSum = 0;
        int n = nums.size();
        vector<int> res(n);
        for(auto &num : nums){
            frontSum += num;
        }
      
        for(int i = 0 ; i < nums.size() ; i++){
            res[i] = abs( (nums[i] * (n - i) ) - frontSum);
            res[i] += abs((nums[i] * i) - backSum);
            frontSum -= nums[i];
            backSum += nums[i];
        }
        return res;
    }
};