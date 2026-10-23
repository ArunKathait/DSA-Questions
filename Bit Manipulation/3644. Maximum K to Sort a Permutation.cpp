
class Solution {// TC ---> O(N)                                 SC ---> O(1)
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();

        // Initialize k with -1 (all bits set to 1).
        // We will use bitwise AND to find the common set bits
        // among elements that are not already at their correct indices.
        int k = -1;

        for (int i = 0; i < n; i++) 
        {
            // Check whether the current element is at its correct position.
            // In a sorted permutation of [0, n-1], nums[i] should equal i.
            if (nums[i] != i) 
            {
                // Update k using bitwise AND.
                // Only bits that are set in both k and nums[i] remain set.
                k = (k & nums[i]);
            }
        }

        // If every element is already at its correct position,
        // k remains -1, so return 0.
        // Otherwise, return the bitwise AND result.
        return k == -1 ? 0 : k;
    }
};

/*

┌──────────────────────────────────────┐
│ Sort Permutation                     │
├──────────────────────────────────────┤
│ Intuition:                           │
│ Minimum valid k is the AND of all    │
│ misplaced elements.                  │
├──────────────────────────────────────┤
│ 1. Initialize k = -1 (all bits set). │
│ 2. Traverse the array.               │
│ 3. If nums[i] != i, update           │
│    k = k & nums[i].                  │
│ 4. If no element is misplaced,       │
│    return 0; otherwise, return k.    │
├──────────────────────────────────────┤
│ Time Complexity       → O(n)         │
│ Auxiliary Space       → O(1)         │
│ Extra Space           → O(1)         │
└──────────────────────────────────────┘

*/
