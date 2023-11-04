class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxi = 0;
        for(auto &x:left){
            maxi = max(x,maxi);
        }
        for(auto &x:right){
            maxi = max(n-x,maxi);
        }
        return maxi;
    }
};