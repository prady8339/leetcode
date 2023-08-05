//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int N, int k) 
    { 
     unordered_map<int,int> ps;
     int j = 0,maxi = 0,sum=0;
   
     while(j<N){
         sum+=arr[j];
         
         if(sum==k) maxi = j+1;
         
         if(ps.count(sum-k)){ 
             maxi = max(maxi,j-ps[sum-k]);
         }
         if(!ps.count(sum))
         ps[sum]=j;
         j++;
     }
     return maxi;
    }
    
};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends