// T: O(n)
// S: O(1)

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int tank = 0;
        int total = 0;

        for (int i = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i];

            tank += diff;
            total += diff;

            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }

        return total < 0 ? -1 : start;
    }
};


// if sum of diff is negative, return -1
// if diff is negative at i, i+1 not possible
// check running sum, it must never become negative
// if start at i, fails at j, no valid start at [i, j] 

// if sum of diff is negative, return -1
// if diff is negative at i, i+1 not possible
// check running sum, it must never become negative
// if start at i, fails at j, no valid start at [i, j] 

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff;
        for (int i = 0; i < gas.size(); i++) 
            diff.push_back(gas[i] - cost[i]);

        if (accumulate(diff.begin(), diff.end(), 0) < 0) return -1;

        // gas:   1, 2, 3, 4, 5
        // cost:  3, 4, 5, 1, 2
        // diff: -2,-2,-2, 3, 3
        int tank = 0;
        int start = -1;
        
        for (int i = 0; i < diff.size(); i++) {
            if (tank + diff[i] >= 0) {
                tank += diff[i];
                if (start == -1) start = i;
            } else {
                start = -1;
                tank = 0;
            }
        }
        return start;
    }
};


