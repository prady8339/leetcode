//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        vector<int> o,t;
        for(int i = 0 ; i<n ;i++){
            if(a[i]==1) o.push_back(a[i]);
            else if(a[i]==2)  t.push_back(a[i]);
        }
        int px = 0;
        for(int i = 0 ; i < n-(o.size()+t.size()) ; i++){
            a[px++] = 0;
        }
        for(int i = 0 ; i < o.size() ; i++){
            a[px++] = 1;
        }
        for(int i = 0 ; i < t.size() ; i++){
            a[px++] = 2;
        }
        
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends