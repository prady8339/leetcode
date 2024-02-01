class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        // mergeSort(nums,0, n - 1);
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> v;
        for(int i = 0 ; i < n ; i++){
            if(v.size() == 0){
                v.push_back(nums[i]);
            }else if(nums[i] - v[0] <= k){
                v.push_back(nums[i]);
                if(v.size() == 3){
                    ans.push_back(v);
                    v.clear();
                }
            }else{
                return {};
            }
        }
        return ans;
    }
};