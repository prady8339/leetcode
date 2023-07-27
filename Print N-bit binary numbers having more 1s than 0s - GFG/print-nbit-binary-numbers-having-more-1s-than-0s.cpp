//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
    private:
    void solve(int n, int one, int zero, string &ds,vector<string> &ans)
{
    if (one + zero > n)
        return;

    if (one + zero == n)
    {
       ans.push_back(ds);
        return;
    }

    ds.push_back('1');
    solve(n, one + 1, zero, ds,ans);
    ds.pop_back();
    if (one > zero)
    {
        ds.push_back('0');
        solve(n, one, zero + 1, ds,ans);
        ds.pop_back();
    }
}
public:	
	vector<string> NBitBinary(int N)
	{

        string ds;
        vector<string> ans;
        solve(N, 0, 0, ds,ans);
        return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends