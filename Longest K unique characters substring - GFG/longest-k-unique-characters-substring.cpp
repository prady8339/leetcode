//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        unordered_map<char,int> ump;
        int i = 0 , j = 0;
        int maxi = -1;
        while(j<s.size()){
            if(ump.size()<k){
                ump[s[j]]++;
                j++;
            }else if(ump.size()==k){
                maxi = max(maxi,j-i);
                ump[s[j]]++;
                j++;
            }else{
                while(ump.size()>k){
                    ump[s[i]]--;
                    if(ump[s[i]]<=0) ump.erase(s[i]);
                    i++;
                    if(ump.size()==k) maxi = max(maxi,j-i);
                }
                ump[s[j]]++;
               j++;
            }
        }
        if(ump.size()==k) maxi = max(maxi,j-i);
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends