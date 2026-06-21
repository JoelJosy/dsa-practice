// T: O(logn)
// S: O(logn)
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (n == 0) return 1;

        if (n < 0) {
            x = 1 / x;
            n = -n;
        }

        double half;
        if (n % 2 == 0) {
            half = myPow(x, n/2);
            half *= half;
        } else {
            half = myPow(x, (n - 1)/2);
            half = x * half * half;
        }

        return half;
    }
};

// if n even:
//    x^n = (x^{n/2})^2
// else:
//    x^n = x * (x^{(n-1)/2})^2