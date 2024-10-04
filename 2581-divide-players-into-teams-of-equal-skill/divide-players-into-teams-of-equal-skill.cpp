class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(), skill.end());
        long long req = skill[0] + skill[n - 1];
        long long ans = 0;
        for (int i = 0; i < n / 2; i++) {
            int l = skill[i];
            int r = skill[n - i - 1];
            if (l + r != req)
                return -1;
            ans += (long long) l * r;
        }
        return ans;
    }
};