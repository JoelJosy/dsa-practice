// Last Stone Weight
// https://leetcode.com/problems/last-stone-weight/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;
        for (int stone: stones) heap.push(stone);

        while(heap.size() > 1) {
            int x = heap.top();
            heap.pop();
            int y = heap.top();
            heap.pop();
            if (x != y) {
                heap.push(abs(x - y));
            }
        }

        return heap.empty() ? 0 : heap.top();
    }
};
