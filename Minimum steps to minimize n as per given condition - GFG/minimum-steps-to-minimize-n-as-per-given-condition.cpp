//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
private:
    int solve(int n, vector<int>& dp, int& steps) {
        if (n == 1) return steps;
        if (dp[n] != -1) return dp[n];

        int a = INT_MAX, b = INT_MAX, c = INT_MAX;
        if (n % 3 == 0) {
            steps++;
            a = solve(n / 3, dp, steps);
            steps--;
        }
        if (n % 2 == 0) {
            steps++;
            b = solve(n / 2, dp, steps);
            steps--;
        }
        steps++;
        c = solve(n - 1, dp, steps);
        steps--;

        return dp[n] = 1 + min({a, b, c});
    }

public:
    int minSteps(int N) {
        if (N == 1) return 0;
        if (N == 3 || N == 2) return 1;
        vector<int> dp(N + 1, -1); // Initialize dp vector with -1
        dp[1] = 0;
        dp[2] = 1;
        dp[3] = 1;
        int steps = 0;
        return solve(N, dp, steps);
    }
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.minSteps(n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends