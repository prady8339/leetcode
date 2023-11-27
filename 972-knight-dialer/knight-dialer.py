class Solution:
    def knightDialer(self, n: int) -> int:
        adj = {
            1: [6, 8], 2: [7, 9], 3: [4, 8],
            4: [0, 3, 9], 5: [], 6: [0, 1, 7],
            7: [2, 6], 8: [1, 3], 9: [2, 4],
            0: [4, 6]
        }
        mod = 10 ** 9 + 7
        
        @cache
        def dfs(sz, idx):
            if sz == n:
                return 1
            count = 0
            for next_idx in adj[idx]:
                count = (count + dfs(sz + 1, next_idx)) % mod
            return count

        ways = 0
        for i in adj:
            ways = (ways + dfs(1, i)) % mod

        return ways
