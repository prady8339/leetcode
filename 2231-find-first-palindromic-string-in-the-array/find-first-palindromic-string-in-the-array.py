class Solution:
    def firstPalindrome(self, words: List[str]) -> str:
        def isPal(w):
            l = 0
            r = len(w)-1
            while l < r :
                if(w[l] != w[r]):
                    return False
                l += 1
                r -= 1
            return True
        
        for w in words:
            if(isPal(w)):
                return w
        return ""