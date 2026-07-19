class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        int maxlen = 0;
        int flips = 0;
        while (r < n) {
            if (nums[r] == 0) {
                flips++;
            }

            while (flips > k) {
                if (nums[l] == 0)
                    flips--;
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};