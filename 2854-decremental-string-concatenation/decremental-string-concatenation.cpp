class Solution {
int solve(char last,char first,vector<string> &words,int i,unordered_map<string,int> &dp){
    if(i >= words.size()){
        return 0;
    }
    int len = words[i].size();
    string key = to_string(i)+ "_" + first+ last;
    if(dp.count(key))
        return dp[key];

    int a = INT_MAX,b = INT_MAX;
    if(words[i].back() == first){
        a = len - 1 + solve(last, words[i][0], words, i + 1, dp);
    }
    else{
        a =  len + solve(last, words[i][0], words, i + 1, dp);
    }

    if(words[i][0] == last){
        b = len - 1 + solve(words[i].back(), first , words, i + 1, dp);
    }
    else{
        b = len + solve(words[i].back(), first, words, i + 1, dp);
    }
    return dp[key] = min(a,b);
}
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        unordered_map<string,int> dp;
        return words[0].size() + solve(words[0].back(),words[0][0] , words, 1, dp);
    }
};