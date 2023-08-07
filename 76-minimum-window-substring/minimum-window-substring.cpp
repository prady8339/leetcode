class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        if(t.size()>n) return "";
        pair<int,int> ptr={0,INT_MAX};

        unordered_map<char,int> un;
        for(auto x:t) un[x]++;
        int count = un.size();
        int i = 0,j=0;
        while(j<n){
            if(count>0){
                if(un.count(s[j])){
                    un[s[j]]--;
                    if(un[s[j]]==0) count--;
                }
                j++;
            }
            if(count==0){
                while(count==0){
                int currLen = ptr.second-ptr.first;
                if(j-i<currLen) {
                    ptr.first = i;
                    ptr.second = j;
                }
                    if(un.count(s[i])){
                    if(un[s[i]]==0) count++;
                    un[s[i]]++;
                    }
                    i++;
                }        
            }
        } 
        //cout<<count<<endl;  
        if(count==0) {
             int currLen = ptr.second-ptr.first;
                if(j-i<currLen) {
                    ptr.first = i;
                    ptr.second = j;
                }
        }
        if(ptr.second==INT_MAX) return "";
        return s.substr(ptr.first,ptr.second-ptr.first);
    }
};