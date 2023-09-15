# class Solution:
#     def checkIfPangram(self, sentence: str) -> bool:
#         exist = [0 for _ in range(26)]
#         for ch in sentence:
#             exist[ch - 'a'] = 1
#         return sum(exist) == 26
    
class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        res = 0
        for ch in sentence:
            res |= (1 << (ord(ch) - ord('a')))
        return res == (1 << 26) - 1