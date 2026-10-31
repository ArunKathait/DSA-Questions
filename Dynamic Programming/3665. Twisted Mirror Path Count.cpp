*******************************************APPROACH 1st(MEMOIZATION)*************************************************

class Solution {// Time Complexity : O(n × m)                                         Total Auxiliary Space : O(n × m)
public:
    int M = 1e9 + 7;

    // Direction constants
    int LEFT = 0;  // Robot entered the current cell while moving right
    int UP = 1;    // Robot entered the current cell while moving down

    int solve(int row, int col, int n, int m, vector<vector<int>>& grid, int cameFrom,vector<vector<array<int, 2>>>& dp) 
    {
        // If robot goes outside the grid, this path is invalid
        if (row >= n || col >= m) 
        {
            return 0;
        }

        // If robot reaches the destination, we found one valid path
        if (row == n - 1 && col == m - 1) 
        {
            return 1;
        }

        // If this state is already calculated, return its stored result
        // We use cameFrom because the same cell can behave differently
        // depending on the direction from which the robot entered it
        if (dp[row][col][cameFrom] != -1) 
        {
            return dp[row][col][cameFrom];
        }

        // Check whether the current cell contains a mirror
        if (grid[row][col] == 1) 
        {
            // Robot entered the mirror while moving right
            // Mirror reflects it downward
            if (cameFrom == LEFT) 
            {
                return dp[row][col][cameFrom] = solve(row + 1, col, n, m, grid, UP, dp);
            }

            // Robot entered the mirror while moving down
            // Mirror reflects it to the right
            else if (cameFrom == UP) 
            {
                return dp[row][col][cameFrom] = solve(row, col + 1, n, m, grid, LEFT, dp);
            }
        }

        // If the current cell is empty, robot can choose either direction

        // Option 1: Move right
        // The next cell is entered while moving right, so cameFrom = LEFT
        int right = solve(row, col + 1, n, m, grid, LEFT, dp);

        // Option 2: Move down
        // The next cell is entered while moving down, so cameFrom = UP
        int down = solve(row + 1, col, n, m, grid, UP, dp);

        // Add both possible paths and store the result in DP
        return dp[row][col][cameFrom] = (right + down) % M;
    }

    int uniquePaths(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // DP dimensions:
        // n rows, m columns, 2 possible entering directions
        // Initially -1 means the state has not been calculated
        vector<vector<array<int, 2>>> dp(n + 1, vector<array<int, 2>>(m + 1, {-1, -1}));

        // Start recursion from the top-left cell
        return solve(0, 0, n, m, grid, LEFT, dp);
    }
};

/*

┌────────────────────────────────────────┐
│ Unique Paths with Mirrors              │
├────────────────────────────────────────┤
│ DP State: dp[row][col][cameFrom]       │
│                                        │
│ LEFT = 0 → Entered from left           │
│ UP   = 1 → Entered from top            │
│                                        │
│ Out of Bounds → Return 0               │
│ Destination   → Return 1               │
│ Mirror        → Reverse direction      │
│ Empty Cell    → Try Right + Down       │
│                                        │
│ Memoization → Store each state once    │
├────────────────────────────────────────┤
│ Time Complexity       : O(n × m)       │
│ DP Space              : O(n × m)       │
│ Recursion Stack       : O(n + m)       │
│ Auxiliary Space       : O(n × m)       │
└────────────────────────────────────────┘

*/

**********************************************APPROACH 2nd(TABULATION)***********************************************

class Solution {// Time Complexity : O(n × m)                            Space Complexity : O(n × m)
public:
    int M = 1e9 + 7;

    // Direction identifiers used as DP array indices
    int LEFT = 0;  // Robot entered the current cell while moving right
    int UP = 1;    // Robot entered the current cell while moving down

    int uniquePaths(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // DP state: dp[row][col][cameFrom]
        //
        // For every cell, we maintain two possible states:
        // dp[row][col][LEFT] -> Robot entered from the left
        // dp[row][col][UP]   -> Robot entered from the top
        //
        // Extra row and column are initialized with 0.
        // They represent out-of-boundary positions, which are invalid paths.
        vector<vector<array<int, 2>>> dp(n + 1, vector<array<int, 2>>(m + 1, {0, 0}));

        // Traverse from bottom-right to top-left.
        // We calculate the bottom and right cells before the current cell
        // because our transitions depend on those cells.
        for (int row = n - 1; row >= 0; row--) 
        {
            for (int col = m - 1; col >= 0; col--) 
            {
                // Calculate both possible entering-direction states
                for (int cameFrom = 0; cameFrom < 2; cameFrom++) 
                {
                    // Base case: destination reached.
                    // Reaching the last cell counts as one valid path.
                    if (row == n - 1 && col == m - 1) 
                    {
                        dp[row][col][cameFrom] = 1;
                        continue;
                    }

                    // Check whether the current cell contains a mirror
                    if (grid[row][col] == 1) 
                    {
                        // If robot entered the mirror while moving right,
                        // it gets reflected downward.
                        if (cameFrom == LEFT) 
                        {
                            dp[row][col][cameFrom] = dp[row + 1][col][UP];
                        }

                        // If robot entered the mirror while moving down,
                        // it gets reflected towards the right.
                        else 
                        {
                            dp[row][col][cameFrom] = dp[row][col + 1][LEFT];
                        }

                        // Mirror allows only the reflected movement.
                        // Do not calculate normal right and down movements.
                        continue;
                    }

                    // Current cell is empty.
                    // Robot can choose either right or down.

                    // Option 1: Move right.
                    // The next cell will be entered from the left.
                    int right = dp[row][col + 1][LEFT];

                    // Option 2: Move down.
                    // The next cell will be entered from the top.
                    int down = dp[row + 1][col][UP];

                    // Total paths = paths going right + paths going down.
                    // Apply modulo to avoid integer overflow.
                    dp[row][col][cameFrom] = (right + down) % M;
                }
            }
        }

        // Return the number of paths starting at (0,0),
        // assuming the starting cell does not trigger reflection.
        return dp[0][0][LEFT];
    }
};

/*

┌──────────────────────────────────────────┐
│ Tabulation – Bottom-Up DP                │
├──────────────────────────────────────────┤
│ 1. Create DP array of size (n+1) × (m+1) │
│    with 2 states per cell.               │
│                                          │
│ 2. Traverse from bottom-right to         │
│    top-left.                             │
│                                          │
│ 3. For each cell, process both           │
│    directions: LEFT and UP.              │
│                                          │
│ 4. If destination → dp = 1               │
│                                          │
│ 5. If mirror:                            │
│    LEFT → Down                           │
│    UP   → Right                          │
│                                          │
│ 6. If empty cell:                        │
│    dp = Right + Down                     │
│                                          │
│ 7. Return dp[0][0][LEFT]                 │
├──────────────────────────────────────────┤
│ Time Complexity  : O(n × m)              │
│ Space Complexity : O(n × m)              │
└──────────────────────────────────────────┘

*/
