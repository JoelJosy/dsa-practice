class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curralt = 0;
        int maxalt = 0;
        for (int g: gain) {
            curralt += g;
            maxalt = max(maxalt, curralt);
        }

        return maxalt;
    }
};