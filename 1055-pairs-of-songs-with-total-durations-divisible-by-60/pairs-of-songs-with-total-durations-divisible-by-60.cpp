class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> mp;
        int n = time.size();
        int ct = 0;
        for(int i = 0 ; i < n ; i++){
            int curr = time[i] %  60;
            if(curr == 0 || mp.count(60 - curr)){
                if(curr != 0)
                    ct += mp[60 - curr];
                else 
                    ct += mp[curr];
            }
            mp[curr]++;
        }   
        return ct;
    }
};
// x + curr = 60
// x + curr = 0;
