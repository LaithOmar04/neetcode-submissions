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
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.end < b.end;
        });

        for(int i = 0; i+1 < intervals.size(); ++i) {
            // if they intersect
            if(intervals[i].end > intervals[i+1].start && intervals[i].end < intervals[i+1].end) return false;
            // if they are the same start & end
            if(intervals[i].start == intervals[i+1].start && intervals[i].end == intervals[i+1].end) return false;
        }

        return true;
    }
};
