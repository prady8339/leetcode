class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> adj(n);
        unordered_map<int,int> od;
        for(auto rd: roads){
            od[rd[0]]++;
            od[rd[1]]++;
            adj[rd[0]].insert(rd[1]);
            adj[rd[1]].insert(rd[0]);
        }

        int maxi = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                if(adj[i].count(j)){
                    maxi = max(maxi,od[i]+od[j]-1);
                }else{
                    maxi = max(maxi,od[i]+od[j]);
                }
            }
        }

        return maxi;

    }
};