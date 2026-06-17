// Heap
// T: O(Nlogk) n-> total number of elements
// S: O(logk)
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // min num, idx, list idx
        priority_queue<
            tuple<int, int, int>, 
            vector<tuple<int, int, int>>, 
            greater<tuple<int, int, int>>
        > heap;

        // push all minimums and track candidate range
        int currmax = INT_MIN;
        int k = 0;
        for (auto& num: nums) {
            currmax = max(currmax, num[0]);
            heap.push({num[0], 0, k});
            k++;
        }
        k++; // size of nums

        auto [bestL, idx, listidx] = heap.top();
        int bestR = currmax;
        while (!heap.empty()) {
            auto [num, i, listidx] = heap.top(); heap.pop();

            if (currmax - num < bestR - bestL) {
                bestR = currmax;
                bestL = num;
            }

            i++;
            if (i >= nums[listidx].size()) break;

            int next = nums[listidx][i];
            currmax = max(currmax, next);

            heap.push({next, i, listidx});
            
        }

        return {bestL, bestR};
    }
};

// similar to merge k sorted lists
// pick min from each list
// min determines lower bound, max upper bound
// increase min, to decrease range


// Sliding window
// T: O(NlogN)
// S: O(N)
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // flatten array
        vector<pair<int, int>> arr;
        int k = nums.size();

        for (int listId = 0; listId < k; listId++) {
            for (int val : nums[listId]) {
                arr.push_back({val, listId});
            }
        }

        sort(arr.begin(), arr.end());

        // listidx, freq
        unordered_map<int,int> freq;
        // distinct listidx covered
        int covered = 0;

        int l = 0, r = 0;
        int bestL = 0;
        int bestR = INT_MAX;
        while (r < arr.size()) {
            int ridx = arr[r].second;

            freq[ridx]++;
            if (freq[ridx] == 1) 
                covered++;

            while (covered == k) {
                int currL = arr[l].first;
                int currR = arr[r].first;
                if ((currR - currL < bestR - bestL) ||
                    (currR - currL == bestR - bestL && currL < bestL)) {
                    bestL = currL;
                    bestR = currR;
                }

                int lidx = arr[l].second;
                freq[lidx]--;
                if (freq[lidx] == 0)
                    covered--;
                l++;
            }
            r++;
        }
        return {bestL, bestR};
    }
};

// if arrays flattened, and sorted (along with listidx beside)
// we need to find min window with all listidxs
// like min window substring