class Solution {
public:
    string compressedString(string word) {
        int count = 0;
        char prev =' ';
        string ans = "";
        for (auto& c : word) {
            if (c == prev) {
                count++;
            } else {
                while (count > 9) {
                    ans.push_back('9');
                    ans.push_back(prev);
                    count -= 9;
                }
                if (count > 0 && count <= 9) {
                    ans += to_string(count);
                    ans.push_back(prev);
                }
                count = 1;
            }
            prev = c;
        }
        while (count > 9) {
            ans.push_back('9');
            ans.push_back(prev);
            count -= 9;
        }
        if (count > 0 && count <= 9) {
            ans += to_string(count);
            ans.push_back(prev);
        }
        return ans;
    }
};