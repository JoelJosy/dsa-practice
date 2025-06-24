# Remove Duplicates from Sorted Array
# https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=1;
        int n = nums.size();
        for (j;j<n;j++) {
            if (nums[i] != nums [j]) {
                nums[i+1] = nums[j];
                i++;
            } 
        }

    return i+1;
    }
};