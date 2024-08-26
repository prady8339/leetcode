class Solution {
public:
    int pivotInteger(int n) {
       int pef = 0;
       int suf = n;
       for(int i = 1; i <= n ; i++) pef += i;
       while(n){
            if(pef == suf) return n;
            pef -= n;
            suf += n - 1;
            n--;
       }
       return -1;
 
    }
};