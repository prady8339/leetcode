class Solution {
    private:
    void gp(int open,int close,string &temp,vector<string> &ans){
        if(open<=0 && close<=0){
            ans.push_back(temp);
            return;
        }
        if(open>0){
            temp.push_back('(');
            gp(open-1,close,temp,ans);
            temp.pop_back();
        }
        if(close > open){
            temp.push_back(')');
            gp(open,close-1,temp,ans);
            temp.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        gp(n,n,temp,ans);
        return ans;
    }
};