// Time and Space: O(1) for all below solns

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n!=0) {
            if ((n & 1) == 1)
                count++;
            n = n >> 1; // shift one bit to the right
        }
        return count;
    }
};


// The expression n & (n - 1) removes the rightmost set bit from n. 
// By repeatedly applying this operation until n becomes 0, 
// we can count exactly how many 1 bits were present

class Solution {
public:
    int hammingWeight(int n) {
        int res = 0;
        while (n) {
            n &= n - 1;
            res++;
        }
        return res;
    }
};