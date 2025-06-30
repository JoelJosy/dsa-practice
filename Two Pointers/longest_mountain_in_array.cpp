// 845. Longest Mountain in Array
// https://leetcode.com/problems/longest-mountain-in-array/

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans = 0;
        for (int i = 1; i < arr.size() - 1; i++) {
            if (arr[i-1] < arr[i] && arr[i] > arr[i+1]) {
                int l = i - 1;
                int r = i + 1;
                while (l-1 >= 0 && arr[l] > arr[l-1]) l--;
                while (r+1 < arr.size() && arr[r] > arr[r+1]) r++;
                ans = max(ans, r-l+1);
            }
        }

        return ans;
    }
};