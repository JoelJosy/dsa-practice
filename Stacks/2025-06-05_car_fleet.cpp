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



// Another solution
int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int,int>> cars;
    for (int i = 0; i < position.size(); i++) {
        cars.push_back({position[i], speed[i]});
    }

    sort(cars.begin(), cars.end(), greater<>());

    int fleets = 0;
    double lastTime = 0;

    for (auto &car : cars) {
        double time = (double)(target - car.first) / car.second;

        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }
    }

    return fleets;
}

