class Solution {
public:
    long long maximumHappinessSum(vector<int>& happy, int k) {
        sort(happy.rbegin(),happy.rend());
        long long sum  = 0;
        for(int i = 0 ; i < k ; i++){
            if(happy[i] - i > 0) sum += happy[i] - i;
        }
        return sum;
    }
};