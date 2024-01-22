class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans {0,0};
        unordered_map<int,int> un;
        for(int i = 0; i < nums.size() ; i++){
            un[nums[i]]++;
        }
        for(int i = 0 ; i < nums.size() ; i++){
            if(!un.count(i+1)){
                ans[1] = i+1;
            }else if(un[i+1] == 2){
                ans[0] = i + 1;
            }
        }
        return ans;
    }
};