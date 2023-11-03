class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int i = 1; 
        int k = 0;
        int ct = 0;
        while(i<=n){
            if(k>=target.size()) break;
            if(target[k]==i){
                while(ct>0){
                    ans.push_back("Pop");
                    ct--;
                }
                k++;
               
            }else{
                ct++;
            }
            ans.push_back("Push");
            i++;
        }
        return ans;
    }
};