class Solution {
bool isPerfect(int num) {
    if (num < 0) return false;  
    int sqrtNum = static_cast<int>(sqrt(num));  
    return (sqrtNum * sqrtNum == num);     
}
public:
    bool judgeSquareSum(int c) {
        int a = 0;
        for(int i = 0; a <= (c - a) ; i++){
            a = i * i;
            if(isPerfect(c - a)) return true;
        }
        return false;
    }
};