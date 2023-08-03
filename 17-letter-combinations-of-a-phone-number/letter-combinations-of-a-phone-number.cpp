class Solution {

    private:
    void solve(int idx,string &dig,string &ds,vector<string> &ans,unordered_map<int,string> &un){

        if(idx>=dig.size()){
            if(ds.size()>0)
            ans.push_back(ds);
            return ;
        }

        for(auto x:un[dig[idx]-'0']){
            ds.push_back(x);
            solve(idx+1,dig,ds,ans,un);
            ds.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int,string> un;
        un[2]="abc";
        un[3]="def";
        un[4]="ghi";
        un[5]="jkl";
        un[6]="mno";
        un[7]="pqrs";
        un[8]="tuv";
        un[9]="wxyz";
        vector<string> ans;
        string ds;
        solve(0,digits,ds,ans,un);
        return ans;    
    }
};