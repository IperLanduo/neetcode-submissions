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
        if(intervals.empty())return 0;
        
        vector<int> startTimes, endTimes;
        for (const auto& interval : intervals) {
            startTimes.push_back(interval.start);
            endTimes.push_back(interval.end);
        }
        
        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());

        int s=0, e=0;
        int count=0, maxRoom=0;

        while(s<intervals.size()){
            if(startTimes[s] < endTimes[e]){
                count ++;
                s++;
            }
            else {
                count --;
                e++;
            }
            maxRoom = max(maxRoom, count);
        }
        return maxRoom;

    }
};
