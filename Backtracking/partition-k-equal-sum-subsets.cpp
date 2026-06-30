// T: O(k^n)
// S: O(k+n)
class Solution {
public:
    int target;
    bool backtrack(int i, vector<int>& buckets, vector<int>& nums) {
        int n = nums.size();
        int k = buckets.size();

        if (i == n) {
            for (auto& b: buckets)
                if (b != 0) return false;
            return true;
        }

        for (int b = 0; b < k; b++) {
            if (buckets[b] - nums[i] < 0) 
                continue;
            if (b > 0 && buckets[b] == buckets[b-1])
                continue;

            buckets[b] -= nums[i];
            if (backtrack(i + 1, buckets, nums))
                return true;
            buckets[b] += nums[i];
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        
        target = sum / k;
        vector<int> buckets(k, target);

        sort(nums.begin(), nums.end(), greater<>());
        return backtrack(0, buckets, nums);
    }
};