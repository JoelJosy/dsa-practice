// Time: O(nlogn)
// Space: O(n)

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n==0) return 0;

        sort(intervals.begin(), intervals.end(),
            [](const Interval& a, const Interval& b) {
                return a.start < b.start;
            });

        // min heap of end times
        priority_queue<int, vector<int>, greater<int>> ends;
        ends.push(intervals[0].end);
        int start = intervals[0].start;
        for (int i = 1; i < n; i++) {
            start = intervals[i].start;

            // if earliest ending meeting ends before this starts
            // free that room
            if (ends.top() <= start) {
                ends.pop();
            }
            ends.push(intervals[i].end);
        }
        return ends.size();
    }
};

// Alternative
// track number of active meetings through out
// return max value of this
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<int> starts;
        vector<int> ends;

        for (auto& curr: intervals) {
            starts.push_back(curr.start);
            ends.push_back(curr.end);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        // starts: 0  5 15 
        // ends:  10 20 40
        int activeMeetings = 0;
        int s = 0;
        int e = 0;
        int res = 0;
        while (s < n) {
            // new starts and none has ended
            if (starts[s] < ends[e]) {
                s++;
                activeMeetings++;
            }
            // new starts after one ends
            else if (starts[s] >= ends[e]) {
                e++;
                activeMeetings--;
            }
            res = max(res, activeMeetings);
        }
        return res;
    }
};


// start time -> +1 new meeting
// end time -> -1 meeting