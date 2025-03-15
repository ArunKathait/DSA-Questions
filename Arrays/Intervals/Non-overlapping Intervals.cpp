
class Solution {// TC--->O(N) + O(NLogN)                           SC-->O(N)
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // If there are no intervals, return 0 (nothing to remove)
        if(n == 0)
        {
            return 0;
        }

        // Variable to store the count of intervals that need to be removed
        int ans = 0;

        // Lambda function to define the sorting criteria
        // Sorting intervals based on their ending time (second element)
        auto mycomp = [](vector<int>&a ,vector<int>&b)
        {
            // Sort intervals by their ending times in ascending order
            return a[1] < b[1];
        };
        
        // Sorting the intervals using the custom comparator
        sort(intervals.begin(),intervals.end(),mycomp);

        // `last` stores the end time of the last non-overlapping interval
        int last = intervals[0][1];

        // Iterate through the sorted intervals starting from the second interval
        for(int i=1;i<n;i++)
        {
            // If the current interval's start time is less than `last`, it overlaps
            if(intervals[i][0] < last)
            {
                // Increment the count of intervals to be removed
                ans++;
            }
            else 
            {
                // If there is no overlap, update `last` to the end of the current interval
                last = intervals[i][1];
            }
        }

        // Return the number of removed intervals
        return ans;
    }
};
