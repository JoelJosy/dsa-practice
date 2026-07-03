// T: O(n)
// S: O(n)
class StockSpanner {
public:
    stack<pair<int, int>> stk;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        if (stk.empty()) {
            stk.push({price, span});
            return span;
        }

        while (!stk.empty() && price >= stk.top().first) {
            span += stk.top().second;
            stk.pop();
        }

        stk.push({price, span});
        return span;
    }
};

// use spans of prev element to jump across elements
// if new num >= prev, they become useless
// if next num >= new then it skips over the prev
// if not next num is blocked by new
// use stack
// elements are pushed only once, and popped only once


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */