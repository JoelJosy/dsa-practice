// T O(n)
// S O(1) both solns

// one pass optimal
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;
        while (mid <= high) {
            if (nums[mid] == 1) {
                mid++;
            } else if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

// all 0s before low
// all 2s after high
// all 1s between

// Two pass hashset 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int n: nums) {
            freq[n]++;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (freq[0] > 0) {
                nums[i] = 0;
                freq[0]--;
            } else if (freq[1] > 0) {
                nums[i] = 1;
                freq[1]--;
            } else if (freq[2] > 0) {
                nums[i] = 2;
                freq[2]--;
            }
        }
    }
};