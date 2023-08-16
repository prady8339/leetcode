//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    
private:
    int solve(int n,int price[],vector<int> &dp){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int maxi = 0;
        for(int j = 0 ; j < n ; j++){
            maxi = max(price[j]+solve(n-(j+1),price,dp),maxi);
        }
        
        return dp[n] = maxi;
        
    }
    
  public:
    int cutRod(int price[], int n) {
        // vector<int> dp(n+1,-1);
        // return solve(n,price,dp);
        vector<vector<int>> dp(n+1,vector<int> (n+1));
        
        for(int i = 1 ; i < n+1 ; i++){
            for(int j = 0 ; j < n+1; j++){
                
                dp[i][j]=dp[i-1][j];
                 
                if(j>=i){
                    dp[i][j]=max(price[i-1]+dp[i][j-i],dp[i-1][j]);
                }
                
            }
        }
        return dp[n][n];
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends