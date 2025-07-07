// 152. maximum product subarray
// https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0];
        int currProduct = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            currProduct = max(nums[i], currProduct * nums[i]);
            maxProduct = max(maxProduct, currProduct);
        }

        return maxProduct;

    }
};