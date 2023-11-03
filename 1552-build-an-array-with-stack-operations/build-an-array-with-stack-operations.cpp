class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int i = 1; 
        int k = 0;
        while(i<=n){
            if(k>=target.size()) break;
            if(target[k]==i){
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