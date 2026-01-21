
class Solution {// TC ---> O(nlogn)                              SC ---> O(1)
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        // Total number of intervals
        int totalIntervals = intervals.size();

        // Sort intervals by:
        // 1) start time ascending
        // 2) end time ascending (default vector sort behavior)
        sort(intervals.begin(), intervals.end());

        // This will store the number of intervals
        // that are NOT covered by any other interval
        int nonCoveredCount = 0;

        // These variables track the range of the
        // last selected (non-covered) interval
        int previousStart = -1;
        int previousEnd   = -1;

        // Traverse all intervals
        for (int i = 0; i < totalIntervals; i++) 
        {
            // Current interval [start, end]
            int currentStart = intervals[i][0];
            int currentEnd   = intervals[i][1];

            /*
                Condition explanation:
                - currentStart > previousStart  → new interval starts later
                - currentEnd   > previousEnd    → new interval extends further

                If both are true:
                → current interval is NOT covered
                → count it
            */
            if (currentStart > previousStart && currentEnd > previousEnd) 
            {
                nonCoveredCount++;
                previousStart = currentStart;
            }

            // Update the farthest end seen so far
            // This helps detect covered intervals
            previousEnd = max(previousEnd, currentEnd);
        }

        // Return number of intervals not covered by others
        return nonCoveredCount;
    }
};
