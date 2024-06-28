class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> city(n,0);
        vector<int> freq(n,0);
        for(auto &e : roads){
            int u = e[0];
            int v = e[1];
            freq[u]++;
            freq[v]++;
        }
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < n ; i++){
            pq.push({freq[i],i});
        }
        int l = n;
        while(!pq.empty()){
            auto tp = pq.top();
            city[tp.second] = l;
            l--;
            pq.pop();
        }

        long long ans = 0;

        for(auto &e : roads){
            int u = e[0];
            int v = e[1];
            ans += city[u];
            ans += city[v];
        }
        
        return ans;
    }
};
