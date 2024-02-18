class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        for(int i = 0 ; i < heights.size() - 1 ; i++){
            int diff = heights[i + 1] -  heights[i];
            if(diff > 0){
                pq.push(diff);
                if(bricks >= diff){
                    bricks -= diff;
                }else if(ladders > 0){
                    bricks += pq.top();
                    bricks -= diff;
                    ladders -= 1;
                    pq.pop();
                }else{
                    return i;
                }
            }
        }
        return heights.size() - 1;
    }
};