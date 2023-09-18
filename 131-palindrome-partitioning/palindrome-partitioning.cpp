class Solution {
private:
    bool isPal(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void helper(vector<vector<string>> &ans,vector<string> &temp,string &s,int i,int j){
        if(i>=s.size()){
            ans.push_back(temp);
        }
        for(int j = i ; j < s.size() ; j++){
            if(isPal(s,i,j)){
                temp.push_back(s.substr(i,j-i+1));
                helper(ans,temp,s,j+1,s.size());
                temp.pop_back();
            }
        }

    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        helper(ans,temp,s,0,s.size()-1);
        return ans;
    }
};