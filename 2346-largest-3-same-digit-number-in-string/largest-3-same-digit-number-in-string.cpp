class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string maxi ;

        for(int i = 0  ; i < n ; i++){
            char prev = num[i];
            bool f = 1;
            for(int j = i ; j < i+3 ; j++){
               if(num[j] != prev){
                   f = 0;
                   break;
               }
            }
            if(f){
                if(maxi.size()==0){
                    maxi = num.substr(i,3);
                }
                else{
                    maxi = max(maxi,num.substr(i,3));
                }
            }
        }
        return maxi;
    }
};