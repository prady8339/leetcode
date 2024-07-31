class Solution {

private: 
    int solve(vector<vector<int>>& books, int sw, int idx, vector<int>& memo){
        if(idx >= books.size()) return 0;
        if(memo[idx] != -1) return memo[idx];
        
        int maxHeight = 0;
        int width = 0;
        int res = INT_MAX;

        for(int i = idx; i < books.size(); i++) {
            if(width + books[i][0] > sw) break;
            width += books[i][0];
            maxHeight = max(maxHeight, books[i][1]);
            res = min(res, maxHeight + solve(books, sw, i + 1, memo));
        }

        return memo[idx] = res;
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int> memo(books.size(), -1);
        return solve(books, shelfWidth, 0, memo);
    }

};
