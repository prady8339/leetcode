class Solution {
private:
    int ct(int n){
        int count = 0;
        while(n!=0){
            if(n%2==1) count++;
            n=n>>1;
        }
        cout<<endl;
        return count;
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i = 0 ; i < n+1 ; i++){
            ans[i]=ct(i);
        }
        return ans;
    }
};