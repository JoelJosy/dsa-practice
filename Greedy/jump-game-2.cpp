// Time: O(n) 
// Space: O(1)

class Solution {
public:
    int jump(vector<int>& nums) {
        // range of indexes to which u can jump so far
        int l, r; 
        l=r=0;

        int n = nums.size();
        if (n == 1) return 0;
        
        int jumps = 0;
        while (l<=r) {
            int r_next = -1;
            // furthest possible from current level
            for (int i = l; i <= r; i++) 
                r_next = max(r_next, i+nums[i]);
            
            jumps++;
            if (r_next >= n-1) return jumps;
            l = r + 1;
            r = r_next;
        }
        return jumps;
    }
};


// BFS like solution
// At each level, track range of positions u can jump to
// this indicates next level
// Level 0: range jumpable at level 0, i e with 0 jumps
// Level 1: range jumpable with 1 jump
// and so on. return jumps once range reaches end