class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int sum = 0;
        bool g = 0, p = 0, m = 0;
        for(int i = travel.size(); i > 0 ; i--){
            sum += garbage[i].size();
            if(!g || !m || !p)
            for(auto &ch : garbage[i]){
                if(ch == 'G') g = 1;
                if(ch == 'P') p = 1;
                if(ch == 'M') m = 1;
                if(p && m && g) break;
            }
            if(g)
                sum +=  travel[i-1];
            if(p)
                sum += travel[i-1];
            if(m)
                sum += travel[i-1];
        }
        sum += garbage[0].size();
        return sum;
    }
};