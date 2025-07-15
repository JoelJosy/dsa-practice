// 295 Find Median From Data Stream
// https://leetcode.com/problems/find-median-from-data-stream/
class MedianFinder {
public:
    priority_queue<int> maxHeap; // left half
    priority_queue<int, vector<int>, greater<int>> minHeap; // right half

    MedianFinder() {
    }
    
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // balance heaps
        if (maxHeap.size() < minHeap.size()) {
            int top = minHeap.top();
            minHeap.pop();
            maxHeap.push(top);
        } else if (maxHeap.size() - minHeap.size() > 1) {
            int top = maxHeap.top();
            maxHeap.pop();
            minHeap.push(top);
        }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            return (maxHeap.top());
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */