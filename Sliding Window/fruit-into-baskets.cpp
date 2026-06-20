// T: O(n)
// S: O(1)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0;
        int res = 0;
        
        // fruit, count
        unordered_map<int, int> types;

        for (int r = 0; r < fruits.size(); r++) {
            types[fruits[r]]++;

            while (types.size() > 2) {
                types[fruits[l]]--;
                if (types[fruits[l]] == 0)
                    types.erase(fruits[l]);
                l++;
            }

            res = max(res, r - l + 1);
        }   
        return res;
    }
};