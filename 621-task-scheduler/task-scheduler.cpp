class Solution {
private:
    void reduce(priority_queue<pair<int,char>> &pq, int k,int &ans){
        stack<pair<int,int>> st;
        while(!pq.empty() && k > 0){
            k--;
            ans++;
            auto tp = pq.top();
            if(tp.first - 1  > 0)
            st.push({tp.first - 1, tp.second});
            pq.pop();
        }
        if(k > 0 && !st.empty()){
            ans+= k;
        }
        while(!st.empty()){
            pq.push(st.top());
            st.pop();
        }
    }
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> freq;
        for(auto &t : tasks) freq[t]++;
        for(auto &[k, v]: freq) pq.push({v,k});
        int ans = 0;
        while(!pq.empty()){
            reduce(pq, n + 1,ans);
        }
        return ans;
    }
};