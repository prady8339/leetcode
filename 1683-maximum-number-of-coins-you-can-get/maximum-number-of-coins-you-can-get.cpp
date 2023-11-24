class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int mySum = 0;
        sort(piles.begin(),piles.end());
        int n = piles.size() / 3;
        int end = piles.size() - 2;
        while(end >= n){
            mySum += piles[end];
            end -= 2;
        }
        return mySum;
    }
};