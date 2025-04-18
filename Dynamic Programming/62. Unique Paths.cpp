*****************************************APPROACH 1st(USING RECURSION)********************************

class Solution {// TC--->O(2^(m + n))                        SC--->O(m + n)
public:
    // Recursive function to count the number of unique paths
    int solve(int row,int col,int m,int n)
    {
        // Base case: If we have reached the bottom-right cell (destination), there's 1 path
        if(row == m - 1 && col == n - 1)
        {
            return 1;
        }

        // If the current position is out of bounds, return 0 as it's not a valid path
        if(row < 0 || col < 0 || row >= m || col >= n)
        {
            return 0;
        }

        // Move to the right cell
        int right = solve(row,col + 1,m,n);

        // Move to the down cell
        int down = solve(row + 1,col,m,n);

        // Total number of paths from current cell is sum of paths by going right and going down
        return right + down;
    }

    // Main function to be called
    int uniquePaths(int m, int n) {
        // Start the path from the top-left cell (0, 0)
        return solve(0,0,m,n);
        
    }
};


***************************************APPROACH 2nd(USING RECURSION + MEMOIZATION)***************************
class Solution {// TC--->O(m*n)                            SC--->O(m*n)
public:
    // Recursive function with memoization to count unique paths
    int solve(int row,int col,int m,int n,vector<vector<int>>&dp)
    {
        // Base case: If we reach the last row or last column,
        // there's only 1 way to go — straight to the destination
        if(row == m - 1 || col == n - 1)
        {
            return 1;
        }

        // Out of bounds check (optional, for safety)
        if(row < 0 || col < 0 || row >= m || col >= n)
        {
            return 0;
        }

        // If we've already computed the result for this cell, return it (memoization)
        if(dp[row][col] != -1)
        {
            return dp[row][col];
        }

        // Move to the right cell
        int right = solve(row,col + 1,m,n,dp);

        // Move to the down cell
        int down = solve(row + 1,col,m,n,dp);

        // Store the total number of unique paths from current cell
        return dp[row][col] = (right + down);
    }

    // Main function to be called
    int uniquePaths(int m, int n) {
        // Create a 2D DP array initialized with -1 (to mark uncomputed values)
        vector<vector<int>>dp(m,vector<int>(n,-1));

        // Start the path from the top-left cell (0, 0)
        return solve(0,0,m,n,dp);
        
    }
};

*****************************************APPROACH 3rd(USING TABULATION)**********************************

class Solution {// TC--->O(m*n)                          SC--->O(m*n)
public:
    int uniquePaths(int m, int n) {
        // Create a 2D DP table of size m x n
        // dp[i][j] will store the number of unique paths to reach cell (i, j)
        vector<vector<int>> dp(m, vector<int>(n));

        // Initialize the starting point (top-left corner)
        dp[0][0] = 1;

        // Initialize the first column: Only one way to reach any cell in the first column (by moving down)
        for(int row = 0; row < m; row++) 
        {
            dp[row][0] = 1;
        }

        // Initialize the first row: Only one way to reach any cell in the first row (by moving right)
        for(int col = 0; col < n; col++) 
        {
            dp[0][col] = 1;
        }

        // Fill the rest of the DP table
        for(int i = 1; i < m; i++) 
        {
            for(int j = 1; j < n; j++) 
            {
                // The number of unique paths to reach cell (i, j) is the sum of:
                // - the paths from the cell above (i-1, j)
                // - the paths from the cell to the left (i, j-1)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        // The answer is in the bottom-right corner (destination)
        return dp[m-1][n-1];
    }
};

**************************************APPROACH 4th(USING TABULATION-->EASY ONE)***********************


class Solution {// TC--->O(m*n)                              SC--->O(m*n)
public:
    int uniquePaths(int m, int n) {
        // Create a 2D DP table of size m x n
        // Initialize all cells with 1
        // Because there is only 1 way to reach any cell in the first row or first column
        vector<vector<int>> dp(m, vector<int>(n, 1));

        // Start filling the table from cell (1,1) since first row and first column are already 1
        for(int i = 1; i < m; i++) 
        {
            for(int j = 1; j < n; j++) 
            {
                // Number of ways to reach cell (i, j) is the sum of:
                // - ways to reach the cell above (i-1, j)
                // - ways to reach the cell on the left (i, j-1)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        // The bottom-right cell contains the total number of unique paths from top-left to bottom-right
        return dp[m-1][n-1];
    }
};
