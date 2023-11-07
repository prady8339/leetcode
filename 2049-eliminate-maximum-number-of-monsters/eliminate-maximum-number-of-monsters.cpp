class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        for(int i = 0 ; i < n ; i++){
            if(dist[i]==0) return 0;
            dist[i] = ceil( (double) dist[i] / speed[i]);
        }
        sort(dist.begin(),dist.end());

        // for(auto x:dist){cout<<x<<" ";}

        int prev = 0, count = 0;
        for(int i = 0 ; i < n ; i++){
            if(dist[i]-prev <= 0) break;
            prev++;
            count++;
        }

        return count;
    }
};