class Solution {
public:
    int minDeletions(string s) {
        priority_queue<int> pq;
        unordered_map<char,int> um;
        for(auto x:s) um[x]++;
        for(auto x:um) pq.push(x.second);
        int tp = pq.top(),ct=0;
        pq.pop();
        while(!pq.empty()){
            int temp = pq.top();
            pq.pop();
            if(temp!=tp){
                tp = temp;
            }else{
                ct++;
                if(temp-1 > 0)
                pq.push(temp-1);
            }
        }
        return ct;
    }
};