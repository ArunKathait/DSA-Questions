*****************************************************APPROACH 1st(USING RECURSION)****************************************

class Solution {// TC ---> O(2^(n+m))                              SC ---> O(n+m)
public:
    // Recursive function to count valid paths
    int solve(int row, int col, int n, int m,
              vector<vector<int>>& grid, int k, int currentSum)
    {
        // ❌ If row or col goes out of grid boundaries → no valid path
        if(row >= n || col >= m)
        {
            return 0;
        }

        // ✔ If we reach the last cell (bottom-right corner)
        if(row == n-1 && col == m-1)
        {
            // Check if total sum % k == 0
            // currentSum includes sum till previous cell
            // Add current cell grid[row][col] before checking
            return ((currentSum + grid[row][col]) % k == 0) ? 1 : 0;
        }

        // ✔ Compute new sum after adding current cell value
        // We take modulo k to avoid large numbers
        int newSum = (currentSum + grid[row][col]) % k;

        // ✔ Move right (col + 1)
        int right = solve(row, col + 1, n, m, grid, k, newSum);

        // ✔ Move down (row + 1)
        int down  = solve(row + 1, col, n, m, grid, k, newSum);

        // Total valid paths = right paths + down paths
        return right + down;
    }

    // Main function
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();        // number of rows
        int m = grid[0].size();     // number of columns

        // Start from (0,0) with initial sum = 0
        return solve(0, 0, n, m, grid, k, 0);
    }
};

**********************************************APPROACH 2nd(USING MEMOIZATION)*******************************************

class Solution {// TC ---> O(n * m * k)                             SC ---> O(n * m * k)
public:
    int M = 1e9 + 7;  // Modulo value to avoid large numbers

    // Recursive function to count number of valid paths
    int solve(int row, int col, int n, int m,
              vector<vector<int>>& grid, int k,
              int currentSum,
              vector<vector<vector<int>>>& dp)
    {
        // ❌ If the position goes outside the grid → invalid path
        if (row >= n || col >= m)
        {
            return 0;
        }

        // ✔ If we reached bottom-right cell (end of path)
        if (row == n - 1 && col == m - 1)
        {
            // Check if total sum % k == 0
            // Add the value of the last cell to currentSum
            return ((grid[row][col] + currentSum) % k == 0) ? 1 : 0;
        }

        // ✔ If result already computed → return saved result
        if (dp[row][col][currentSum] != -1)
        {
            return dp[row][col][currentSum];
        }

        // ✔ Compute new sum modulo k after including current cell
        int newSum = (currentSum + grid[row][col]) % k;

        // ✔ Move Right (col + 1)
        int right = solve(row, col + 1, n, m, grid, k, newSum, dp);

        // ✔ Move Down (row + 1)
        int down  = solve(row + 1, col, n, m, grid, k, newSum, dp);

        // ✔ Store the result in dp table and return modulo M
        return dp[row][col][currentSum] = (right + down) % M;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();        // number of rows
        int m = grid[0].size();     // number of columns

        // ✔ Initialize 3D DP array with -1
        // dp[row][col][sum_mod_k]
        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(m, vector<int>(k, -1))
        );

        // Start recursion from top-left with sum = 0
        return solve(0, 0, n, m, grid, k, 0, dp);
    }
};

*******************************************APPROACH 3rd(TABULATION)***************************************************

class Solution {// TC ---> O(n * m * k)                        SC ---> O(n * m * k)
public:
    int M = 1e9 + 7; // Modulo to avoid large numbers in answers

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();      // Number of rows
        int m = grid[0].size();   // Number of columns

        // 3D DP table: dp[i][j][rem] = number of paths from cell (i,j) to bottom-right
        // where the sum of values along the path modulo k equals 'rem'
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, 0)));

        // 1️⃣ Initialize the bottom-right cell
        for (int rem = 0; rem < k; rem++) {
            // If the sum (current remainder + value at last cell) is divisible by k → 1 path
            // Otherwise → 0 paths
            dp[n-1][m-1][rem] = ((grid[n-1][m-1] + rem) % k == 0) ? 1 : 0;
        }

        // 2️⃣ Fill the DP table from bottom-right to top-left
        for (int i = n - 1; i >= 0; i--) 
        {         // iterate rows backwards
            for (int j = m - 1; j >= 0; j--) 
            {     // iterate columns backwards
                for (int rem = 0; rem < k; rem++) 
                { // iterate all possible remainders
                    // Skip the last cell (already initialized)
                    if (i == n - 1 && j == m - 1) continue;

                    // Calculate new remainder after including current cell's value
                    int newRem = (rem + grid[i][j]) % k;

                    // Number of paths going down
                    int down = (i + 1 < n) ? dp[i + 1][j][newRem] : 0;

                    // Number of paths going right
                    int right = (j + 1 < m) ? dp[i][j + 1][newRem] : 0;

                    // Total paths from (i,j) for current remainder
                    dp[i][j][rem] = (down + right) % M;
                }
            }
        }

        // 3️⃣ Answer: Number of paths starting at (0,0) with initial remainder 0
        return dp[0][0][0];
    }
};
