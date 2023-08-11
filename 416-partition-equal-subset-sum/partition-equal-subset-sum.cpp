class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
        }
        if(sum % 2 != 0) return false;
        set<int> dp;
        dp.insert(0);
        int target = sum / 2;
        
        for(int i=nums.size()-1; i>=0; i--)
        {
            set<int> temp;
            for(int j: dp)
            {
                temp.insert(j);
                if(j + nums[i] == target) return true;
                temp.insert(j + nums[i]);
            }
            dp=temp;
        }
        
        return false;
    }
};