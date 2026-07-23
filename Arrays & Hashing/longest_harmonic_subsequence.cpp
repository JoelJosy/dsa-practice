// Map
// T: O(n)
// S: O(n)
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num: nums) freq[num]++;

        int res = 0;

        for (auto& [num, f]: freq) {
            if (freq.count(num+1)) {
                res = max(res, freq[num+1] + f);
            }
        }
        return res;
    }
};

// Sliding Window
// T: O(nlogn)
// S: O(1)
class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        if (n == 1) return 0;

        int res = 0;
        int l = 0, r = 0;

        while (r < n) {
            while (nums[r] - nums[l] > 1)
                l++;

            if (nums[r] - nums[l] == 1) {
                res = max(res, r - l + 1);
            }
            r++;
        }

        return res;
    }
};
//  1 1 2 2 2 3 3 5 7