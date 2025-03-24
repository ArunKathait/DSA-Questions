
class Solution {// TC--->O(NLogN)                       SC--->O(1)
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // Get the number of meetings
        int n = meetings.size();

        // Sort the meetings based on their start time
        sort(meetings.begin(),meetings.end());

        // Not used, can be removed
        int start = 0;

        // Keeps track of the last occupied day
        int end = 0;

        // Variable to store the count of free days
        int ans = 0;

        // Iterate through all meetings
        for(auto &meeting : meetings)
        {
            // meeting[0] is the start day of the current meeting
            // meeting[1] is the end day of the current meeting

             // If there is a gap between the end of the last meeting and the start of the current meeting
            if(end < meeting[0])
            {
                // Add the free days between meetings
                ans += (meeting[0] - end - 1);
            }

            // Update `end` to track the last occupied day
            end = max(end,meeting[1]);
        }

        // Count the free days after the last meeting until `days`
        if(end < days)
        {
            ans += (days - end);
        }

        // Return the total number of free days
        return ans;
        
    }
};
