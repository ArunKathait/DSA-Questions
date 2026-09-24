
class Solution {// Time = O(n)                        Space = O(n)
public:

    // Store the original array so that reset()
    // can always return the initial configuration.
    vector<int> original;

    // Constructor
    // Save the original array.
    Solution(vector<int>& nums) {
        original = nums;
    }

    // Return the original array.
    vector<int> reset() {
        return original;
    }

    // Return a randomly shuffled version of the array.
    vector<int> shuffle() {

        // Make a copy because we should not modify
        // the original array.
        vector<int> shuffled = original;

        int n = shuffled.size();

        // Number of elements that are still available
        // for random selection.
        int leftSize = n;

        // Start from the last position and move backwards.
        for(int i = n - 1; i > 0; i--)
        {
            // Pick a random index from the remaining
            // unselected elements.
            //
            // If leftSize = 4:
            // rand() % 4 gives 0, 1, 2, or 3.
            int j = rand() % leftSize;

            // Put the randomly selected element
            // at the current position.
            swap(shuffled[i], shuffled[j]);

            // One element is now fixed, so the number
            // of remaining elements decreases by 1.
            leftSize--;
        }

        return shuffled;
    }
};

/*

┌──────────────────────────────────────┐
│       LC 384 — Fisher-Yates          │
├──────────────────────────────────────┤
│ Pattern: Random Shuffle              │
│                                      │
│ 1. Copy original array               │
│ 2. Start from last index             │
│ 3. Pick j from [0, i]                │
│ 4. Swap nums[i] and nums[j]          │
│ 5. Move i backwards                  │
│                                      │
│ Formula:                             │
│ j = rand() % (i + 1)                 │
│                                      │
│ Why?                                 │
│ Every position gets a random         │
│ element from remaining elements.     │
│                                      │
│ Time:  O(n)                          │
│ Space: O(n)                          │
│                                      │
│ Key: Fisher-Yates Shuffle            │
└──────────────────────────────────────┘

*/
