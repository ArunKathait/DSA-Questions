
class Solution {// TC ---> O(NlogN)                              SC ---> O(1)
public:

    // -------------------------------------------------
    // Function to check whether current energy (mid)
    // is sufficient to complete all tasks
    // -------------------------------------------------
    bool isPossible(vector<vector<int>>& tasks, int mid)
    {
        // Traverse all tasks
        for(int i = 0; i < tasks.size(); i++)
        {
            // actual = energy consumed after completing task
            int actual = tasks[i][0];

            // minimum = minimum energy required
            // before starting the task
            int minimum = tasks[i][1];

            // -----------------------------------------
            // If current energy is less than required
            // we cannot perform this task
            // -----------------------------------------
            if(minimum > mid)
            {
                return false;
            }

            // -----------------------------------------
            // Perform task
            // Energy decreases by actual consumption
            // -----------------------------------------
            mid -= actual;
        }

        // All tasks completed successfully
        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {

        int n = tasks.size();

        // -------------------------------------------------
        // Sort tasks based on:
        // (minimum - actual) in descending order
        //
        // Why?
        //
        // Tasks having larger extra requirement
        // should be done earlier.
        //
        // Example:
        //
        // actual = 1, minimum = 10
        // difference = 9
        //
        // This task is harder to start later,
        // so we perform it early.
        // -------------------------------------------------
        auto lambda = [](vector<int> task1, vector<int> task2)
        {
            int diff1 = task1[1] - task1[0];
            int diff2 = task2[1] - task2[0];

            return diff1 > diff2;
        };

        // Sort tasks optimally
        sort(tasks.begin(), tasks.end(), lambda);

        // -------------------------------------------------
        // Binary Search on Answer
        //
        // We are searching minimum initial energy
        // required to finish all tasks.
        // -------------------------------------------------

        int low = 0;
        int high = 1e9;

        int ans = -1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            // -----------------------------------------
            // If current energy is sufficient
            // try smaller answer
            // -----------------------------------------
            if(isPossible(tasks, mid))
            {
                ans = mid;

                high = mid - 1;
            }
            else
            {
                // Need more energy
                low = mid + 1;
            }
        }

        // Minimum possible initial energy
        return ans;
    }
};
