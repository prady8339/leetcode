class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int rem = 0;
        ans += numBottles;
       while(numBottles > 0){
            int newbot = (rem + numBottles) / numExchange;
            rem = (rem + numBottles) % numExchange;
            ans += newbot;
            numBottles = newbot;
            if(newbot == 0) break;
       }
        return ans;
    }
};