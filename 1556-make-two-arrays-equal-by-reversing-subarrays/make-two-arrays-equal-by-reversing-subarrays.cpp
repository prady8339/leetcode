class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> um;
        for(auto &x : target) um[x]++;
        for(auto &x: arr) um[x]--;
        for(auto &[k,v] : um){
            if(v != 0) return false;
        }
        return true;
    }
};