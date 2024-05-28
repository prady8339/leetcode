class Solution {
public:
    string makeGood(string s) {
       int n = s.size();
       int diff = abs('A' - 'a');
       unordered_set<int> idxs;
       for(int i = n - 2; i >= 0 ; i--){
        if(abs(s[i] - s[i+1]) == diff){
            idxs.insert(i);
            idxs.insert(i+1);
            i--;
        }
       } 
       if(idxs.size() == 0) return s;
       string ans;
       for(int i = 0; i < n ;i++){
        if(idxs.count(i)) continue;
        ans += s[i];
       }
       return makeGood(ans);
    }
};