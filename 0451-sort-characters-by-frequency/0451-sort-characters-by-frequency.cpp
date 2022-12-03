#define pic pair<int,char>
class Solution {
public:
    string frequencySort(string s) {
        sort(s.begin(),s.end());
        priority_queue<pic> pq;
        s+='0';
        string str;
        
       int i = 1 ,j=1 ;
           
    while( i < s.length())
    {
        if(s[i-1]==s[i]) j++;
        else{ 
            pq.push({j,s[i-1]});
            j=1;
            }
        i++;
    }
        
     
        while(!pq.empty()){
                auto x = pq.top();
                int c = x.first;
                while(c>0){
                    str+=x.second;
                    c--;
                }
                pq.pop();
        }
        return str;
    }
};