class Solution {
public:
    int minOperations(string s) {
        int a = 0, b = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if(i&1){
                //a zero b one
                if(s[i]=='1'){
                    a++;
                }else{
                    b++;
                }
            }else{
                //a one b zero
                if(s[i]=='0'){
                    a++;
                }else{
                    b++;
                }
            }
        }
        return min(a, b);
    }
};