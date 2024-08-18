class Solution {
private:
    bool is_valid(string& s) {
        if (s.size() > 3 || s.size() == 0)
            return false;
        if (s[0] == '0' && s.size() == 1)
            return true;
        if (s[0] == '0')
            return false;
        int x = stoi(s);
        if (x <= 255 && x >= 0)
            return true;
        return false;
    }

    void solve(vector<string>& ans, string& s, string ds, int idx, int cuts) {

        if (idx >= s.size() || cuts > 3) {
            return;
        }

        if (cuts == 3) {
            int sx = s.size() - idx;
            string xf = s.substr(idx, sx);
            if (is_valid(xf)) {
                ans.push_back(ds + xf);
            }
        }

        string prev = ds;
        for (int i = 1; i <= 3; i++) {
            string xf = s.substr(idx, i);
            if (is_valid(xf)) {
                ds += xf;
                ds.push_back('.');
                solve(ans, s, ds, idx + i, cuts + 1);
                ds = prev;
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        solve(ans, s, "", 0, 0);
        return ans;
    }
};