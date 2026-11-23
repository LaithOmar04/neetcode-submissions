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
        for(int i = 0; i < intervals.size(); ++i) {
            for(int j = i+1; j < intervals.size(); ++j) {
                if((intervals[j].start < intervals[i].end && intervals[j].start >= intervals[i].start) || (intervals[j].end > intervals[i].start && intervals[j].end <= intervals[i].end)) return false;
            }
        }

        return true;
    }
};
