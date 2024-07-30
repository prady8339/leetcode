class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int totalA = 0, totalB = 0;
        for(auto &x : s){
            if(x == 'a') totalA++;
        }
        totalB = n - totalA;

        if(totalA == n || totalB == n) return 0;

        int prevB = 0;
        int nextA = totalA;

        int ans = nextA;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == 'b') prevB++;
            else nextA--;

            ans = min(nextA + prevB , ans);
        }
        
        return ans;
    }
};