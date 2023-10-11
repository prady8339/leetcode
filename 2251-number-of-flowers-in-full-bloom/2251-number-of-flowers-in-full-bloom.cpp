class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> sBloom, eBloom;
        int n = flowers.size();
        for(int i = 0 ; i < n ; i++){
            sBloom.push_back(flowers[i][0]);
            eBloom.push_back(flowers[i][1]);
        }
        sort(sBloom.begin(),sBloom.end());
        sort(eBloom.begin(),eBloom.end());
        vector<int> ans;
        int m = people.size();
        for(int i = 0; i < m ; i++){
            int bloomingFLowers = upper_bound(sBloom.begin(),sBloom.end(),people[i]) - sBloom.begin();
            int closedFLowers = lower_bound(eBloom.begin(),eBloom.end(),people[i]) - eBloom.begin();
            people[i] = (bloomingFLowers - closedFLowers);
        }
        return people;
    }
};