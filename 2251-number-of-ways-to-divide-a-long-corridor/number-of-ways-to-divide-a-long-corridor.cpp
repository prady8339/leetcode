class Solution {
    int mod = 1e9 + 7;
    int solve(int idx,int seatCount,string &corridor,int cache[][3]){
        int n = corridor.size();
        if(idx == n) return seatCount == 2 ? 1 : 0;

        if(cache[idx][seatCount] != -1) return cache[idx][seatCount];
        int ways = 0;
        if(seatCount == 2){
            if(corridor[idx] == 'S') {
                ways = solve(idx + 1, 1, corridor, cache);
            }
            else{
                ways = (solve(idx + 1, 0, corridor, cache) + solve(idx + 1, 2, corridor, cache)) % mod;
            }
           
        }else{
            if(corridor[idx] == 'S'){
                ways = solve(idx + 1, seatCount + 1, corridor, cache);
            }else{
                ways = solve(idx + 1, seatCount, corridor, cache);
            }
        }
        return cache[idx][seatCount] = ways;
    }
public:
    int numberOfWays(string corridor) {
        int cache[corridor.length()][3];
        memset(cache, -1, sizeof(cache));
        return solve(0, 0, corridor, cache);
    }
};