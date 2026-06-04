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
        int res = 0;

        while (x != 0) {
            int dig = x % 10;
            x /= 10;

            // check overflow
            if (res > INT_MAX/10 || (res == INT_MAX / 10 - dig))
                return 0;
            if (res < INT_MIN/10 || (res == INT_MIN / 10 + dig))
                return 0;

            res = res * 10 + dig;
        }

        return res;
    }
};
