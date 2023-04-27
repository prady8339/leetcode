class Solution {
public:
    int bulbSwitch(int n) {
        if(n==0) return 0;
        if(n<=3) return 1;
        int adder = 3;
        for(int i = 3,count = 1;count<n;i+=adder){
            if( n < i+1 ) return count;
            adder+=2;
            count++;
        }
        return n;
    }
};