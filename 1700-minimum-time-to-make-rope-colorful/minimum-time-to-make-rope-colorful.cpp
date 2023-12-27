class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int maxi = neededTime[0], sum = maxi;
        int prev = 0, ans = 0, n = colors.size();

        for(int i = 1; i < n ; i++){
            if(colors[i] == colors[prev]){
                sum += neededTime[i];
                maxi = max(maxi, neededTime[i]);
            }else{
                ans += sum - maxi;
                maxi = neededTime[i];
                sum = neededTime[i];
            }
            prev = i;
        }
        ans += sum - maxi;
        
        return ans;
    }
};