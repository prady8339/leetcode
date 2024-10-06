class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {

        if (s1.size() < s2.size())
            swap(s1, s2);

        vector<string> t1 = splitIntoWords(s1);
        vector<string> t2 = splitIntoWords(s2);

        int i = 0;
        while (i < t2.size() && t1[i] == t2[i]) {
            i++;
        }

        int j1 = t1.size() - 1, j2 = t2.size() - 1;
        while (j2 >= i && t1[j1] == t2[j2]) {
            j1--;
            j2--;
        }

        return j2 < i;
    }

private:
    vector<string> splitIntoWords(const string& s) {
        vector<string> words;
        string word;
        for (char ch : s) {
            if (ch == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word.clear();
                }
            } else {
                word += ch;
            }
        }
        if (!word.empty())
            words.push_back(word);
        return words;
    }
};
