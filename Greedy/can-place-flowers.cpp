// T: O(n)
// S: O(1)
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size();
        if (n == 0) return true;
        
        for (int i = 0; i < sz; i++) {
            if (flowerbed[i] == 0 &&
                (i == 0 || flowerbed[i-1] == 0) &&
                (i == sz-1 || flowerbed[i+1] == 0)) {

                flowerbed[i] = 1;
                n--;
            }

            if (n == 0) return true;
        }
        return false;
    }
};
