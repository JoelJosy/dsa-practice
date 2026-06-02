// T: O(1)
// S: O(1)

class Solution {
public:
    int getSum(int a, int b) {
        unsigned int ua = a;
        unsigned int ub = b;

        int carry = 0;
        unsigned int res = 0;

        for (int i = 0; i < 32; i++) {
            int d1 = ua & 1;
            int d2 = ub & 1;

            int sum = d1 ^ d2 ^ carry;
            carry = (d1 & d2) | (carry & (d1 ^ d2));

            res |= (sum << i);

            ua >>= 1;
            ub >>= 1;
        }

        return (int)res;
    }
};


// Optimal 
class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int carry = (a & b) << 1;
            a ^= b; // partial sum without including carry in calc
            b = carry; // includes carry in next iteration sum
        }
        return a;
    }
};