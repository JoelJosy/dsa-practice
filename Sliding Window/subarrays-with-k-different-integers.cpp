// T: O(n)
// S: O(n)
class Solution {
public:
    int atmostK(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        unordered_map<int, int> distinct;
        int ans = 0;

        while (r < nums.size()) {
            distinct[nums[r]]++;

            while (distinct.size() > k) {
                distinct[nums[l]]--;
                if (distinct[nums[l]] == 0) {
                    distinct.erase(nums[l]);
                }
                l++;
            }
            // valid subarrays ending at r
            ans += r - l + 1;
            r++;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostK(nums, k) - atmostK(nums, k-1);
    }
};

// find atmost(k)
// ans = atmost(k) - atmost(k-1)
// atmost(k) in subarray ending at right = right - left + 1