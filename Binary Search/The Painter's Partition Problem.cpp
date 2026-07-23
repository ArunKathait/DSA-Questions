
class Solution {// TC ---> O(n × log(sum(arr)))                                 SC ---> O(1)
public:

    // This function checks how many painters are needed
    // if one painter can paint at most 'mid' units of work.
    int isPossible(vector<int>& arr, int mid)
    {
        int sum = 0;      // Current work assigned to one painter
        int count = 1;    // At least one painter is required

        // Traverse all boards
        for (int i = 0; i < arr.size(); i++)
        {
            // If current board can be assigned to the current painter
            // without exceeding the maximum allowed work (mid)
            if (sum + arr[i] <= mid)
            {
                sum += arr[i];
            }
            else
            {
                // Otherwise assign this board to a new painter
                count++;

                // New painter starts with the current board
                sum = arr[i];
            }
        }

        // Return total painters required
        return count;
    }

    int minTime(vector<int>& arr, int k)
    {
        int n = arr.size();
        int ans = 0;

        // Minimum possible answer:
        // One painter must at least paint the largest board.
        int low = *max_element(arr.begin(), arr.end());

        // Maximum possible answer:
        // One painter paints all boards.
        int high = accumulate(arr.begin(), arr.end(), 0);

        // Binary Search on the answer
        while (low <= high)
        {
            // Middle value represents the maximum work
            // allowed for one painter.
            int mid = low + (high - low) / 2;

            // Find how many painters are needed
            // if each painter can paint at most 'mid' work.
            if (isPossible(arr, mid) <= k)
            {
                // We can complete the work with k or fewer painters.
                // Try to minimize the answer.
                ans = mid;
                high = mid - 1;
            }
            else
            {
                // More than k painters are needed.
                // Increase the allowed work per painter.
                low = mid + 1;
            }
        }

        // Minimum possible maximum painting time
        return ans;
    }
};
