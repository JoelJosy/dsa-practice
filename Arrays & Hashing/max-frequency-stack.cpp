// T: Push and Pop O(1)
class FreqStack {
public:
    // num, freq
    unordered_map<int, int> freq;
    // freq, nums stack
    unordered_map<int, stack<int>> group;
    int maxFreq = 0;
    
    FreqStack() {
    }
    
    void push(int val) {
        freq[val]++;
        group[freq[val]].push(val);
        maxFreq = max(maxFreq, freq[val]);
    }
    
    int pop() {
        int res = group[maxFreq].top();
        group[maxFreq].pop();
        freq[res]--;
        if (group[maxFreq].empty()) {
            maxFreq--;
        }

        return res;
    }
};

// one map for num->freq
// another for freq->stack of nums