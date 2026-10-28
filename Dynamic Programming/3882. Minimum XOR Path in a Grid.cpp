
class Solution {// Time Complexity: O(n × m × K)                             Auxiliary Space: O(n × m × K)
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // dp[i][j][x] = true if XOR value x is possible
        // for any path from (0, 0) to cell (i, j).
        //
        // bitset<1024> stores possible XOR values from 0 to 1023.
        vector<vector<bitset<1024>>> dp(n, vector<bitset<1024>>(m));

        // The starting cell is included in the path.
        // Therefore, the initial XOR is grid[0][0].
        dp[0][0][grid[0][0]] = 1;

        // Traverse every cell from top to bottom and left to right.
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                // The starting cell is already initialized.
                if (i == 0 && j == 0) 
                {
                    continue;
                }

                // Store the XOR values that can reach
                // the cell directly above the current cell.
                bitset<1024> up;

                // Store the XOR values that can reach
                // the cell directly to the left.
                bitset<1024> left;

                // If an upper cell exists, copy its possible XOR values.
                if (i > 0) 
                {
                    up = dp[i - 1][j];
                }

                // If a left cell exists, copy its possible XOR values.
                if (j > 0) 
                {
                    left = dp[i][j - 1];
                }

                // A path can reach the current cell from above or left.
                // Combine all possible XOR values from both directions.
                bitset<1024> combined = up | left;

                // Check every possible XOR value from 0 to 1023.
                for (int xorVal = 0; xorVal < 1024; xorVal++) 
                {
                    // If xorVal is achievable at the previous cell,
                    // extend that path to the current cell.
                    if (combined[xorVal]) 
                    {
                        // Include the current cell's value in the XOR.
                        int ansXorVal = xorVal ^ grid[i][j];

                        // Mark the resulting XOR as achievable
                        // at the current cell.
                        dp[i][j][ansXorVal] = 1;
                    }
                }
            }
        }

        // At the destination, find the smallest achievable XOR.
        for (int xorVal = 0; xorVal < 1024; xorVal++) 
        {
            if (dp[n - 1][m - 1][xorVal]) 
            {
                return xorVal;
            }
        }

        // Return -1 if no valid XOR value is found.
        return -1;
    }
};

/*

┌──────────────────────────────────────────┐
│ Minimum XOR Path — Bitset DP             │
├──────────────────────────────────────────┤
│ 1. Initialize dp[0][0] with the starting │
│    cell's XOR value.                     │
│ 2. For each cell, collect possible XOR   │
│    values from top and left.             │
│ 3. XOR each possible value with the      │
│    current cell's value.                 │
│ 4. Mark the resulting XOR as achievable. │
│ 5. Return the smallest achievable XOR    │
│    at the destination.                   │
├──────────────────────────────────────────┤
│ Key Trick:                               │
│ bitset<1024> tracks all possible XOR     │
│ values from 0 to 1023 for each cell.     │
├──────────────────────────────────────────┤
│ Time Complexity:       O(n × m × K)      │
│ Auxiliary Space:       O(n × m × K) bits │
│ Extra Space:           O(1)              │
├──────────────────────────────────────────┤
│ K = 1024; time simplifies to O(n × m).   │
└──────────────────────────────────────────┘

*/
