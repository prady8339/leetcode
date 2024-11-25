class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450";
        string current;
        int zidx = -1;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                char c = board[i][j] + '0';
                current.push_back(c);
                if (c == '0')
                    zidx = i * 3 + j;
            }
        }
        vector<vector<int>> dirs = {{1, 3}, {0, 2, 4}, {1, 5},
                                    {0, 4}, {1, 3, 5}, {2, 4}};
        unordered_set<string> seen;
        queue<pair<int, string>> q;
        q.push({zidx, current});
        int count = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto [zeroIdx, curr] = q.front();
                q.pop();
                if (curr == target)
                    return count;
                for (auto& d : dirs[zeroIdx]) {
                    swap(curr[d], curr[zeroIdx]);
                    if (!seen.count(curr)) {
                        q.push({d, curr});
                        seen.insert(curr);
                    }
                    swap(curr[d], curr[zeroIdx]);
                }
            }
            count++;
        }
        return -1;
    }
};
// 0 1 2
// 3 4 5