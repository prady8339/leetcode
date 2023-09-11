class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
        map<int,int> ds;
        vector<vector<int>> ans;
        int n = gs.size();
        for(int i = 0 ; i < n ; i++){
           ds[gs[i]]++;
        }
         for(auto &x:ds){
             ds[x.first] = ds[x.first]/x.first; 
         }
        vector<bool> vis(n);
        queue<int> q;
        for(auto &x : ds){
            q.push(x.first);
        }
        while(!q.empty()){
            int grp = q.front();
            ds[grp]--;
            if(ds[grp]<=0) q.pop();

            vector<int> temp(grp);
            int j = 0;
            for(int i= 0 ; i < n && j < grp; i++){
                if(vis[i]) continue;
                if(gs[i] == grp){
                    temp[j++] = i;
                    vis[i]=1;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};