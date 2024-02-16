class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> un;
        for(auto &x : arr) un[x]++;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto &[_, val] : un){
            pq.push(val);
        }
      
        while(!pq.empty() && k > 0 ){
            int tp = pq.top();
            if(tp <= k){ 
                pq.pop();
            }
            k -= tp;
        }
        return pq.size();
    }
};