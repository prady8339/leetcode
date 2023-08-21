class Solution {
bool checkSubseq(char c,vector<vector<int>> &alpha_idx,int &last_idx){
    auto search_idx = upper_bound(alpha_idx[c-'a'].begin(),alpha_idx[c-'a'].end(),last_idx);
    if(search_idx == alpha_idx[c-'a'].end()){
        return false;
    }
    last_idx = *search_idx;
    return true;
    // for(auto search_idx : alpha_idx[c-'a']){
    //     int idx = (int) search_idx;
    //     if(idx > last_idx){
    //         last_idx = idx;
    //         return true;
    //     }
    // }
    // return false;
}
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> alpha_idx(26);
        int count = 0;
        for(int i = 0 ;i < s.size() ; i++) 
        alpha_idx[s[i]-'a'].push_back(i);

        for(auto &word : words){
            int last_idx = -1;
            int char_count = 0;
            for(auto c : word){
                if(checkSubseq(c,alpha_idx,last_idx)) char_count++;
                else break;
            }
            if(char_count==word.size()) count++;
        }
        
        return count;

    }
};