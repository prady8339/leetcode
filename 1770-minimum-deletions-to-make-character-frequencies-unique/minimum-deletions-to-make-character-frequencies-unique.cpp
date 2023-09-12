class Solution {
public:
    int minDeletions(string s) {
        unordered_map<int,int> frequencies;
        unordered_set<int> unique_frequencies;
        int deletions = 0;

        for (char ch : s) {
            frequencies[ch]++;
        }

        for (auto [ch,freq] : frequencies) {
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
