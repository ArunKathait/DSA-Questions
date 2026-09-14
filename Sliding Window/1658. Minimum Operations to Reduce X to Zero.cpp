********************************************APPROACH 1st(RECURSION + MEMOIZATION)**************************************

class Solution {// Time  → O(N²)                     Space → O(N²)
public:

    // dp[left][right] stores the minimum number of operations
    // needed when the remaining array is from index left to right.
    //
    // We don't store x separately because for a fixed [left, right],
    // the amount already removed is fixed, so the remaining x is also fixed.
    vector<vector<int>> dp;

    int solve(int left, int right, vector<int>& nums, int x)
    {
        // If x becomes 0, it means we have successfully removed
        // elements whose sum is exactly the required x.
        //
        // No more operations are needed.
        if (x == 0)
        {
            return 0;
        }

        // If left > right:
        // There are no elements left to remove.
        //
        // If x < 0:
        // We have removed more sum than required.
        //
        // Both cases mean this path is invalid.
        //
        // We return a very large value (INF) to represent
        // an impossible solution.
        if (left > right || x < 0)
        {
            return 1e9;
        }

        // If we have already calculated this state,
        // directly return the stored answer.
        //
        // This avoids solving the same (left, right) state again.
        if (dp[left][right] != -1)
        {
            return dp[left][right];
        }

        // OPTION 1:
        // Remove the leftmost element.
        //
        // We perform 1 operation and reduce x
        // by nums[left].
        int takeLeft = 1 + solve(left + 1,right,nums,x - nums[left]);

        // OPTION 2:
        // Remove the rightmost element.
        //
        // We perform 1 operation and reduce x
        // by nums[right].
        int takeRight = 1 + solve(left,right - 1,nums,x - nums[right]);

        // We want the minimum number of operations.
        //
        // Store the answer in dp so that if we encounter
        // the same [left, right] state again, we don't
        // calculate it from scratch.
        return dp[left][right] = min(takeLeft, takeRight);
    }


    int minOperations(vector<int>& nums, int x)
    {
        int n = nums.size();

        // Create an n x n DP table.
        //
        // Initially -1 means:
        // "This state has not been calculated yet."
        dp.assign(n, vector<int>(n, -1));

        // Start with the complete array.
        //
        // left = 0
        // right = n - 1
        // x = original x
        int ans = solve(0, n - 1, nums, x);

        // If ans is INF or greater, it means
        // there is no possible way to make x equal to 0.
        //
        // Therefore return -1.
        //
        // Otherwise return the minimum number of operations.
        return ans >= 1e9 ? -1 : ans;
    }
};

/*

Important flow to remember

solve(left, right, x)
          |
          ↓
       x == 0?
      /       \
    YES        NO
    |           |
   return 0     |
                ↓
        left > right OR x < 0?
              /       \
            YES        NO
             |          |
            INF          ↓
                    already in dp?
                     /       \
                   YES        NO
                    |          |
                  return       ↓
                         takeLeft
                         takeRight
                            |
                            ↓
                           min
                            |
                            ↓
                       store in dp

╔══════════════════════════════════════════════╗
║       1658 — MIN OPERATIONS TO REDUCE X      ║
╠══════════════════════════════════════════════╣
║ 🎯 RECURSION + MEMOIZATION                  ║
║                                              ║
║ State:                                       ║
║ dp[left][right]                              ║
║                                              ║
║ At every step:                               ║
║ → Take LEFT                                  ║
║ → Take RIGHT                                 ║
║                                              ║
║ Transition:                                  ║
║ min(1 + solve(left+1,right,x-left),          ║
║     1 + solve(left,right-1,x-right))         ║
║                                              ║
║ Base:                                        ║
║ x == 0       → 0                             ║
║ left > right  → INF                          ║
║ x < 0         → INF                          ║
║                                              ║
║ Invalid answer: ans >= INF → -1              ║
║                                              ║
║ TC → O(N²)                                   ║
║ SC → O(N²)                                   ║
║                                              ║
╚══════════════════════════════════════════════╝

*/

*************************************************APPROACH 2nd(SLIDING WINDOW)*****************************************

class Solution {// TC → O(N)                                SC → O(1) 
public:
    int minOperations(vector<int>& nums, int x) {

        int n = nums.size();

        // Calculate sum of the complete array
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // Instead of removing elements from both ends,
        // we find the longest subarray that we can KEEP.
        //
        // totalSum - keptSum = x
        //
        // Therefore:
        // keptSum = totalSum - x
        int targetSum = totalSum - x;

        // If x is greater than the total sum,
        // we cannot remove elements whose sum is x.
        if (targetSum < 0) 
        {
            return -1;
        }

        int maxLength = -1;

        int i = 0;
        int sum = 0;

        // j represents the right end of the sliding window
        for (int j = 0; j < n; j++) 
        {
            // Add current element to the window
            sum += nums[j];

            // Since all nums are positive,
            // if sum becomes greater than target,
            // move the left pointer forward.
            while (sum > targetSum) 
            {
                sum -= nums[i];
                i++;
            }

            // We found a valid subarray.
            // Store the LONGEST valid subarray.
            if (sum == targetSum) 
            {
                maxLength = max(maxLength, j - i + 1);
            }
        }

        // If no subarray with targetSum exists,
        // there is no valid answer.
        if (maxLength == -1) 
        {
            return -1;
        }

        // Elements outside the longest kept subarray
        // are removed from the ends.
        return n - maxLength;
    }
};

/*

╔══════════════════════════════════════╗
║ 1658 — SLIDING WINDOW                ║
╠══════════════════════════════════════╣
║ total = sum(nums)                    ║
║ target = total - x                   ║
║                                      ║
║ Find LONGEST subarray                ║
║ whose sum == target                  ║
║                                      ║
║ nums positive → Sliding Window       ║
║                                      ║
║ if sum > target → shrink from left   ║
║ if sum == target → update maxLength  ║
║                                      ║
║ Answer = N - maxLength               ║
║                                      ║
║ TC → O(N)                            ║
║ SC → O(1)                            ║
╚══════════════════════════════════════╝

*/
