// T: O(m log m + m log n)
// S: O(n)
// m -> no of meetings
// m -> no of rooms
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> free;
        priority_queue<
            pair<long long, int>, 
            vector<pair<long long, int>>, 
            greater<pair<long long, int>>
        > busy;

        for (int i = 0; i < n; i++) free.push(i);

        vector<int> counts(n, 0);
        for (vector<int>& curr: meetings) {
            int start = curr[0];
            int end = curr[1];

            while (!busy.empty() && busy.top().first <= start) {
                auto [topend, toproom] = busy.top(); busy.pop();
                free.push(toproom);
            }

            if (!free.empty()) {
                int room = free.top(); free.pop();
                counts[room]++;
                busy.push({end, room});
            } else {
                auto [topend, toproom] = busy.top(); busy.pop();
                long long newEnd = topend + (end - start);
                counts[toproom]++;
                busy.push({newEnd, toproom});
            }
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (counts[i] > counts[ans])
                ans = i;
        }
        return ans;
    }
};