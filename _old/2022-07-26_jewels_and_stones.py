# Jewels and Stones
# https://leetcode.com/problems/jewels-and-stones/

class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        return len([i for i in stones if i in jewels])
