class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> un;
        vector<vector<int>> res;
        for(auto &x : nums) un[x]++;
        int i = 0;
        while(i < nums.size()){
            vector<int> vec;
            for(auto &[k, v]: un){
                v--;
                if(v>=0) 
                    vec.push_back(k);
            }
            i+= vec.size();
            res.push_back(vec);
        }
        return res;
    }
};