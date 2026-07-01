// DP + Sliding Window
// check from which index before could we have reached curr idx
// update counts based on sliding window of ranges
// T: O(n)
// S: O(n)
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        vector<bool> dp(n, false);
        dp[0] = true;

        int count = 0; // number of reachable indices in window

        for (int i = 1; i < n; i++) {

            // add reachable index entering window
            if (i - minJump >= 0 && dp[i - minJump])
                count++;

            // remove index leaving window
            if (i - maxJump - 1 >= 0 && dp[i - maxJump - 1])
                count--;

            // decide reachability
            if (s[i] == '0' && count > 0)
                dp[i] = true;
        }

        return dp[n - 1];
    }
};


// BFS
// from each zero, push reachable zeroes into queue
// to prevent overlapping range scans,
// maintain a farthest pointer, denoting farthest index scanned
// T: O(n) (without farthest -> O(n * range))
// S: O(n)
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        queue<int> q;
        q.push(0);

        int farthest = 0;

        while (!q.empty()) {
            int curr = q.front(); q.pop();
            if (curr == n - 1) return true;

            int start = max(curr + minJump, farthest + 1);
            int end = min(n - 1, curr + maxJump);

            for (int j = start; j <= end; j++) {
                if (s[j] == '0') {
                    q.push(j);
                }
                farthest = j;
            }
        }

        return false;
    }
};


