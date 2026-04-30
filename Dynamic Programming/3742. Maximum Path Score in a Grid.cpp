**************************************************APPROACH 1st(MEMOIZATION)***************************************
  
class Solution {// TC ---> O(n × m × k)                              SC ---> O(n × m × k)
public:

    // Recursive function:
    // row, col → current position
    // cost → number of "positive cells" used so far
    // k → maximum allowed cost
    // dp → memoization table
    int solve(int row, int col, int n, int m, int cost,
              vector<vector<int>>& grid, int k,
              vector<vector<vector<int>>>& dp)
    {
        // ❌ Out of bounds → invalid path
        if(row >= n || col >= m)
        {
            return INT_MIN;
        }

        // ✅ Update cost based on current cell
        // If grid value > 0 → increase cost
        int newCost = cost + (grid[row][col] > 0 ? 1 : 0);

        // ❌ If cost exceeds k → invalid path
        if(newCost > k)
        {
            return INT_MIN;
        }

        // ✅ Base case: reached destination
        if(row == n - 1 && col == m - 1)
        {
            return grid[row][col];
        }

        // ⚠️ DP CHECK (IMPORTANT)
        // If already computed → return stored value
        if(dp[row][col][cost] != -1)
        {
            return dp[row][col][cost];
        }

        // 👉 Explore both directions

        // Move RIGHT
        int right = solve(row, col + 1, n, m, newCost, grid, k, dp);

        // Move DOWN
        int down = solve(row + 1, col, n, m, newCost, grid, k, dp);

        // ❌ If both paths are invalid
        if(right == INT_MIN && down == INT_MIN)
        {
            return dp[row][col][cost] = INT_MIN;
        }

        // ✅ Take best path (max score)
        return dp[row][col][cost] = grid[row][col] + max(right, down);
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        // 3D DP:
        // dp[row][col][cost] = max score from this state
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(k + 1, -1))
        );

        // Start from (0,0) with cost = 0
        int ans = solve(0, 0, n, m, 0, grid, k, dp);

        // If no valid path → return -1
        if(ans == INT_MIN)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};

***********************************************APPROACH 2nd(TABULATION)********************************************

  class Solution {// TC ---> O(n × m × k)                           SC ---> O(n × m × k)
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {

        int n = grid.size();        // number of rows
        int m = grid[0].size();     // number of columns

        // dp[i][j][cost] = maximum path sum starting from (i, j)
        // when we have already used 'cost' number of positive cells
        // -1 means "invalid / not reachable"
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(k + 1, -1))
        );

        // We fill DP from bottom-right → top-left
        // because each state depends on (i+1, j) and (i, j+1)
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = m - 1; j >= 0; j--)
            {
                // Try all possible costs from k → 0
                for(int cost = k; cost >= 0; cost--)
                {
                    // Calculate new cost after including current cell
                    // If current cell > 0 → increase cost by 1
                    int newCost = cost + (grid[i][j] > 0 ? 1 : 0);

                    // If cost exceeds allowed k → skip this state
                    if(newCost > k)
                    {
                        continue;
                    }

                    // ✅ Base case: bottom-right cell
                    if(i == n - 1 && j == m - 1)
                    {
                        // Only this cell contributes
                        dp[i][j][cost] = grid[i][j];
                        continue;
                    }

                    // Initialize both directions as invalid
                    int right = -1;
                    int down = -1;

                    // Move DOWN (i+1, j)
                    if(i + 1 < n)
                    {
                        // Take value only if valid (not -1)
                        down = dp[i+1][j][newCost];
                    }

                    // Move RIGHT (i, j+1)
                    if(j + 1 < m)
                    {
                        right = dp[i][j + 1][newCost];
                    }

                    // Choose best among right and down
                    int bestNext = max(right, down);

                    // If at least one path is valid
                    if(bestNext != -1)
                    {
                        // Add current cell value to best path
                        dp[i][j][cost] = grid[i][j] + bestNext;
                    }
                }
            }
        }

        // Final answer: start from (0,0) with cost = 0
        return dp[0][0][0];
    }
};
