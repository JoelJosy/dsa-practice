// T: O(n)
// S: O(1)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            while (x >= 1 && x <= n && 
                x != nums[x-1]) { // check if alr in correct place
                swap(nums[i], nums[x-1]);
                x = nums[i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] == i + 1) continue;
            return i+1;
        }
        return n+1;
    }
};

// answer is in [1...n+1]
// rearrange array to correct indices
// go through array, from 1 to n
// if expected is found, continue
// else return expected