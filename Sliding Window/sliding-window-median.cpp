// Time: O(nlogk)
// Space: O(k)

class Solution {
public:
    // corresp to maxheap and minheap
    // NOTE: erase(x) removes all occurances of x, so use erase(find())
    multiset<int> lo, hi;

    void rebalance() {
        while (lo.size() > hi.size() + 1) {
            hi.insert(*lo.rbegin());
            lo.erase(lo.find(*lo.rbegin()));
        }
        while (hi.size() > lo.size()) {
            lo.insert(*hi.begin());
            hi.erase(hi.begin());
        }
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        for (int i = 0; i < nums.size(); i++) {
            if (lo.empty() || nums[i] <= *lo.rbegin())
                lo.insert(nums[i]);
            else 
                hi.insert(nums[i]);

            rebalance();

            if (i >= k) {
                int prev = nums[i-k];
                auto it = lo.find(prev);
                if (it != lo.end()) {
                    lo.erase(it);
                } else {
                    hi.erase(hi.find(prev));
                }
                rebalance();
            }

            if (i >= k - 1) {
                if (k % 2 == 1)
                    res.push_back(*lo.rbegin());
                else
                    res.push_back(((double)*lo.rbegin() + *hi.begin()) / 2.0);
            }
        }
        return res;
    }
};