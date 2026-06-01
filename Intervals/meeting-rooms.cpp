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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [](const Interval& a, const Interval& b) {
                return a.start < b.start;
            });

        int n = intervals.size();
        for (int i = 0; i < n-1; i++) {
            if (intervals[i].end > intervals[i+1].start) 
                return false;
        }
        return true;
    }
};
