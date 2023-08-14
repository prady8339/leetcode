public class Solution {
    private int solve(int[] nums, int target, int idx, int exp, HashMap<Integer, Integer>[] dp) {
        if (idx >= nums.length) {
            return exp == target ? 1 : 0;
        }
        if (dp[idx].containsKey(exp)) return dp[idx].get(exp);

        int neg = solve(nums, target, idx + 1, exp - nums[idx], dp);
        int pos = solve(nums, target, idx + 1, exp + nums[idx], dp);

        int result = neg + pos;
        dp[idx].put(exp, result);
        return result;
    }

    public int findTargetSumWays(int[] nums, int target) {
        int n = nums.length;
        HashMap<Integer, Integer>[] dp = new HashMap[n + 1];
        for (int i = 0; i <= n; i++) {
            dp[i] = new HashMap<>();
        }
        return solve(nums, target, 0, 0, dp);
    }
}
