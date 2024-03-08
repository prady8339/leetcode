class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        int maxi = 0,count = 0;;
        for(auto &x : nums){
            freq[x]++;
            maxi = max(freq[x],maxi);
        }
        for(auto &[_,f] : freq){
            if(f == maxi) count += f;
        }
        return count;
    }
};