// T: O(n)
// S: O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

// T: O(n)
// S: O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        deque<int> dq(nums.begin(), nums.end());
        while (k--) {
            dq.push_front(dq.back());
            dq.pop_back();
        }
        nums.assign(dq.begin(), dq.end());
    }
};