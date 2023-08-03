class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char, int> charCount;
        int count = 0;

        for (char ch : p) {
            charCount[ch]++;
            
        }
        count = charCount.size();

        int i = 0, j = 0;

        while (j < s.size()) {
            if (j < p.size()) {
                if (charCount.count(s[j])) {
                    charCount[s[j]]--;
                    if (charCount[s[j]] == 0) count--;
                }
                j++;
            } else {
                if (count == 0) ans.push_back(i);

                if (charCount.count(s[i])) {
                    if(charCount[s[i]] == 0) count++;
                    charCount[s[i]]++;
                }

                if (charCount.count(s[j])) {
                    charCount[s[j]]--;
                    if (charCount[s[j]] == 0) count--;
                }

                i++;
                j++;
            }
        }
        if(count==0) ans.push_back(i);

        return ans;
    }
};
