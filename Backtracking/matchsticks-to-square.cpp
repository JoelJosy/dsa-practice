class Solution {
public:
    bool backtrack(vector<int>& sides, vector<int>& matchsticks, int i) {
        if (i == matchsticks.size()) {
            return true;
        }

        // try each side
        int stick = matchsticks[i];
        for (int s = 0; s < 4; s++) {
            if (sides[s] - stick >= 0) {
                // skip duplicate branches
                if (s > 0 && sides[s] == sides[s-1]) continue;
                
                sides[s] -= stick;
                if (backtrack(sides, matchsticks, i+1))
                    return true;
                sides[s] += stick;
            }
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (total % 4 != 0) return false;
        int target = total / 4;
        
        for (int stick: matchsticks) {
            if (stick > target) return false;
        }

        // side -> len
        vector<int> sides(4, target);
        sort(matchsticks.begin(), matchsticks.end(), greater<>());

        return backtrack(sides, matchsticks, 0);
    }
};