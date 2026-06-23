class MyCircularQueue {
public:
    int cap;
    int size;
    int front;
    int rear;
    vector<int> q;
    MyCircularQueue(int k) {
        cap = k;
        size = 0;
        front = 0;
        rear = -1;
        q.resize(k, -1);
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        
        rear = (rear + 1) % cap;
        q[rear] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % cap;
        size--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return q[front];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return q[rear];
    }
    
    bool isEmpty() {
        if (size == 0) return true;
        return false;
    }
    
    bool isFull() {
        if (size == cap) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */