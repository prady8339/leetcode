class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;

        for (int j = 1; j < n - 1; ++j) {
            int leftLess = 0, leftMore = 0, rightLess = 0, rightMore = 0;

            for (int i = 0; i < j; ++i) {
                if (rating[i] < rating[j]) leftLess++;
                else if (rating[i] > rating[j]) leftMore++;
            }

            for (int k = j + 1; k < n; ++k) {
                if (rating[k] < rating[j]) rightLess++;
                else if (rating[k] > rating[j]) rightMore++;
            }

            ans += leftLess * rightMore + leftMore * rightLess;
        }

        return ans;
    }
};
