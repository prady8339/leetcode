class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> un;
        for(auto &x : s){
            un[x]++;
        }
        for(auto &[k, v]: un){
            pq.push({v,k});
        }
        string ans;
        while(!pq.empty()){
            auto tp = pq.top();
            char k = tp.second;
            int times = tp.first;
            while(times){
                ans += k;
                times--;
            }
            pq.pop();
        }
        return ans;
    }
};