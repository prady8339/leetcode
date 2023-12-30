class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        unordered_map<char,int> freq;
        for(auto &w : words){
            for(auto &c : w){
                freq[c]++;
            }
        }
        for(auto &[k, v] : freq){
            if(v % n != 0) return false;
        }
        return true;
    }
};