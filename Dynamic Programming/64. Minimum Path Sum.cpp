***********************************************APPROACH 1st(USING RECURSION)****************************

class Solution {// TC--->O(2^(N + M))                      SC--->O(N + M)
public:
    // Recursive function to calculate minimum path sum from (row, col) to bottom-right
    int solve(int row,int col,int n,int m,vector<vector<int>>&grid)
    {
        // Base case: if we're at the destination cell (bottom-right), return its value
        if(row == n - 1 && col == m - 1)
        {
            return grid[row][col];
        }

        // If the current cell is out of bounds, return a large value (invalid path)
        if(row < 0 || col < 0 || row >= n || col >= m)
        {
            return INT_MAX;
        }

        // Recursively calculate the minimum path sum if we move right
        int right = solve(row,col + 1,n,m,grid);

        // Recursively calculate the minimum path sum if we move down
        int down = solve(row + 1,col,n,m,grid);

        // Return the current cell's value + minimum of the two possible moves (right, down)
        return grid[row][col] + min(right,down);
    }
    
    // Main function to start the recursion from the top-left corner
    int minPathSum(vector<vector<int>>& grid) {
        // number of rows
        int n = grid.size();

        // number of columns
        int m = grid[0].size();

        // Start solving from cell (0, 0)
        return solve(0,0,n,m,grid);
    }
};

********************************************APPROACH 2nd(USING MEMOIZATION)***********************************

class Solution {// TC--->O(N*M)                         SC-->O(N*M)
public:

    // Recursive function with memoization to find minimum path sum from (row, col) to bottom-right
    int solve(int row, int col, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        // Base case: if we're at the destination cell, return its value
        if(row == n - 1 && col == m - 1)
        {
            return grid[row][col];
        }

        // If we go out of bounds, return INT_MAX so it won't be chosen in min()
        if(row < 0 || col < 0 || row >= n || col >= m)
        {
            return INT_MAX;
        }

        // If we've already computed the value for this cell, return it
        if(dp[row][col] != -1)
        {
            return dp[row][col];
        }

        // Recursive call to move down
        int down = solve(row + 1, col, n, m, grid, dp);

        // Recursive call to move right
        int right = solve(row, col + 1, n, m, grid, dp);

        // Store and return the current cell's value + minimum of right and down paths
        return dp[row][col] = grid[row][col] + min(right, down);
    }

    // Main function to start the recursion from top-left corner (0,0)
    int minPathSum(vector<vector<int>>& grid) {
        // number of rows
        int n = grid.size(); 

        // number of columns        
        int m = grid[0].size();      

        // Create a DP table initialized with -1 (to represent unvisited cells)
        vector<vector<int>> dp(n, vector<int>(m, -1));

        // Start solving from the top-left corner (0, 0)
        return solve(0, 0, n, m, grid, dp);
    }
};

*********************************************APPROACH 3rd(USING TABULATION)**************************************

class Solution {// TC--->O(N*M)                               SC--->O(N*M)
public:
    int minPathSum(vector<vector<int>>& grid) {
        // number of rows
        int n = grid.size();

        // number of columns
        int m = grid[0].size();

        // Create a 2D DP table to store the minimum path sum to each cell
        vector<vector<int>>dp(n,vector<int>(m));

        // Initialize the starting point (top-left corner)
        dp[0][0] = grid[0][0];

        // Fill the first column: you can only move down in the first column
        for(int row=1;row<n;row++)
        {
            dp[row][0] = grid[row][0] + dp[row-1][0];
        }

        // Fill the first row: you can only move right in the first row
        for(int col=1;col<m;col++)
        {
            dp[0][col] = grid[0][col] + dp[0][col-1];
        }

        // Fill the rest of the DP table
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                // For each cell, take the minimum of the top or left cell
                // because those are the only directions we can come from
                dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
            }
        }

        // The bottom-right cell contains the minimum path sum from top-left to bottom-right
        return dp[n-1][m-1];
    }
};

/*    
     State Definition in DP:
     dp[i][j]: This represents the minimum path sum to reach the cell (i, j) from the starting point (0, 0).

     Breakdown:
    1.Starting Point:
                     The initial cell dp[0][0] is initialized to grid[0][0] because it's the starting point.
    2.First Row:
                For the first row, since we can only move right, each cell dp[0][col] is the sum of grid[0][col] and 
                the previous cell dp[0][col-1].
    3.First Column:
                  For the first column, since we can only move down, each cell dp[row][0] is the sum of grid[row][0] and the 
                  previous cell dp[row-1][0].
    4.Remaining Cells:
                      For any cell (i, j), the minimum path sum is the sum of grid[i][j] and the minimum of the two possible
                      previous cells:
                       ----->Top cell: dp[i-1][j]
                       ----->Left cell: dp[i][j-1]
        This gives us:
                      dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
    5.Final State:
                  The bottom-right cell dp[n-1][m-1] will hold the minimum path sum from the top-left to the
                  bottom-right corner.
*/
