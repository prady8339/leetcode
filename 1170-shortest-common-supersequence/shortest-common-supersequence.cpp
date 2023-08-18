class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size() , m = str2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1));

        for(int i = 1 ; i < n + 1 ; i++){
            for(int j = 1 ; j < m + 1 ; j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }

        string lcs;
        
        while(n>0 && m>0){
            if(str1[n-1]==str2[m-1]){
                lcs.push_back(str1[n-1]);
                n--; m--;
            }else if(dp[n-1][m] > dp[n][m-1]){
                n--;
            }else {
                m--;
            }
        }
        
        reverse(lcs.begin(),lcs.end());
        n = str1.size() , m = str2.size();
        string superseq;
        int i = 0,j=0,k=0;

        while(k<lcs.size() && i<n && j<m){
            if(lcs[k]==str1[i] && lcs[k]==str2[j]){
                superseq.push_back(lcs[k++]);
                i++; j++;
            }
            else if(lcs[k]!=str1[i]){
                superseq.push_back(str1[i++]);
            }else{
                superseq.push_back(str2[j++]);
            }
        }

        while(i<n) superseq.push_back(str1[i++]);
        while(j<m) superseq.push_back(str2[j++]);

        return superseq;
    }
};