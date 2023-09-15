from collections import defaultdict
from typing import List


class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        cnt = defaultdict(int)
        words.sort(key=len)
        res = 0
        for word in words:
            cnt[word] = 1
            for i in range(len(word)):
                prev = word[:i] + word[i+1:]
                if prev in cnt:
                    cnt[word] = max(cnt[word], cnt[prev] + 1)
            res = max(res, cnt[word])
        return res
