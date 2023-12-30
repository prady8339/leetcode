class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        freq = defaultdict(int)

        for w in words:
            for c in w:
                freq[c] += 1

        for c in freq:
            if freq[c] % len(words):
                return False           
        return True