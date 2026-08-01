class Solution {// TC ---> O(n log n)                                     SC ---> O(1)
public:
    bool canAttend(vector<vector<int>> &arr) {

        // Total number of meetings
        int n = arr.size();

        // Comparator to sort meetings based on their ending time.
        // If two meetings have the same ending time,
        // sort them by their starting time.
        auto myComp = [](vector<int>& a, vector<int>& b)
        {
            if (a[1] == b[1])
            {
                return a[0] < b[0];
            }
            else
            {
                return a[1] < b[1];
            }
        };

        // Sort all meetings according to the comparator.
        sort(arr.begin(), arr.end(), myComp);

        // Store the ending time of the first meeting.
        int last = arr[0][1];

        // Check every remaining meeting.
        for (int i = 1; i < n; i++)
        {
            // If the current meeting starts before the previous
            // meeting ends, the meetings overlap.
            // Therefore, it is impossible to attend all meetings.
            if (last > arr[i][0])
            {
                return false;
            }

            // Update the end time of the last attended meeting.
            last = arr[i][1];
        }

        // No overlapping meetings were found.
        return true;
    }
};
