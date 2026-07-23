
class Solution {// TC ---> O(NLogN)                      SC ---> O(1)
public:

    // This function checks whether it is possible to place
    // 'k' cows such that the minimum distance between
    // any two cows is at least 'minAllowedDist'.
    bool isPossible(vector<int>& arr, int minAllowedDist, int k)
    {
        // Place the first cow in the first stall.
        int cows = 1;

        // Store the position of the last placed cow.
        int lastPosition = arr[0];

        // Try placing the remaining cows.
        for (int i = 1; i < arr.size(); i++)
        {
            // If the distance between the current stall
            // and the last occupied stall is at least
            // the required minimum distance,
            // place another cow here.
            if (arr[i] - lastPosition >= minAllowedDist)
            {
                cows++;
                lastPosition = arr[i];
            }

            // If all k cows have been placed successfully,
            // then this minimum distance is possible.
            if (cows == k)
            {
                return true;
            }
        }

        // Not enough cows could be placed.
        return false;
    }

    int aggressiveCows(vector<int> &arr, int k)
    {
        int n = arr.size();

        // Sort the stall positions because cows
        // must be placed from left to right.
        sort(arr.begin(), arr.end());

        // Minimum possible distance between two cows.
        int low = 1;

        // Largest stall position.
        int maxi = arr[n - 1];

        // Smallest stall position.
        int mini = arr[0];

        // Maximum possible minimum distance.
        // (Distance between first and last stall.)
        int high = maxi - mini;

        int ans = 0;

        // Binary Search on the answer (minimum distance).
        while (low <= high)
        {
            // Assume 'mid' is the minimum distance
            // between any two cows.
            int mid = low + (high - low) / 2;

            // Check whether we can place all cows
            // while maintaining at least 'mid' distance.
            if (isPossible(arr, mid, k))
            {
                // 'mid' is possible.
                // Store it and try for a larger distance.
                ans = mid;
                low = mid + 1;
            }
            else
            {
                // 'mid' is not possible.
                // Reduce the minimum distance.
                high = mid - 1;
            }
        }

        // Return the largest possible minimum distance.
        return ans;
    }
};
