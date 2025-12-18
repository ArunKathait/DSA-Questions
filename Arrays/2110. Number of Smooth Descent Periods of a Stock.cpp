
class Solution {// TC--->O(N)                         SC--->O(1)
public:
    long long getDescentPeriods(vector<int>& prices) {

        // Total number of days
        int n = prices.size();

        // ans will store the final answer (total descent periods)
        // We start with 1 because a single day itself is always a valid descent period
        long long ans = 1;

        // count keeps track of the length of the current continuous descent sequence
        // Initially, a single element counts as length 1
        int count = 1;

        // Start from the second day
        for(int i = 1; i < n; i++)
        {
            // Check if current price is exactly 1 less than previous price
            // This means the descent condition is satisfied
            if(prices[i - 1] - prices[i] == 1)
            {
                // Extend the current descent sequence
                count++;
            }
            else
            {
                // Descent breaks, reset count to 1 (current day alone)
                count = 1;
            }

            // Add the number of descent periods ending at day i
            // For example, if count = 3, then there are 3 descent subarrays
            // ending at this index
            ans += count;
        }

        // Return the total number of descent periods
        return ans;
    }
};
