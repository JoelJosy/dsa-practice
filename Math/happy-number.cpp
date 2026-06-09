// Space optimized O(1)
class Solution {
public:
    int getsum(int n) {
        int res = 0;
        while (n > 0) {
            int dig = n % 10;
            n /= 10;
            res += dig * dig;
        }
        return res;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = getsum(n);

        while (fast != slow) {
           slow = getsum(slow);
           fast = getsum(fast);
           fast = getsum(fast);
        }

        return fast == 1;
    }
};


// Time and Space: O(logn)
class Solution {
public:
    int getsum(int n) {
        int res = 0;
        while (n > 0) {
            int dig = n % 10;
            n /= 10;
            res += dig * dig;
        }
        return res;
    }

    bool isHappy(int n) {
        unordered_set<int> visit;

        while (visit.find(n) == visit.end()) {
            visit.insert(n);
            n = getsum(n);
            if (n == 1) return true;
        }
        return false;
    }
};
