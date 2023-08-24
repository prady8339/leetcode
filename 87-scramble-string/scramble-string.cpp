class Solution {
unordered_map<string,bool> dp;
private:
    bool isScrambleHelper(string s1, string s2, int i) {
        int n = s1.size();

       if(s1.compare(s2) == 0)
       return true;
        //cause if s1[i]==s2[2] it was returned;
       if(n <= 1)
       return false;

        string key = s1;
        key.append("_");
        key.append(s2);
        if(dp.find(key) != dp.end()) return dp[key];
        for (int j = 1; j < i; j++) {
            if ((isScrambleHelper(s1.substr(0, j), s2.substr(0, j), j) &&
                 isScrambleHelper(s1.substr(j), s2.substr(j), i - j)) ||
                (isScrambleHelper(s1.substr(0, j), s2.substr(n - j), j) &&
                 isScrambleHelper(s1.substr(j), s2.substr(0, n - j), i - j))) {
                return dp[key] = true;
            }
        }

        return dp[key] = false;
    }

public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }
        
        if (s1.size() != s2.size()) {
            return false;
        }
        
        return isScrambleHelper(s1, s2, s1.size());
    }
};
