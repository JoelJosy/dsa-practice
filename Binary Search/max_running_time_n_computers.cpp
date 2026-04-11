// 2141. Maximum Running Time of N Computers
https://leetcode.com/problems/maximum-running-time-of-n-computers/description/

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l = 0;
        long long sum = accumulate(batteries.begin(), batteries.end(), 0LL);
        long long r = sum / n; // max minutes per laptop
        long long ans = 0;

        while (l <= r) {
            long long mid = l + (r-l)/2;

            // check if all laptops can run for mid minutes
            long long maxPossible = 0;
            for (int i = 0; i < batteries.size(); i++) {
                maxPossible += min((long long) batteries[i], mid);
            }
            
            if (maxPossible >= mid*n) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};