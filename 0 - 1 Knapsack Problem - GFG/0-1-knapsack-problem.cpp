//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    // private:
    // int solve(int w,int *wt,int *val,int n,vector<unordered_map<int,int>> &dp){
    //     if(n<0 || w<=0) return 0;
        
    //     if(dp[n].count(w)) return dp[n][w];
        
    //     if(w>=wt[n])
    //     return dp[n][w] = max(val[n] + solve(w - wt[n], wt, val, n - 1, dp), solve(w, wt, val, n - 1, dp));
    //     else return dp[n][w] = solve(w,wt,val,n-1,dp);
    // }
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
    //   vector<unordered_map<int,int>> dp(n+1);
    //   return solve(W,wt,val,n-1,dp);
        vector<vector<int>> tab(n+1,vector<int> (W+1));
        for(int i = 0 ; i < n+1 ; i++){
            for(int j = 0 ; j < W+1 ; j++){
                if(i==0 || j==0){
                    tab[i][j]=0;
                }
            }
        }
        
        for(int i = 1 ; i < n+1 ; i++){
            for(int j = 1 ; j < W+1 ; j++){
                if(wt[i-1]<=j){
                    tab[i][j]=max(val[i-1]+tab[i-1][j-wt[i-1]],tab[i-1][j]);
                }else{
                    tab[i][j]=tab[i-1][j];
                }
            }
        }
        // for(int i = 0 ; i < n+1 ; i++){
        //     for(int j = 0 ; j < W+1 ; j++){
        //         cout<<tab[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return tab[n][W];
    }
};


//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends