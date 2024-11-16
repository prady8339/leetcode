class Solution {
private:
    bool isValid(vector<int> &nums,int l,int r){
        for(int i = l + 1 ; i < r ; i++){
            if(nums[i] != nums[i - 1] + 1) return false;
        }
        return true;
    }
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1)
            return nums;
        vector<int> res;
        for (int i = 0; i <= nums.size() - k; i++) {
            if (isValid(nums,i, i + k)) {
                res.push_back(nums[i + k - 1]);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }
};