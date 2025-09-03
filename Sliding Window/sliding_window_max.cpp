// 239. Sliding Window Maximum
// https://leetcode.com/problems/sliding-window-maximum/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deq;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            // pop old window values
            while (!deq.empty() && deq.front() <= i - k) {
                deq.pop_front();
            }

            // insert values if lesser 
            // else pop until lesser
            while (!deq.empty() && nums[i] > nums[deq.back()]) {
                deq.pop_back();
            }
            deq.push_back(i);

            // output deq front
            if (i >= k - 1) {
                res.push_back(nums[deq.front()]);
            }
        }
        return res;
    }
};


// Heap

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> heap;
        vector<int> output;
        for (int i = 0; i < nums.size(); i++) {
            heap.push({nums[i], i});
            if (i >= k - 1) {
                while (heap.top().second <= i - k) {
                    heap.pop();
                }
                output.push_back(heap.top().first);
            }
        }
        return output;
    }
};