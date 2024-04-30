class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.size();
        long long count = 0;
        vector<int> freq(1024, 0); 
        freq[0] = 1;
        
        int mask = 0; 
        
        for (int i = 0; i < n; ++i) {
            mask ^= (1 << (word[i] - 'a')); 
            count += freq[mask]; 
            
           
            for (int j = 0; j < 10; ++j) {
                count += freq[mask ^ (1 << j)];
            }
            
            freq[mask]++; 
        }
        
        return count;
    }
};