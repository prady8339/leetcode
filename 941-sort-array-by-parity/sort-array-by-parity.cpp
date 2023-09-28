class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> eve,odd;
        for(int i = 0 ;i < nums.size() ; i++){
            if(nums[i]&1){
                odd.push_back(nums[i]);
            }else{
                eve.push_back(nums[i]);
            }
        }
        int j = 0,k = 0;
        while(j<eve.size()){
            nums[j]=eve[j];
            j++;
        }
        while(k<odd.size()){
            nums[j+k]=odd[k];
            k++;
        }
        return nums;
    }
};