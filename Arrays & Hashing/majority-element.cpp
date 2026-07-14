// T: O(n)
// S: O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c1 = 0;
        int n1 = -1;
        for (int num: nums) {
            if (num == n1) {
                c1++;
            } else if (c1 == 0) {
                c1++;
                n1 = num;
            } else 
                c1--;
        }
        return n1;
    }
};