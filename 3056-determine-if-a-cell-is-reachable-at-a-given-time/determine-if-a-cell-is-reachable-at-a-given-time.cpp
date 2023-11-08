class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx == fx && sy == fy && t==1) return false;
        int u = abs(sx-fx);
        int v = abs(sy-fy);
        if(u > t || v > t) return false;
        return true;

    }
};