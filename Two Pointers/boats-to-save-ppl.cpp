// T: O(nlogn)
// S: O(1)
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        
        int l = 0;
        int r = n - 1;
        int boats = 0;
        while (l <= r) {
            // see if heaviest can be paired
            int remaining = limit - people[r];
            r--;
            if (people[l] <= remaining) {
                remaining -= people[l];
                l++;
            }
            boats++;
        }
        return boats;
    }
};