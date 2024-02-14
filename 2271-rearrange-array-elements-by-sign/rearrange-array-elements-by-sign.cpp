class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> pos,neg;
        for(auto &x : nums){
            if(x > 0) pos.push(x);
            else neg.push(x);
        }
        for(int i = 0 ; i < nums.size() ; i+=2){
            nums[i] = pos.front();
            nums[i+1] = neg.front();
            pos.pop();
            neg.pop();
        }
        return nums;
    }
};