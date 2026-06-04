// T: O(logx)
// S: O(1)

class Solution {
public:
    int reverse(int x) {
        int res = 0;

        while (x != 0) {
            int dig = x % 10;
            x /= 10;

            // overflow check BEFORE multiplication
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && dig > 7))
                return 0;

            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && dig < -8))
                return 0;

            res = res * 10 + dig;
        }

        return res;
    }
};


class Solution {
public:
    int reverse(int x) {
        const int MIN = -2147483648; // -2^31
        const int MAX = 2147483647;  // 2^31 - 1

        int res = 0;
        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            if (res > MAX / 10 || (res == MAX / 10 && digit > MAX % 10))
                return 0;
            if (res < MIN / 10 || (res == MIN / 10 && digit < MIN % 10))
                return 0;
            res = (res * 10) + digit;
        }

        return res;
    }
};