class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto &x : nums){
            pq.push(x);
        }
        long long score = 0;
        while(k--){
            int tp = pq.top();
            score += tp;
            pq.pop();
            int x = ceil((double)tp / 3);
            pq.push(x);
        }
        return score;
    }
};