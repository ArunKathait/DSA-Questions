
class Solution {// Time: O(n)                           Space: O(1)
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;

        // Traverse from left to right.
        //
        // We stop at n-2 because an operation needs
        // exactly 3 consecutive elements:
        //
        // i, i+1, i+2
        //
        // So i must be <= n-3.
        for(int i = 0; i < n - 2; i++)
        {
            // If nums[i] is already 1, we don't need
            // to do anything.
            //
            // If nums[i] is 0, we MUST flip the three
            // elements starting from i.
            //
            // Why MUST?
            // Because after moving past index i, there
            // is no later operation that can change nums[i].
            if(nums[i] == 0)
            {
                // Flip nums[i]
                // 0 -> 1
                // 1 -> 0
                nums[i] = 1 - nums[i];

                // Flip the next element
                nums[i + 1] = 1 - nums[i + 1];

                // Flip the third element
                nums[i + 2] = 1 - nums[i + 2];

                // We performed one operation
                ans++;
            }
        }

        // At this point, all positions from 0 to n-3
        // have been made equal to 1.
        //
        // We cannot perform another operation because
        // there are fewer than 3 elements remaining.
        //
        // Therefore, if either of the last two elements
        // is still 0, it is impossible to make the entire
        // array equal to 1.
        if(nums[n - 1] == 0 || nums[n - 2] == 0)
        {
            return -1;
        }

        // All elements are 1.
        // Return the minimum number of operations.
        return ans;
    }
};

/*  

┌────────────────────────────────────────┐
│       MINIMUM 3-BIT FLIPS              │
├────────────────────────────────────────┤
│                                        │
│ Scan LEFT → RIGHT                      │
│                                        │
│ nums[i] == 1                           │
│     → do nothing                       │
│                                        │
│ nums[i] == 0                           │
│     → MUST flip i, i+1, i+2            │
│                                        │
│ Why?                                    │
│ Once we pass i, we cannot change it.   │
│                                        │
│ At the end:                            │
│ Last 2 elements must be 1              │
│ Otherwise → -1                         │
│                                        │
│ Time  : O(n)                           │
│ Space : O(1)                           │
│                                        │
│ Pattern: GREEDY                        │
└────────────────────────────────────────┘

*/
