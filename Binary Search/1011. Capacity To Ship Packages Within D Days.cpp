
// TC ---> O(N × log(S))       where N = number of packages, S = sum(weights) − max(weights)
// SC ---> O(1)
class Solution {
public:
    // Helper function to determine how many days are needed 
    // if the ship has a given capacity 'mid'
    int check(vector<int>& weights, int mid)
    {
        int days = 1;   // start with 1 day
        int load = 0;   // current day's total load

        // Traverse through all package weights
        for (auto w : weights)
        {
            // If adding this weight exceeds ship capacity,
            // it means we need an extra day
            if (load + w > mid)
            {
                days++;      // move to next day
                load = w;    // start new day with current weight
            }
            else
            {
                load += w;   // otherwise, keep adding to current day
            }
        }

        // Return total days required for given ship capacity
        return days;
    }

    // Main function to find the minimum capacity of ship 
    // to deliver all packages within given number of days
    int shipWithinDays(vector<int>& weights, int days)
    {
        int n = weights.size();

        // Minimum possible capacity = heaviest single package
        int low = *max_element(weights.begin(), weights.end());

        // Maximum possible capacity = sum of all package weights
        int high = accumulate(weights.begin(), weights.end(), 0);
        
        int ans = 0;  // to store the final (minimum) capacity result

        // Binary search over possible capacity range
        while (low <= high)
        {
            int mid = low + (high - low) / 2;  // mid capacity (try this ship size)

            // Calculate how many days are needed with this capacity
            int numberOfDays = check(weights, mid);

            // If it can be done in the allowed number of days or fewer
            // then this capacity might be sufficient — try smaller one
            if (numberOfDays <= days)
            {
                ans = mid;       // store current possible answer
                high = mid - 1;  // try to minimize capacity
            }
            else
            {
                // If it takes more than 'days' days, capacity too small
                low = mid + 1;   // increase ship capacity
            }
        }

        // Return the smallest capacity that meets the requirement
        return ans;
    }
};
