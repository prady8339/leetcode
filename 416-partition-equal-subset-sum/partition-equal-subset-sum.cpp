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
            for(int k: dp)
            {
                temp.insert(k);
            }
            
            for(int j: temp)
            {
                if(j + nums[i] == target) return true;
                dp.insert(j + nums[i]);
            }
        }
        
        // for(int i:dp)
        // {
        //     if(i == target) return true;
        // }
        return false;
    }
};