class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1 && k==1) return 0;  
        int mid =  pow(2,n-1)/2;
        if(k > mid){
           return !kthGrammar(n-1,k - mid);
        }else{
            return kthGrammar(n-1,k);
        }
    }
};

// 1>0 (1)

// 2>01 (2)

// 3>0110 (4)
 
// 4>01101001 (8)

// 5>0110100110010110 (16)