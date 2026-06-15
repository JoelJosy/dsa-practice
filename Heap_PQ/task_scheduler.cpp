// 621. Task Scheduler
// https://leetcode.com/problems/task-scheduler/

// Greedy O(n) solution

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char task : tasks) {
            count[task - 'A']++;
        }

        sort(count.begin(), count.end());
        int maxf = count[25];
        int idle = (maxf - 1) * n;

        for (int i = 24; i >= 0; i--) {
            idle -= min(maxf - 1, count[i]);
        }
        return max(0, idle) + tasks.size();
    }
};


// Math Soln
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char c: tasks) {
            freq[c-'A']++;
        }
        int maxFreq = *max_element(freq.begin(), freq.end());
        int maxCount = 0;
        for (int f : freq) {
            if (f == maxFreq) {
                maxCount++;
            }
        }

        // Calculate the minimum time required
        // Max partitions: maxFreq - 1 (last letter need not have idles)
        // Each partition has n idles, except the last one which can have less
        // Partition size: n + 1 (task + n idles)

        int slots = (maxFreq - 1) * (n + 1) + maxCount;
        int minTime = max((int)tasks.size(), slots);
        return minTime;
    }
};


// Max Heap
// T: O(t) {O(tlogm but m is max 26 so log26 is constant)}
// S: O(m)
// t -> time
// m -> distinct tasks
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char c: tasks) {
            freq[c]++;
        }

        priority_queue<int> pq;
        for (auto [c, f]: freq) {
            pq.push(f);
        }

        // {remainingCount, timeAvailable}
        queue<pair<int, int>> cooldown;

        int time = 0;

        while (!pq.empty() || !cooldown.empty()) {
            time++;
            
            if (!cooldown.empty() && cooldown.front().second == time) {
                pq.push(cooldown.front().first);
                cooldown.pop();
            }
            
            if (!pq.empty()) {
                int freq = pq.top();
                pq.pop();
                freq--;
                if (freq > 0)
                    cooldown.push({freq, time + n + 1});
            } 

        }
        return time;
    }
};



class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char c: tasks) {
            freq[c]++;
        }

        priority_queue<int> pq;
        for (auto [c, f]: freq) {
            pq.push(f);
        }

        int res = 0;

        while (!pq.empty()) {
            vector<int> remaining;
            int cycle = n+1;

            while (cycle && !pq.empty()) {
                int max_freq = pq.top();
                pq.pop();
                res++;
                if (max_freq-1 > 0) {
                    remaining.push_back(max_freq-1);
                }
                cycle--;
            }

            for (int f: remaining) {
                pq.push(f);
            }
            if (pq.empty()) break;
            res += cycle;
        }

        return res;
    }
};