class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        int res = 0;
        for (int c: costs) {
            if (coins - c < 0) break;
            coins -= c;
            res++;
        }
        return res;
    }
};