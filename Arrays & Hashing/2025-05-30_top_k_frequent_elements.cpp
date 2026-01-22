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


// Min heap 
// O(nlogk)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Count : <num, freq>

        priority_queue<pair<int, int>, vector<pair<int, int>>, 
                        greater<pair<int, int>>> heap;

        for (const auto& p: freq) {
            heap.push({p.second, p.first});
            if (heap.size() > k) {
                heap.pop();
            }
        }

        for (int i = 0; i < k; i++) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;

    }
};

// Bucket Sort
// O(n)

#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int x : nums) freq[x]++;

    // bucket[i] = all numbers that appear i times
    vector<vector<int>> bucket(nums.size() + 1);
    for (auto &p : freq) {
        bucket[p.second].push_back(p.first);
    }

    vector<int> ans;
    for (int i = nums.size(); i >= 1 && (int)ans.size() < k; i--) {
        for (int x : bucket[i]) {
            ans.push_back(x);
            if ((int)ans.size() == k) break;
        }
    }
    return ans;
}
