// T: O(logn)
// S: O(logn) for cache
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    // idx, value
    unordered_map<int, int> cache;
    MountainArray *mountains;
    int getVal(int idx) {
        if (cache.count(idx)) {
            return cache[idx];
        }
        return cache[idx] = mountains->get(idx);
    }

    int binSearch(int l, int r, int target, bool lhalf) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = getVal(mid);
            if (val == target) return mid;

            if (lhalf) {
                if (val < target) l = mid + 1;
                else r = mid - 1;
            } else {
                if (val > target) l = mid + 1;
                else r = mid - 1;
            }
        } 
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        mountains = &mountainArr;
        
        // find peak
        int l = 0;
        int r = n - 1;
        int peak;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (l == r) {
                peak = l;
                break;
            }
            if (getVal(mid) > getVal(mid + 1)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        int res = binSearch(0, peak, target, true);
        if (res != -1) return res;
        return  binSearch(peak + 1, n - 1, target, false);
    }
};