*********************************************APPROACH 1st**************************************************************

class Solution {// TC ---> O(n log n)                                 SC ---> O(1)
public:
    int minMoves2(vector<int>& nums) {

        int n = nums.size();

        // Step 1: Sort the array.
        // Sorting helps us find the median.
        sort(nums.begin(), nums.end());

        int moves = 0;

        // Step 2: Find the middle index.
        int mid = n / 2;

        // Step 3: Select the median as the target value.
        // The median minimizes the sum of absolute differences.
        int target = nums[mid];

        // Step 4: Calculate the moves required to make
        // every element equal to the median.
        for (auto &num : nums) {

            // Each element needs abs(target - num) moves
            // to become equal to the target.
            moves += abs(target - num);
        }

        // Return the minimum total number of moves.
        return moves;
    }
};

/*

┌────────────────────────────────────────────────┐
│ LEETCODE 462 - MINIMUM MOVES TO EQUAL ELEMENTS │
├────────────────────────────────────────────────┤
│ Approach: Sorting + Median                     │
├────────────────────────────────────────────────┤
│ 1. Sort the array.                             │
│ 2. Find middle index = n / 2.                  │
│ 3. Select nums[n / 2] as the target (median).  │
│ 4. Calculate abs(num - target) for every value.│
│ 5. Sum all differences to get minimum moves.   │
├────────────────────────────────────────────────┤
│ KEY CONCEPT:                                   │
│ Median minimizes sum of absolute differences.  │
│                                                │
│ Formula:                                       │
│ ans = Σ |nums[i] - median|                     │
├────────────────────────────────────────────────┤
│ Time Complexity:  O(n log n)                   │
│ Space Complexity: O(1) auxiliary (excluding    │
│                   sorting implementation)      │
└────────────────────────────────────────────────┘

*/

***************************************************APPROACH 2nd********************************************************

class Solution {// TC ---> O(N)                                 SC ---> O(1)
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        // Place the element that would be at index n/2
        // in its correct sorted position.
        // Elements before it will be <= target, and elements after it >= target.
        nth_element(nums.begin(), nums.begin() + n/2, nums.end());

        // Find the middle index.
        int mid = n/2;

        // The middle element is the median.
        // Choosing the median minimizes the sum of absolute differences.
        int target = nums[mid];

        int moves = 0;

        // Calculate the total moves required to make every element equal
        // to the median.
        //
        // We process elements from both ends:
        // nums[i]       -> element from the left
        // nums[n-i-1]   -> corresponding element from the right
        //
        // abs(target - element) gives the moves required for that element.
        for(int i = 0; i < n/2; i++)
        {
            moves += abs(target - nums[i]);
            moves += abs(target - nums[n - i - 1]);
        }

        // If n is odd, the middle element is already equal to target,
        // so it requires 0 moves.
        // If n is even, all elements have been processed in pairs.
        return moves;
    }
};

/*

┌────────────────────────────────────────────────────┐
│                  nth_element()                     │
├────────────────────────────────────────────────────┤
│ Purpose: Find the element at a specific sorted     │
│          position without fully sorting the array. │
│                                                    │
│ Syntax:                                            │
│ nth_element(begin, nth, end);                      │
│                                                    │
│ Key Points:                                        │
│ • Places the nth element in its correct position.  │
│ • Left elements <= nth element.                    │
│ • Right elements >= nth element.                   │
│ • Left and right portions are NOT sorted.          │
│ • Useful for finding median / kth smallest element.│
│                                                    │
│ Complexity:                                        │
│ • Average Time : O(n)                              │
│ • Worst Time   : O(n²) (standard guarantee)        │
│ • Extra Space  : Implementation-dependent          │
│                                                    │
│ Interview Trick:                                   │
│ Use nth_element() when you need the kth element,   │
│ not the complete sorted array.                     │
└────────────────────────────────────────────────────┘

*/
