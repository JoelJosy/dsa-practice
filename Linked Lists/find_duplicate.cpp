// 287. Find the Duplicate Number
// https://leetcode.com/problems/find-the-duplicate-number/

// Approaches: 
// HashSet O(n) time, O(n) space
// check for count while inserting, this is O(1)
class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.find(num) != seen.end()) {
                return num;
            }
            seen.insert(num);
        }
        return -1;
    }
};

// Fast and Slow Pointers O(n) time, O(1) space
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }

        int slow2 = 0;
        while (true) {
            slow = nums[slow];
            slow2 = nums[slow2];
            if (slow == slow2) {
                return slow;
            }
        }
    }
};

// Negative Marking O(n) time, O(1) space
// Use the fact that numbers are in range 1 to n, so we can use the index as a marker
// For each number, mark the index as negative. If we find a negative number, it
// means we have seen this number before, hence it's a duplicate.
// Note: This modifies the input array, so it may not be suitable for all cases.
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int num : nums) {
            int idx = abs(num) - 1;
            if (nums[idx] < 0) {
                return abs(num);
            }
            nums[idx] *= -1;
        }
        return -1;
    }
};

// Binary Search O(n log n) time, O(1) space
// Check range of values, then find no of vals <= mid, if more than mid then duplicate is in left half, else right half

