# Car Fleet
# https://leetcode.com/problems/car-fleet/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, int, greater<int>> map;
        for (int i = 0; i < position.size(); ++i) {
            map[position[i]] = speed[i]; 
        }

        vector<double> stack;
        double time;
        for (auto it: map) {
            time = (double) (target - it.first) / it.second;
            stack.push_back(time);
            int n = stack.size();
            if (n >= 2 && stack[n-1] <= stack[n-2]) {
                stack.pop_back();
            }
        }
        return stack.size();

    }
};