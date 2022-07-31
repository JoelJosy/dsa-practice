# Build an Array With Stack Operations
# https://leetcode.com/problems/build-an-array-with-stack-operations/

class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        final = []
        fin = []
        # target = [1,2]
        # l = [1,2,3,4]
        l = list(range(1,n+1))
        for i in range(len(l)):
            if fin == target:
                break
            elif l[i] in target:
                final.append("Push")
                fin.append(l[i])
            else:
                final.extend(["Push", "Pop"])
                fin.append(l[i])
                fin.pop()
        return final
        