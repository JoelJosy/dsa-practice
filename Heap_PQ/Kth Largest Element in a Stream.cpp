// Kth Largest Element in a Stream
// https://leetcode.com/problems/kth-largest-element-in-a-stream/

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> heap; // Min-heap to keep track of the k largest elements
    // The top of the heap will be the kth largest element
    // If the heap size exceeds k, we pop the smallest element to maintain only k largest
    // elements in the heap.
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num: nums) {
            heap.push(num);
            if (heap.size() > k) {
                heap.pop();  // pushes top k elements
            }
        }
    }
    
    int add(int val) {
        heap.push(val);
        if (heap.size() > k) {
            heap.pop(); 
        }
        return heap.top();
    }
};


/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */