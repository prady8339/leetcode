//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{  
    bool solve(vector<vector<int>> &dp,vector<int> &arr,int sum,int idx){
    if(sum == 0) return true;
    if(idx < 0) return false;
    if(sum < 0) return false;
       if(dp[idx][sum]!=-1) return dp[idx][sum];
        bool pick = solve(dp,arr,sum-arr[idx],idx-1);
        bool npick = solve(dp,arr,sum,idx-1);
        return dp[idx][sum]=(pick)||(npick);
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        vector<vector<int>> dp(arr.size()+1,vector<int> (sum+1,-1));
        return solve(dp,arr,sum,arr.size()-1);
        // int N = arr.size();
        // vector<vector<bool>> t(N+1,vector<bool> (sum+1));
        // for(int i = 0 ; i < N+1 ; i++){
        //     for(int j = 0 ; j < sum+1 ; j++){
        //         if(i==0) t[i][j]=false;
        //         if(j==0) t[i][j]=true;
        //     }
        // }
        
        // for(int i = 1 ; i < N+1 ; i++){
        //     for(int j = 1 ; j < sum+1 ; j++){
        //         if(arr[i-1]<=j){
        //             t[i][j]= t[i-1][j-arr[i-1]]  || t[i-1][j];
        //             }
        //         else t[i][j]=t[i-1][j];
        //     }
        // }
        // for(int i = 0 ; i < N+1 ; i++){
        //     for(int j = 0 ; j < sum+1 ; j++){
        //         cout<<t[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // return t[N][sum];
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends