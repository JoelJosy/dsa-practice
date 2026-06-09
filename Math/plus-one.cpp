// T: O(n)
// S: O(1)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty())
            return {1};
            
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i] = digits[i] + 1;
                return digits;
            } 
            
            digits[i] = 0;
        }
        
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
