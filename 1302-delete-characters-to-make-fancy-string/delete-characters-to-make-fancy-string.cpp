class Solution {
public:
    string makeFancyString(string s) {
        char prev = ' ';
        int count = 0;
        string ans = "";
        for(auto &x : s){
            if(prev == x){
                count++;
            }else{
                count=1;
            }
            if(count <= 2) ans.push_back(x); 
            prev = x;
        }
        return ans;
    }
};