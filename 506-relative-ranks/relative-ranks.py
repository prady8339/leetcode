class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        ans = score
        mp = {}
        for i,num in enumerate(score):
            mp[num] = i
        
        idx = 1
        for key, value in reversed(sorted(mp.items())):
            if idx == 1:
                ans[value] = "Gold Medal"
            if idx == 2:
                ans[value] = "Silver Medal"
            if idx == 3: 
                ans[value] = "Bronze Medal"
            if idx > 3:
                ans[value] = str(idx)
            idx += 1
        
        return ans



