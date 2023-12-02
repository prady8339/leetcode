class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<int,int> freq;
        for(auto &x : chars){
            freq[x]++;
        }
        int sum = 0;
        for(auto &s: words){
            unordered_map<int,int> f;
            for(auto &ch: s){
                f[ch]++;
            }
            bool check = 1;
            for(auto &[k,v] : f){
                if(!freq.count(k) || freq[k] < v){ check = 0; break;}
            }
            if(check){
                sum += s.size();
            }
        }
        return sum;
    }
};