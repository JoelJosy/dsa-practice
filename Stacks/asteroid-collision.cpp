// T: O(n)
// S: O(n)
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;

        for (int ast: asteroids) {
            // if collision
            if (!stk.empty() && stk.back() > 0 && ast < 0) {
                 while (!stk.empty() && stk.back() > 0 && 
                 stk.back() < -ast) {
                    stk.pop_back();
                 }

                 if (stk.empty() || stk.back() < 0) {
                    stk.push_back(ast);
                 } else if (stk.back() == -ast) {
                    stk.pop_back();
                 }
            } else
                stk.push_back(ast);
        }

        return stk;
    }
};