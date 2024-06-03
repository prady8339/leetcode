class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        l = 0
        i = 0
        while i < len(s) and l < len(t):
            if s[i] == t[l]:
                l+=1
            i+=1

        return len(t) - l