class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> jumps;

        for (int i = 0; i < n - 1; i++) {
            int diff = heights[i + 1] - heights[i];
            if (diff > 0) {
                jumps.push(diff);

                if (jumps.size() > ladders) {
                    int bricks_needed = jumps.top();
                    jumps.pop();

                    if (bricks_needed > bricks) return i;
                    else bricks -= bricks_needed;
                }
            }
        }
        return n - 1;
    }
};
