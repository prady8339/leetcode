class Solution {
private:
bool isSubseq(string &a,string &b){
    //a is small 
    int l = 0 , r = 0;
    while(l < a.size() && r < b.size()){
        if(a[l]==b[r]){
            l++;
        }
        r++;
    }
    return l==a.size();
}
int solve(unordered_map<int,vector<string>> &ds,unordered_map<string,int> &dp,int sz,string word){
    if(sz<=0) return 0;
    int res = 0;

    if(dp.count(word)) return dp[word];
   
    for(auto &a:ds[sz-1]){
        if(isSubseq(a,word)){
            res = max(res,solve(ds,dp,sz-1,a));
        }
    }
    
    return dp[word] = res+1;
}
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<int,vector<string>> ds;
  
        for(int i = 0 ; i < words.size() ; i++){
            ds[words[i].size()].push_back(words[i]);
        }
        
        unordered_map<string,int> dp;
        int maxi = 0;
        
        for(auto &word:words){
            int temp = solve(ds,dp,word.size(),word);
            maxi = max(temp,maxi);
        }
        
        return maxi;
    }
};

