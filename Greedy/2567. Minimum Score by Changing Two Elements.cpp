
class Solution {// TC ---> O(NLogN)                               SC ---> O(1)
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Sort the array in ascending order.
        // This helps us identify the minimum and maximum differences.
        sort(nums.begin(), nums.end());

        // Step 2: Change at most two elements.
        // Consider the three possible ways to remove two extreme elements.

        return min({
            // Case 1: Change the two largest elements.
            // The remaining range is nums[0] to nums[n-3].
            nums[n-3] - nums[0],

            // Case 2: Change the smallest and largest elements.
            // The remaining range is nums[1] to nums[n-2].
            nums[n-2] - nums[1],

            // Case 3: Change the two smallest elements.
            // The remaining range is nums[2] to nums[n-1].
            nums[n-1] - nums[2]
        });
    }
};

/*

┌──────────────────────────────────────────────┐
│ Minimum Score by Changing Two Elements       │
├──────────────────────────────────────────────┤
│ Approach: Sorting + Greedy                   │
│                                              │
│ Key Idea:                                    │
│ Sort the array and consider 3 cases:         │
│ 1. Change two largest elements.              │
│ 2. Change smallest and largest elements.     │
│ 3. Change two smallest elements.             │
│ Return the minimum remaining range.          │
│                                              │
│ Time Complexity:  O(n log n)                 │
│ Space Complexity: O(log n)                   │
│ Extra Space:       O(1) (excluding sort)     │
└──────────────────────────────────────────────┘

*/
