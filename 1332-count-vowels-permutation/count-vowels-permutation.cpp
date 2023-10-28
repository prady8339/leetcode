class Solution {
private:
    int ways(int idx, char v, unordered_map<char, vector<char>> &cons, vector<unordered_map<char, int>> &dp) {
        if(idx == 1) return 1;
        if(dp[idx].count(v)) return dp[idx][v];
        long long temp = 0;
        for(char next : cons[v]){
            temp = (temp + ways(idx - 1, next, cons, dp)) % (1000000007);
        }
        return dp[idx][v] = temp;
    }
public:
    int countVowelPermutation(int n) {
        if(n == 1) return 5;
        vector<unordered_map<char, int>> dp(n + 1);
        unordered_map<char, vector<char>> cons;
        cons['a'] = {'e'};
        cons['e'] = {'a', 'i'};
        cons['i'] = {'a', 'e', 'o', 'u'};
        cons['o'] = {'i', 'u'};
        cons['u'] = {'a'};
        long long ans = 0;
        for(auto &[v, _] : cons){
            ans = (ans + ways(n, v, cons, dp)) % (1000000007);
        }
        return static_cast<int>(ans);
    }
};
