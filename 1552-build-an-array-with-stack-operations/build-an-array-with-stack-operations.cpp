class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int sz = target.size();
        int i = 1; 
        int k = 0;
        while(k < sz){
            if(i > n) break;
            if(target[k] == i){
                ans.push_back("Push");
                k++;
            }else{
                 ans.push_back("Push");
                 ans.push_back("Pop");
            }
            i++;
        }
        return ans;
    }
};