
class Solution {// Time Complexity:  O(n)                      Space Complexity: O(1)
public:
    int longestMountain(vector<int>& arr) {
        // Get the size of the array.
        int n = arr.size();

        // Stores the maximum length of a mountain found so far.
        int ans = 0;

        // Start from index 1 because a peak must have a left neighbour.
        int i = 1;

        // A peak must also have a right neighbour,
        // so we stop at index n-2.
        while(i < n - 1)
        {
            // Check whether the current element is a valid peak.
            // A peak must be strictly greater than both neighbours.
            if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            {
                // Initially, both left and right pointers
                // point to the peak.
                int left = i;
                int right = i;

                // Expand towards the left while elements are
                // strictly increasing towards the peak.
                while(left > 0 && arr[left] > arr[left - 1])
                {
                    left--;
                }

                // Expand towards the right while elements are
                // strictly decreasing away from the peak.
                while(right < n - 1 && arr[right] > arr[right + 1])
                {
                    right++;
                }

                // Calculate the complete mountain length.
                // +1 is required because both boundaries are inclusive.
                ans = max(ans, right - left + 1);

                // Skip the mountain already processed.
                // Continue searching from its right boundary.
                i = right;
            }
            else
            {
                // Current element is not a peak.
                // Move to the next index.
                i++;
            }
        }

        // Return the maximum mountain length.
        // Returns 0 if no valid mountain exists.
        return ans;
    }
};

/*

┌──────────────────────────────────────────────┐
│ Problem: Longest Mountain in Array (LC 845)  │
├──────────────────────────────────────────────┤
│ • Approach: Two Pointers + Peak Expansion    │
│                                              │
│ • Key Idea:                                  │
│   Find a peak where arr[i] > both neighbours │
│   Expand left while arr[left] > arr[left-1]. │
│   Expand right while arr[right] >            │
│   arr[right+1].                              │
│   Calculate length = right - left + 1.       │
│   Skip the processed mountain by setting     │
│   i = right.                                 │
│                                              │
│ • Pattern: Peak Expansion                    │
├──────────────────────────────────────────────┤
│ • Time Complexity:  O(n)                     │
│ • Space Complexity: O(1)                     │
│ • Auxiliary Space:  O(1)                     │
└──────────────────────────────────────────────┘

*/
