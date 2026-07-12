// T: O(n * sum(weights))
// S: O(1)
class Solution {
public:
    bool canShip(int cap, vector<int>& weights, int maxdays) {
        int days = 1;
        int currsum = 0;
        for (int w: weights) {
            currsum += w;
            if (currsum > cap) {
                days++;
                currsum = w;
                if (days > maxdays) 
                    return false;
            }
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int mincap = 0;
        int maxcap = 0;
        for (int w: weights) {
            mincap = max(w, mincap);
            maxcap += w;
        }

        int l = mincap;
        int r = maxcap;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (!canShip(mid, weights, days)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};