class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        if (folder.size() <= 1)
            return folder;
        vector<string> res;
        unordered_set<string> st;
        for (int i = 0; i < folder.size(); i++) {
            string maker = "";
            bool toAdd = true;
            for(int j = 0 ; j < folder[i].size() ; j++){
                if(folder[i][j] == '/' && st.count(maker)){
                    toAdd = false;
                    break;
                }
                maker += folder[i][j];
            }
            if(toAdd){
                st.insert(folder[i]);
                res.push_back(folder[i]);
            }
        }
        return res;
    }
};