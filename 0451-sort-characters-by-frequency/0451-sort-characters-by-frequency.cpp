#define pic pair<int,char>
class Solution {
public:
    string frequencySort(string s) {
        sort(s.begin(),s.end());
        set<pic> pq;
        s+='0';
        string str;
        
       int i = 1 ,j=1 ;
           
    while( i < s.length())
    {
        if(s[i-1]==s[i]) j++;
        else{ 
            pq.insert({j,s[i-1]});
            j=1;
            }
        i++;
    }
        
     
        while(!pq.empty()){
                auto x = prev(pq.end());
                int c = x->first;
                while(c>0){
                    str+=x->second;
                    c--;
                }
                 pq.erase(x);
  
        }
        return str;
    }
};