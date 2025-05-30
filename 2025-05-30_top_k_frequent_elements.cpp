# Top K Frequent Elements
# https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        multimap<int, int> ranked;
        for (int num: nums) {
            map[num]++;
        }

        for (auto it: map) {
            ranked.insert({it.second, it.first});
        }

        vector<int> res;
        for (auto it = ranked.rbegin(); it != ranked.rend() && k > 0; ++it, --k) {
            res.push_back(it->second);
        }       
        return res;

    }

};