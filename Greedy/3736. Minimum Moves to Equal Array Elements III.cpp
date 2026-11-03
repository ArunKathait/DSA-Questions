
class Solution {// Time: O(n)                         Auxiliary Space: O(1)
public:
    int minMoves(vector<int>& nums) {

        // Find the maximum element in the array.
        int maxNumber = *max_element(nums.begin(), nums.end());

        int moves = 0;

        // Calculate how many increments each element needs
        // to become equal to the maximum element.
        for(auto &num : nums)
        {
            moves += (maxNumber - num);
        }

        // Return the total number of increments.
        return moves;
    }
};

/*

┌──────────────────────────────────────────────────────┐
│       MINIMUM MOVES TO EQUAL ARRAY ELEMENTS          │
├──────────────────────────────────────────────────────┤
│ APPROACH: Find Maximum + Greedy                      │
│                                                      │
│ KEY IDEA:                                            │
│ • Find the maximum element in the array.             │
│ • Calculate increments needed for every element.     │
│ • moves = maxNumber - nums[i]                        │
│ • Add all increments to get the total moves.         │
│                                                      │
│ EXAMPLE:                                             │
│ nums = [1, 2, 3]                                     │
│ maxNumber = 3                                        │
│ moves = (3-1) + (3-2) + (3-3)                        │
│       = 2 + 1 + 0 = 3                                │
│                                                      │
│ COMPLEXITY:                                          │
│ • Time:  O(n)                                        │
│ • Space: O(1) auxiliary                              │
│                                                      │
│ IMPORTANT:                                           │
│ This logic applies when one move increments          │
│ exactly ONE element by 1.                            │
│                                                      │
│ LeetCode 453 increments n-1 elements per move,       │
│ so it uses the minimum element instead.              │
└──────────────────────────────────────────────────────┘

*/
