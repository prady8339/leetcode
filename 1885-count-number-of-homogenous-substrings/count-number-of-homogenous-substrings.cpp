class Solution {
public:
    int countHomogenous(string s) {
        int n = s.size();
        int mod = 1e9+7;
        int sum = 0;
        char prev = s[0];
        int ct = 1;
        for(int i = 1 ; i < n ; i++){
            if(s[i]==prev){
                ct++;
            }else{
                sum = (sum + (1ll * ct * (ct + 1)) / 2) % mod;
                prev = s[i];
                ct = 1;
            }
        }
        sum = (sum + (1ll * ct * (ct + 1)) / 2) % mod;
        return sum;
    }
};