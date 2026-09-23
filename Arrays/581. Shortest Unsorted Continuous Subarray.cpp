
class Solution {// Time   = O(N)                             Space  = O(1) 
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        // i will find the first position from the left
        // where the increasing order is broken.
        int i = 0;

        // Keep moving while the array is sorted in increasing order.
        // Example: 1 2 3 7 5
        //              ↑
        //          7 > 5, so stop at i = 3.
        while (i < n - 1 && nums[i] <= nums[i + 1]) 
        {
            i++;
        }

        // If we reached the last index, the complete array is sorted.
        // Therefore, no subarray needs to be changed.
        if (i == n - 1) 
        {
            return 0;
        }

        // j will find the first position from the right
        // where the increasing order is broken.
        int j = n - 1;

        // Move from right to left while the array is sorted.
        // Example: 1 2 3 7 5 6 8
        //                  ↑
        // Initially j = 6.
        // 6 <= 8 → j = 5
        // 5 <= 6 → j = 4
        // 7 <= 5 → false, so stop.
        while (j > 0 && nums[j - 1] <= nums[j]) 
        {
            j--;
        }

        // Now [i ... j] is the initial unsorted portion.
        //
        // We need the smallest and largest values
        // inside this portion.
        int minValue = INT_MAX;
        int maxValue = INT_MIN;

        // Find minimum and maximum values inside [i ... j].
        for (int k = i; k <= j; k++) 
        {
            // Store the smallest value in the unsorted portion.
            minValue = min(minValue, nums[k]);

            // Store the largest value in the unsorted portion.
            maxValue = max(maxValue, nums[k]);
        }

        // Check elements before i.
        //
        // If nums[i - 1] > minValue, then nums[i - 1]
        // is also in the wrong position.
        //
        // Therefore, we must include it in the subarray.
        while (i > 0 && nums[i - 1] > minValue) 
        {
            i--;
        }

        // Check elements after j.
        //
        // If nums[j + 1] < maxValue, then nums[j + 1]
        // is also in the wrong position.
        //
        // Therefore, we must include it in the subarray.
        while (j < n - 1 && nums[j + 1] < maxValue) 
        {
            j++;
        }

        // [i ... j] is now the smallest subarray
        // that needs to be sorted.
        //
        // Number of elements = j - i + 1.
        return j - i + 1;
    }
};

/*

┌──────────────────────────────────────┐
│          LEETCODE 581                │
├──────────────────────────────────────┤
│ 1. Find i                            │
│    First place where order breaks    │
│                                      │
│ 2. Find j                            │
│    Last place where order breaks     │
│                                      │
│ 3. Find min & max                    │
│    Inside [i ... j]                  │
│                                      │
│ 4. Expand boundaries                 │
│    Left  → nums[i-1] > min           │
│    Right → nums[j+1] < max           │
│                                      │
│ Answer = j - i + 1                   │
│ Time   = O(N)                        │
│ Space  = O(1)                        │
└──────────────────────────────────────┘

  */
