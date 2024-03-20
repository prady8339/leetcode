class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for(auto &t : tasks) freq[t - 'A']++;
        sort(begin(freq),end(freq),greater<int>());
        int chunk = freq[0] - 1;
        int idel = chunk * n;
        for(int i = 1 ; i < 26 ; i++) idel -= min(chunk,freq[i]);
        return idel < 0 ? tasks.size() : tasks.size() + idel;
    }
};