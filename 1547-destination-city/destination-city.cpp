class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> possible;
        for(auto &e : paths){
            possible.insert(e[1]);
        }
        for(auto &e : paths){
            if(possible.count(e[0]))
                possible.erase(e[0]);
        }
        auto ans = possible.begin();
        return *ans;
    }
};