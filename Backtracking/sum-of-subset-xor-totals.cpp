class Solution {
public:
    int sum = 0;
    void backtrack(int i, vector<int>& nums, int curr) {
        if (i == nums.size()) {
            sum += curr;
            return;
        }

        backtrack(i + 1, nums, curr);
        backtrack(i + 1, nums, curr ^ nums[i]);
    }

    int subsetXORSum(vector<int>& nums) {
        backtrack(0, nums, 0);
        return sum;
    }
}; 