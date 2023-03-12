class Solution {
    private:
    void solve(int n,vector<int> &arr){
        int cn = n ;
        int ct = 0;
        while(n>0){
            if(n%2!=0){ ct++; }
            n/=2;
        }
        arr[cn]=ct;
        return;
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        int ct = 0;
        for(int i = 0 ;i <= n ; i++){
            solve(i,ans);
        }
        return ans;
    }
};