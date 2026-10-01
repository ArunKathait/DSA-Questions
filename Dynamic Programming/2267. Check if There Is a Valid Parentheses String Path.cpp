*********************************************APPROACH 1st(MEMOIZATION)************************************************

class Solution {// Time  : O(n × m × (n + m))              Space : O(n × m × (n + m))
public:
    // dp[row][col][openCount]
    // -1 = state not calculated yet
    //  0 = no valid path from this state
    //  1 = a valid path exists from this state
    int dp[101][101][201];

    // Checks whether we can reach the destination from (row, col)
    // with the current number of unmatched opening brackets.
    int solve(int row, int col, int openCount, int n, int m, vector<vector<char>>& grid)
    {
        // Process the bracket present in the current cell.
        // '(' increases the unmatched opening bracket count.
        // ')' decreases it because it matches an opening bracket.
        openCount += (grid[row][col] == '(') ? 1 : -1;

        // If closing brackets exceed opening brackets,
        // this path can never become valid.
        if (openCount < 0)
        {
            return false;
        }

        // If we reach the bottom-right cell, the path is valid
        // only when every opening bracket has been matched.
        if (row == n - 1 && col == m - 1)
        {
            return dp[row][col][openCount] = (openCount == 0);
        }

        // If this state has already been calculated,
        // reuse the stored answer instead of exploring again.
        if (dp[row][col][openCount] != -1)
        {
            return dp[row][col][openCount];
        }

        // Try moving DOWN, if the next row is within the grid.
        if (row + 1 < n)
        {
            // If any downward path leads to a valid result,
            // store true and return immediately.
            if (solve(row + 1, col, openCount, n, m, grid))
            {
                return dp[row][col][openCount] = true;
            }
        }

        // Try moving RIGHT, if the next column is within the grid.
        if (col + 1 < m)
        {
            // If any rightward path leads to a valid result,
            // store true and return immediately.
            if (solve(row, col + 1, openCount, n, m, grid))
            {
                return dp[row][col][openCount] = true;
            }
        }

        // Neither direction produces a valid path.
        // Store false so we do not recalculate this state.
        return dp[row][col][openCount] = false;
    }

    bool hasValidPath(vector<vector<char>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // Every path contains n + m - 1 cells.
        // A valid parentheses string must have an even length.
        // Therefore, an odd-length path cannot be valid.
        if ((m + n - 1) % 2 == 1)
        {
            return false;
        }

        // The path starts at the top-left cell.
        // It cannot start with ')' because the balance becomes negative.
        // It also cannot end with '(' because the final balance
        // cannot become zero after processing that final opening bracket.
        if (grid[0][0] == ')' || grid[n - 1][m - 1] == '(')
        {
            return false;
        }

        // Initialize every DP state to -1 (unvisited).
        memset(dp, -1, sizeof(dp));

        // Start at (0, 0) with zero unmatched opening brackets.
        // solve() processes the starting cell itself.
        return solve(0, 0, 0, n, m, grid);
    }
};

/*

┌──────────────────────────────────────┐
│  VALID PARENTHESES PATH — 3D DP      │
├──────────────────────────────────────┤
│ STATE:                               │
│ dp[row][col][openCount]              │
│                                      │
│ BASE CASES:                          │
│ openCount < 0  → false               │
│ Destination     → openCount == 0     │
│ Odd path length → false              │
│                                      │
│ TRANSITIONS:                         │
│ Take DOWN  → solve(row+1, col, cnt)  │
│ Take RIGHT → solve(row, col+1, cnt)  │
│                                      │
│ PRUNING:                             │
│ ')' cannot exceed '('                │
│ '(' increments openCount             │
│ ')' decrements openCount             │
│                                      │
│ MEMOIZATION:                         │
│ -1 = Not visited                     │
│  0 = False, 1 = True                 │
│                                      │
│ TC: O(n × m × (n + m))               │
│ SC: O(n × m × (n + m))               │
│     DP + O(n + m) recursion stack    │
└──────────────────────────────────────┘

*/

*************************************************APPROACH 2nd(TABULATION)*********************************************


class Solution {// Time complexity: O(n * m(n + m))          Space complexity: O(n * m(n+m)) for the DP table.
public:
    // dp[row][col][openCount]
    // true means a valid path to the destination exists
    // when we arrive at (row, col) with this balance
    int dp[101][101][201];

    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Total cells in every path = n + m - 1.
        // A valid parentheses string must have even length.
        if ((m + n - 1) % 2 == 1) 
        {
            return false;
        }

        // A valid parentheses string cannot start with ')'
        // or end with '('.
        if (grid[0][0] == ')' || grid[n - 1][m - 1] == '(') 
        {
            return false;
        }

        // Process the grid from bottom-right to top-left.
        // This ensures the cells below and to the right
        // have already been calculated.
        for (int row = n - 1; row >= 0; row--) 
        {
            for (int col = m - 1; col >= 0; col--) 
            {
                // Try possible opening-bracket balances.
                // Your bound is based on row + col + 1,
                // the number of cells in a path from the start
                // to the current cell.
                for (int openCount = 0; openCount <= row + col + 1; openCount++) 
                {
                    // Destination cell: your code assumes that
                    // openCount is the balance after processing
                    // the destination cell.
                    if (row == n - 1 && col == m - 1) 
                    {
                        dp[row][col][openCount] = (openCount == 0);
                        continue;
                    }

                    // Initially assume no valid path exists.
                    dp[row][col][openCount] = false;

                    // Try moving DOWN.
                    if (row + 1 < n) 
                    {
                        // Process the bracket in the cell below.
                        int newOpenCount = (grid[row + 1][col] == '(') ? openCount + 1 : openCount - 1;

                        // Negative balance means a closing bracket
                        // appeared without a matching opening bracket.
                        if (newOpenCount >= 0 && dp[row + 1][col][newOpenCount] == true) 
                        {
                            dp[row][col][openCount] = true;
                        }
                    }

                    // Try moving RIGHT.
                    if (col + 1 < m) 
                    {
                        // Process the bracket in the cell to the right.
                        int newOpenCount = (grid[row][col + 1] == '(') ? openCount + 1: openCount - 1;

                        // If the rightward path is valid,
                        // the current state is also valid.
                        if (newOpenCount >= 0 && dp[row][col + 1][newOpenCount] == true) 
                        {
                            dp[row][col][openCount] = true;
                        }
                    }
                }
            }
        }

        // Start with balance 1 because the first cell is '('.
        return dp[0][0][1];
    }
};

/*

┌──────────────────────────────────────┐
│  VALID PARENTHESES PATH — TABULATION │
├──────────────────────────────────────┤
│ STATE:                               │
│ dp[row][col][openCount]              │
│                                      │
│ BASE CASE:                           │
│ Destination → openCount == 0         │
│                                      │
│ TRANSITIONS:                         │
│ DOWN  → row + 1                      │
│ RIGHT → col + 1                      │
│                                      │
│ BALANCE:                             │
│ '(' → openCount + 1                  │
│ ')' → openCount - 1                  │
│ Negative balance → Invalid           │
│                                      │
│ ORDER: Bottom-right → Top-left       │
│                                      │
│ TC: O(n × m × (n + m))               │
│ SC: O(n × m × (n + m))               │
│                                      │
│ KEY: 3D DP + Bottom-up Tabulation    │
└──────────────────────────────────────┘

*/
