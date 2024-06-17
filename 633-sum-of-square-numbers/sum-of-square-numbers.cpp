class Solution {
bool isPerfect(int num) {
    if (num < 0) return false;  

    int sqrtNum = static_cast<int>(sqrt(num));  
    return (sqrtNum * sqrtNum == num);     
}
public:
    bool judgeSquareSum(int c) {
        for(int i = 0; i * i <= c ; i++){
            int a = i * i;
            int b = c - a;
            if(isPerfect(a) && isPerfect(b)) return true;
            if(b < a) return false;
        }
        return false;
    }
};