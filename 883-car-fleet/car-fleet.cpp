class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();         
        map<int, double> ds;
        for (int i = 0; i < n; i++) {
            double time = static_cast<double>(target - position[i]) / speed[i];
            ds[position[i]] = time;
        }
        
        int fleets = 0;
        double lastTime = 0.0;
        for (auto it = ds.rbegin(); it != ds.rend(); ++it) {
            if (it->second > lastTime) {
                fleets++;
                lastTime = it->second;
            }
        }
        
        return fleets;
    }
};
