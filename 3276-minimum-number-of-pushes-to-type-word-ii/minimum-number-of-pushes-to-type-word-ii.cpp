class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        for(auto &w : word){
            freq[w - 'a']++;
        }
        sort(freq.rbegin(),freq.rend());
        int it = 1, sum = 0;
        for(int i = 0 ; i < 26 ; i++){
            sum += it * freq[i];
            if((i + 1) % 8 == 0) it++;
        }
        return sum ;
    }
};