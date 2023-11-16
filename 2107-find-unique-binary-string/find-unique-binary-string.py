class Solution:
    def increment(self, num: str) -> str:
        res = ''
        f = False
        for ch in num[::-1]:
            if ch == '1' and not f:
                res += '0'
            elif ch == '0' and not f: 
                res += '1'
                f = True
            else:
                res += ch
        return res[::-1]  

    def findDifferentBinaryString(self, nums: List[str]) -> str:
        nums.sort()
        n = len(nums)
        res = '0' * n
        for num in nums:
            if num != res:
                return res
            res = self.increment(res)
        return res
