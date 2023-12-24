class Solution {
public:
    int minOperations(string s) {
        int azero = 0, aone = 0, bzero = 0, bone = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if(i&1){
                //a zero b one
                if(s[i]=='1'){
                    azero++;
                }else{
                    bone++;
                }
            }else{
                //a one b zero
                if(s[i]=='0'){
                    aone++;
                }else{
                    bzero++;
                }
            }
        }
        return min(azero + aone , bzero + bone);
    }
};