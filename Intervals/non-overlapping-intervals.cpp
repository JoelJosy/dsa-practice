// Time: O(nlogn)
// Space: O(1) or O(logn) incl recursion stack for sorting

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        sort(intervals.begin(), intervals.end());
        int prevend = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            int currstart = intervals[i][0];
            int currend = intervals[i][1];
            if (currstart < prevend) {
                // overlapping
                prevend = min(prevend, currend);
                count++;
            } else {
                prevend = currend;
            }
        }

        return count;
    }
};

// maximize number of non overlapping intervals 
// For overlapping, Greedily pick intervals with shorter end time
// track end time. thus it finds smallest end time possible
// Smaller end -> more future intervals


// OR
// sort by end time first 
// track which ones to keep
// answer = total - keep

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        
        int n = intervals.size();
        int keep = 1;
        int prevend = intervals[0][1];

        for (int i = 1; i < n; i++) {
            int currstart = intervals[i][0];
            int currend = intervals[i][1];
            if (currstart >= prevend) {
                // non overlapping, then keep
                prevend = currend;
                keep++;
            }
        }


        return n - keep;
    }
};