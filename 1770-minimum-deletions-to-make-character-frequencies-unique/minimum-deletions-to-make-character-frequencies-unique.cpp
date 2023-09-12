class Solution {
public:
    int minDeletions(string s) {
        int frequency[26] = {0}; //
        unordered_set<int> unique_frequencies;
        int deletions = 0;

        for (char ch : s) {
            frequency[ch - 'a']++; 
        }

        for (int freq : frequency) {
            while (freq > 0 && unique_frequencies.count(freq)) {
                deletions++;
                freq--;
            }

            if (freq > 0) {
                unique_frequencies.insert(freq);
            }
        }

        return deletions;
    }
};
