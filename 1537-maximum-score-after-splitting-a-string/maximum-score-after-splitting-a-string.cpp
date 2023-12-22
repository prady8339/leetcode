class Solution {
public:
    int maxScore(string s) {
        int oneCt = 0, zeroCt = 0;
        int ans = 0;
        for(int i = 1; i < s.size() -1 ; i++){
            if(s[i]=='1') oneCt++;
        }
    
        for(int i = 1; i < s.size() -1 ; i++){
            ans = max(zeroCt + oneCt , ans);
            if(s[i] == '0') 
                zeroCt++;
            else if(s[i] == '1')
                oneCt--;
        }
        ans = max(zeroCt + oneCt , ans);

        int a = s[0]== '0' ;
        int b = s.back() == '1';
   
        return ans + a + b;
    }
};