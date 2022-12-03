#define pi pair<int,char>
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> un; 
        priority_queue<pi> pq;
        string str;
        for(auto x:s){
            un[x]++;
        }

        for(auto it=un.begin() ; it!=un.end() ; it++){
            pq.push({it->second,it->first});
        }
        
        while(!pq.empty()){
                auto x = pq.top();
                int i = x.first;
                while(i>0){
                    str+=x.second;
                    i--;
                }
                pq.pop();
        }
        return str;
    }
};