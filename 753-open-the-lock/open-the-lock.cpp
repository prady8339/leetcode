class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        unordered_set<string> st(deadends.begin(), deadends.end());
        unordered_set<string> vis;
        queue<pair<string,int>> q;
        q.push({"0000",0});
        int ans = 0;
        while(!q.empty()){
            auto [state,moves] = q.front();
            q.pop();
            if(st.count(state) || vis.count(state)) {
                continue;
            }
            if(state == target) return moves;
            vis.insert(state);

            for(int i = 0 ; i < 4 ; i++){
                string nextState = state;

                // +1 case
                nextState[i] = (state[i] == '9') ? '0' : state[i] + 1;
                if (!vis.count(nextState) && !st.count(nextState)) {
                    q.push({nextState, moves + 1});
                }

                // -1 case
                nextState = state;
                nextState[i] = (state[i] == '0') ? '9' : state[i] - 1;
                if (!vis.count(nextState) && !st.count(nextState)) {
                    q.push({nextState, moves + 1});
                }
            }


        }
        return -1;
    }
};
