
class Solution {// TC ---> O(n log n)                    SC ---> O(n)
public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {

        int n = start.size();

        // Store all meetings as {startTime, endTime}
        vector<vector<int>> intervals;

        for (int i = 0; i < n; i++)
        {
            intervals.push_back({start[i], end[i]});
        }

        // Sort meetings according to their start time.
        sort(intervals.begin(), intervals.end());

        // Min Heap:
        // Stores the end times of meetings that are currently using rooms.
        //
        // Top of the heap = earliest meeting to finish.
        priority_queue<int, vector<int>, greater<int>> pq;

        // Process meetings one by one.
        for (auto &meeting : intervals)
        {
            // If the meeting that finishes the earliest
            // has already ended before the current meeting starts,
            // then we can reuse that room.
            if (!pq.empty() && pq.top() <= meeting[0])
            {
                pq.pop();
            }

            // Allocate a room for the current meeting.
            // Push its ending time into the heap.
            pq.push(meeting[1]);
        }

        // Number of end times left in the heap
        // equals the number of rooms currently occupied.
        return pq.size();
    }
};
