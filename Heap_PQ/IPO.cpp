// T: O((n+k)*logn)
// S: O(n)
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = capital.size();

        // {capital, profit}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > minheap; 

        // {profit, capital}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>
        > maxheap;

        for (int i = 0; i < n; i++) {
            minheap.push({capital[i], profits[i]});
        }

        for (int i = 0; i < k; i++) {
            while (!minheap.empty()) {
                auto [cap, prof] = minheap.top(); 
                if (cap <= w) {
                    maxheap.push({prof, cap});
                    minheap.pop();
                } else break;
            }

            if (!maxheap.empty()) {
                auto [prof, cap] = maxheap.top(); maxheap.pop();
                w += prof;
            }
        }

        return w;
    }
};


// Slightly cleaner:
// Sort by capital first, then use 1 max heap
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        vector<pair<int, int>> projects;
        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }

        sort(projects.begin(), projects.end());

        priority_queue<int> maxHeap;
        int i = 0;

        while (k--) {
            // Add all affordable projects
            while (i < n && projects[i].first <= w) {
                maxHeap.push(projects[i].second);
                i++;
            }

            // No affordable project left
            if (maxHeap.empty())
                break;

            // Take the most profitable one
            w += maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};