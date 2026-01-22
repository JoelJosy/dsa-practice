
int max_kadane(vector<int>& nums) {
    int maxSum = nums[0], currSum = 0;
    for(int x : nums){
        currSum = max(x, currSum + x);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int min_kadane(vector<int>& nums) {
    int minSum = nums[0], currSum = 0;
    for(int x : nums){
        currSum = min(x, currSum + x);
        minSum = min(minSum, currSum);
    }
    return minSum;
}

int maxCircularSubarray(vector<int>& nums) {
    int max_kad = max_kadane(nums);          // Case 1: non-circular
    int total = accumulate(nums.begin(), nums.end(), 0);
    int min_kad = min_kadane(nums);          // Minimum subarray
    int circular = total - min_kad;          // Case 2: circular

    // Handle all-negative case
    if(circular == 0) return max_kad;

    return max(max_kad, circular);
}