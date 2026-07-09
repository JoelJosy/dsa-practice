// T: O(n)
// S: O(1)
class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int swaps = 0;
        int balance = 0;
        int r = n - 1;
        // find first unmatched ]. then swap with last [
        // every ] must have a [ before it

        for (int i = 0; i < n; i++) {
            if (s[i] == '[') balance++;
            else balance--;

            if (balance < 0) {
                while (i < r && s[r] != '[') r--;
                swap(s[r], s[i]);
                swaps++;
                balance = 1;
            }
        }
        return swaps;
    }
};

// Greedy logic
// T: O(n)
// S: O(1)
class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int balance = 0;
        int minBalance = 0;
        // 1 swap fixes 2 brackets

        for (int i = 0; i < n; i++) {
            if (s[i] == '[') balance++;
            else balance--;

            minBalance = min(minBalance, balance);
        }
        minBalance = -minBalance;
        return (minBalance + 1) / 2;
    }
};