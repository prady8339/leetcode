class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char,int> um;
        for(auto &ch : s){
            um[ch]++;
            if(um[ch] > (n/2) + (n&1) ) return "";
        }
        priority_queue<pair<int,char>> pq;
        for(auto &it : um){
            pq.push({it.second,it.first});
        }
        
       string ans;
       while(!pq.empty()){
           auto ele1 = pq.top();
           ans.push_back(ele1.second);
           pq.pop();
           if(pq.empty()) break;
           auto ele2 = pq.top();
            ans.push_back(ele2.second);
            pq.pop();
        if(ele1.first-1 > 0) pq.push({ele1.first-1,ele1.second});
        if(ele2.first-1 > 0) pq.push({ele2.first-1,ele2.second});     
       }
       return ans;
               
    }
};