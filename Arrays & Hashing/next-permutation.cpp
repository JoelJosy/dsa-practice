// T: O(n)
// S: O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return;
        int pivot = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
        } else {
            for (int i = n - 1; i > pivot; i--) {
                if (nums[pivot] < nums[i]) {
                    swap(nums[pivot], nums[i]);
                    break;
                }
            }
            reverse(nums.begin() + pivot + 1, nums.end());
        }
    }
};

// find element where nums[i] < nums[i+1]
// thats the pivot, swap with least num > pivot from right half 
// this is the smallest change possible

// 1 2 6 5 3
//   |     |
// 1 3 6 5 2
// reverse suffix
// 1 3 2 5 6