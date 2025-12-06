*************************************************APPROACH 1st(USING MEMOIZATION)****************************************

class Solution {// TC ---> (O*2^N)                                  SC ---> O(N)
  public:

    // Recursive function to find the maximum amount you can collect
    // when coins are available between indices 'left' and 'right'
    int solve(int left, int right, vector<int>& arr)
    {
        // Base case: no coins left to pick
        if (left > right) {
            return 0;
        }

        /*
            If you pick the LEFT coin at index 'left' (arr[left]):

            Now the opponent gets to pick.

            Opponent plays optimally to MINIMIZE your future score.
            Opponent will have **two choices**:
            
                1. Opponent picks coin at 'left + 1'
                   → remaining coins become (left + 2, right)

                2. Opponent picks coin at 'right'
                   → remaining coins become (left + 1, right - 1)

            Since opponent tries to reduce your future score,
            we take the MINIMUM of these two cases.
        */
        int pickLeft = arr[left] + min(
            solve(left + 2, right, arr),      // Opponent picked left+1
            solve(left + 1, right - 1, arr)   // Opponent picked right
        );

        /*
            If you pick the RIGHT coin at index 'right' (arr[right]):

            Again opponent plays optimally and has two choices:

                1. Opponent picks coin at 'left'
                   → remaining coins = (left + 1, right - 1)

                2. Opponent picks coin at 'right - 1'
                   → remaining coins = (left, right - 2)

            Again, opponent minimizes your future gain,
            so we take the MINIMUM of the two.
        */
        int pickRight = arr[right] + min(
            solve(left + 1, right - 1, arr),  // Opponent picked left
            solve(left, right - 2, arr)       // Opponent picked right - 1
        );

        // Return the better of the two choices:
        // picking the left coin or picking the right coin
        return max(pickLeft, pickRight);
    }

    // Main function
    int maximumAmount(vector<int> &arr) {
        int n = arr.size();

        // We start with full range of coins
        return solve(0, n - 1, arr);
    }
};

****************************************APPROACH 2nd(USING MEMOIZATION)**********************************************

class Solution {// TC ---> O(N^2)                                SC ---> O(N^2)  
  public:

    // Recursive function to compute the maximum amount you can collect
    // when the available coins are from index 'left' to 'right'.
    int solve(int left, int right, vector<int>& arr, vector<vector<int>>& dp)
    {
        // Base case: no coins left
        if (left > right) {
            return 0;
        }

        // If result is already calculated, return it (memoization)
        if (dp[left][right] != -1) {
            return dp[left][right];
        }

        /*
            If you pick the LEFT coin (arr[left]):

            Then the opponent will pick optimally, trying to minimize your future gain.

            Opponent options:
            1. Opponent picks 'left+1' → remaining coins: (left+2, right)
            2. Opponent picks 'right'   → remaining coins: (left+1, right-1)

            Since opponent plays optimally to minimize your result,
            you get arr[left] + min(#1, #2).
        */
        int pickLeft = arr[left] + min(
            solve(left + 2, right, arr, dp),
            solve(left + 1, right - 1, arr, dp)
        );

        /*
            If you pick the RIGHT coin (arr[right]):

            Opponent options:
            1. Opponent picks 'left'   → remaining coins: (left+1, right-1)
            2. Opponent picks 'right-1' → remaining coins: (left, right-2)

            Again, opponent minimizes your future gain.
        */
        int pickRight = arr[right] + min(
            solve(left + 1, right - 1, arr, dp),
            solve(left, right - 2, arr, dp)
        );

        // Store and return the best of picking left or right
        return dp[left][right] = max(pickLeft, pickRight);
    }

    int maximumAmount(vector<int> &arr) {
        int n = arr.size();

        // DP table initialized with -1 (meaning not computed)
        // dp[l][r] will store maximum amount you can collect from subarray l..r
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        // Compute for the full range (0 to n-1)
        return solve(0, n - 1, arr, dp);
    }
};
