**********************************************APPROACH 1st**********************************************************

class Solution {// TC ---> O(N)                                         SC ---> O(1)
public:
    int minMoves(vector<int>& nums) {
        // Get the total number of elements in the array
        int n = nums.size();

        // Calculate the sum of all elements in the array
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // Find the smallest element in the array
        int minNumber = *min_element(nums.begin(), nums.end());

        // Minimum moves = sum of elements - (number of elements * minimum element)
        // We make every element equal to the minimum element conceptually
        return sum - (n * minNumber);
    }
};

/*

┌──────────────────────────────────────────────┐
│ LEETCODE 453 – MINIMUM MOVES TO EQUAL ARRAY  │
├──────────────────────────────────────────────┤
│ KEY IDEA:                                    │
│ Increment n-1 elements = Decrement 1 element │
│                                              │
│ APPROACH:                                    │
│ 1. Find total sum of array.                  │
│ 2. Find minimum element.                     │
│ 3. Calculate total difference from minimum.  │
│                                              │
│ FORMULA:                                     │
│ Moves = sum - (n * minimum)                  │
│                                              │
│ EXAMPLE:                                     │
│ nums = [1, 2, 3]                             │
│ sum = 6, min = 1, n = 3                      │
│ Moves = 6 - (3 * 1) = 3                      │
│                                              │
│ TIME:  O(n)                                  │
│ SPACE: O(1)                                  │
│                                              │
│ STL:                                         │
│ accumulate()  -> Sum                         │
│ min_element() -> Minimum                     │
└──────────────────────────────────────────────┘

*/

*****************************************************APPROACH 2***********************************************************

class Solution {// TC ---> O(N)                                                 SC ---> O(1)
public:
    int minMoves(vector<int>& nums) {
        // Get the total number of elements in the array
        int n = nums.size();

        // Stores the total number of moves required
        int ans = 0;

        // Find the smallest element in the array
        int minNumber = *min_element(nums.begin(), nums.end());

        // Calculate how much each element is greater than the minimum
        for (auto &num : nums)
        {
            // Each element needs (num - minNumber) moves
            // to reach the minimum value conceptually
            ans += (num - minNumber);
        }

        // Return the total number of moves
        return ans;
    }
};

/*

┌──────────────────────────────────────────────┐
│ LEETCODE 453 – MINIMUM MOVES TO EQUAL ARRAY  │
├──────────────────────────────────────────────┤
│ APPROACH:                                    │
│ 1. Find the minimum element.                 │
│ 2. Traverse the array.                       │
│ 3. Add (num - minNumber) to ans.             │
│                                              │
│ KEY LOGIC:                                   │
│ Increment n-1 elements = Decrement 1 element │
│                                              │
│ FORMULA:                                     │
│ ans += (num - minNumber)                     │
│                                              │
│ EXAMPLE:                                     │
│ nums = [1, 2, 3]                             │
│ min = 1                                      │
│ ans = (1-1) + (2-1) + (3-1)                  │
│ ans = 0 + 1 + 2 = 3                          │
│                                              │
│ TIME:  O(n)                                  │
│ SPACE: O(1)                                  │
└──────────────────────────────────────────────┘

*/
