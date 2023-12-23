class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> vis;
        int x = 0, y = 0;
        int n = path.size();
        vis.insert({0,0});
        for(int i = 0 ; i < n ; i++){
            char dir = path[i];
            if(dir == 'N'){
                ++y;
            }else if(dir == 'S'){
                --y;
            }else if(dir == 'W'){
                ++x;
            }else if(dir == 'E'){
                --x;
            }
            if(vis.count({x,y})) return true;
            vis.insert({x,y});
        }
        return false;
    }
};