class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> pos,neg;
        vector<int> ans;
        for(auto &x : nums){
            if(x > 0) pos.push(x);
            else neg.push(x);
        }
        while(!pos.empty()){
            ans.push_back(pos.front());
            ans.push_back(neg.front());
            pos.pop();
            neg.pop();
        }
        return ans;
    }
};