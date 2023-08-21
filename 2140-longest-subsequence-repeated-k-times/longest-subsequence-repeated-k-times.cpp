class Solution {
private:
    bool checkStr(string &temp,int k,string &s){
        int freq = 0 ;
        int i = 0 , j = 0;
        int n = s.size();
        while( i < n ){
            if(temp[j]==s[i]){ 
                j++;
                if(j==temp.size()) j = 0 , freq++; 
                //promising one to later give me freq==k , so that i don't reject the potential soln giver.
                if(freq==k) return true;
            }
            i++;
        }
        return false;
    }

public:
    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.size();
        queue<string> q;
        q.push("");
        string ans = "";
        while(!q.empty()){
            string curr = q.front();
            q.pop();
            for(int i = 0 ; i < 26 ; i++){
                string temp = curr + char(i+'a');
                if(checkStr(temp,k,s)){
                    ans = temp;
                    q.push(temp);
                }
            }
        }
        return ans;
    }
};