# Koko Eating Bananas
# https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = 0;
        for (int num: piles) {
            if (num > max) max = num;
        }
        
        int l = 1;
        int u = max;
        int k = u;
        int m = 0;
        while (l <= u) {
            m = l + (u - l) / 2;
            
            long long totalT = 0;
            for (int num: piles) {
                totalT += (num + m - 1) / m;
            }

            if (totalT <= h) {
                k = m;
                u = m - 1;
            } else {
                l = m + 1;
            }
        }

        return k;
    }
};