class Solution {
public:
    int maxDepth(string s) {
        int count = 0, maxi = 0;
        for(auto &x : s){
            if(x == '('){
                count++;
                maxi = max(count,maxi);
            }else if(x == ')'){
                count--;
            }
        }
        return maxi;
    }
};