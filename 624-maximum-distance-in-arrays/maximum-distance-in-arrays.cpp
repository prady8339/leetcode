class Solution {
public:
    int maxDistance(vector<vector<int>>& a) {
        int n = a.size();
        pair<int,int> mx1 = {INT_MIN, -1}, mx2 = {INT_MIN, -1};
        pair<int,int> mi1 = {INT_MAX, -1}, mi2 = {INT_MAX, -1};
        
        for(int i = 0 ; i < n ; i++){
            if(a[i].back() >= mx1.first){
                mx2 = mx1;
                mx1 = {a[i].back(), i};
            } else if(a[i].back() >= mx2.first){
                mx2 = {a[i].back(), i};
            }

            if(a[i][0] <= mi1.first){
                mi2 = mi1;
                mi1 = {a[i][0], i};
            } else if(a[i][0] <= mi2.first){
                mi2 = {a[i][0], i};
            }
        }

        if(mx1.second != mi1.second) 
            return abs(mx1.first - mi1.first);

        return max(
            abs(mx1.first - mi2.first),
            abs(mx2.first - mi1.first)
        );
    }
};
