// T: O(n)
// O(1)

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();

        // track prev changed
        vector<int> prev(3, -1);
        
        for (int i = 0; i < n; i++) {
            if (triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2]) continue;
            
            // if prev uninitialized
            if (prev[0] == -1) {
                prev = triplets[i];
                if (prev == target) return true;
                continue;
            } else {
                if (prev == target) return true;
            }

            prev[0] = max(prev[0], triplets[i][0]);
            prev[1] = max(prev[1], triplets[i][1]);
            prev[2] = max(prev[2], triplets[i][2]);
            
        }
        if (prev == target) return true;
        return false;
    }
};

// Simpler
// Slightly better space

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool a = false, b = false, c = false;

        for (auto& t : triplets) {
            if (t[0] > target[0] ||
                t[1] > target[1] ||
                t[2] > target[2])
                continue;

            if (t[0] == target[0]) a = true;
            if (t[1] == target[1]) b = true;
            if (t[2] == target[2]) c = true;
        }

        return a && b && c;
    }
};