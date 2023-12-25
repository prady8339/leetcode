class Solution {

bool valid(string c){
    int len = c.size();
    if(len > 2) return false;
    if((len == 2 || len == 1) && c[0]=='0') return false;
    int t = stoi(c);
    if(t > 0 && t <= 26) return true;
    return false;
}

int solve(string &s,int i,vector<int> &dp){
    if(i == s.size()){
        return 1;
    }

    if(dp[i]!= -1) return dp[i];
    string a = s.substr(i,1);
    string b = s.substr(i,2);

    int oneStep = 0, twoStep = 0;

    if(valid(a)){
        oneStep +=  solve(s, i+1, dp);
    }else{
        // cuz not possible anyhow
        return 0;
    }

    if(valid(b) && i + 1 < s.size()){
        twoStep +=  solve(s, i+2, dp);
    }
    //no else cuz it can be possible using oneStep

    return dp[i] = oneStep + twoStep;
}
public:
    int numDecodings(string s) {
    vector<int> dp(s.length(), -1);
       return solve(s,0,dp);
    }
};