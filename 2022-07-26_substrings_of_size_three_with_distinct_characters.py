# Substrings of Size Three with Distinct Characters
# https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/

class Solution:
    def countGoodSubstrings(self, s: str) -> int:
        return sum(len(set(s[i:i+3])) == 3 for i in range(len(s)-2))
        