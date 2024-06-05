class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
       int n = words.size();
       vector<int> freq1(26,0),freq2(26,0);

       for(auto &c : words[0]){
        freq1[c - 'a']++;
       }
        
       for(auto &w : words){
        for(auto &c : w){
           freq2[c - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(freq1[i] != freq2[i]){
                freq1[i] = min(freq1[i],freq2[i]);
            }
            freq2[i] = 0;
        }
       } 
    vector<string> ans;
    for(int i = 0 ; i < 26 ; i++){
        while(freq1[i] > 0){
            char ch = i + 'a';
            string s(1,ch);
            ans.push_back(s);
            freq1[i]--;
        }
    }
    return ans;
    }
};