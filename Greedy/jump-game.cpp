// Time: O(n)
// Space: O(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;

        for (int i = 0; i < n; i++) {
            if (i <= farthest) {
                // reachable
                farthest = max(farthest, i+nums[i]);
            } else {
                // unreachable
                return false;
            }
        }
        return true;
    }
};

// some indexes may not be reachable
// hence, iterating through array and checking 
// if end is reachable from each is not correct
// eg: [1,2,1,0,1], last index is not reachable

// 1. Iterate from reverse,
// check if reachable to end
// update end if true
// return false if not

// 2. Iterate, track farthest u can go at each step
// if i > farthest => i is unreachable
// else update farthest
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int goal = n-1;

        for (int i = n-2; i >= 0; i--) {
            if (i + nums[i] >= goal) {
                // reachable, update goal
                goal = i;
            } 
        }

        if (goal == 0) return true;
        return false;
    }
};
