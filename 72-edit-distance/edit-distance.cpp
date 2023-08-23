class Solution {
public:
    int minDistance(string word1, string word2) {
       int n = word1.size() , m = word2.size();
       vector<vector<int>> dp(n+1,vector<int> (m+1));
       //for the base case
       //case 1 when word1 is empty we need word2.size() operation cuz we insert all
       //case 2 when word2 is empty we need word1.size() operation cuz we delete all 

       for(int i = 0 ; i < n+1 ; i++){
           //size == max operation
           dp[i][0] = i;
       }
        for(int j = 0 ; j < m+1 ; j++){
           //size == max operation
           dp[0][j] = j;
       }
    
    // we word1[i]==word2[j] we just simply move further with no cost
    // else we choose minmum from 3 cases either replace , insert ,delete

       for(int i = 1 ;i < n+1 ; i++){
           for(int j = 1 ; j < m+1 ; j++){
               if(word1[i-1] == word2[j-1]){
                   dp[i][j] = dp[i-1][j-1];
               }else{
                   // replace , delete ,insert
                   dp[i][j] = min({dp[i-1][j-1]+1,dp[i][j-1]+1,dp[i-1][j]+1});
                   // for better intution itterate dp in reverse and same with initilization 
                   // then return dp[0][0] for for now we return dp[n][m]
               }
           }
       }

       return  dp[n][m] ; 
    }
};