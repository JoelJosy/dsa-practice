// T: O(nlogn)
// S: O(n)

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;
        // 1 2 2 3 3 4 4 5
        // a 1 2 3 4
        // b 2 3 4 5
        unordered_map<int, int> freq;
        for (int num: hand) freq[num]++;

        priority_queue<int, vector<int>, greater<int>> heap;
        for (auto& [num, count] : freq) 
            heap.push(num);

        while (!heap.empty()) {
            int start = heap.top();
            
            for (int i = start; i < start + groupSize; i++) {
                // if consec not available
                if (freq.find(i) == freq.end()) // if (freq[i] == 0) 
                    return false;
                freq[i]--;

                if (freq[i] == 0) {
                    // if (i != heap.top()) return false; // worked without this
                    heap.pop();
                }
            }

        }
        
        return true;
    }
};

// min heap of elements, calc freq
// min elements MUST start a group
// start with heap top
// iterate from min element to groupsize
// if consec not available return false
// else decrement freq
// if freq 0, pop if top of heap
// else return false (therell be gap in next group)