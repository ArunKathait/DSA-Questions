*********************************************APPROACH 1st(USING RECURSION)******************************

class Solution {// TC--->O(2^(n + m))                        SC--->O(n + m)
public:
    // Recursive helper function to count unique paths from (row, col) to (n-1, m-1)
    int solve(int row,int col,int n,int m,vector<vector<int>>&obstacleGrid)
    {
        // Base case: If current cell is out of bounds or has an obstacle, return 0
        if(row < 0 || col < 0 || row >= n || col >= m || obstacleGrid[row][col] == 1)
        {
            return 0;
        }

        // Base case: If we're on the last row and last column, and no obstacle,
        // there's only one unique path straight to the end (either right or down only)
        if(row == n - 1 && col == m - 1)
        {
            return 1;
        }

        // Recursive case: Try to move right and down from current position
        int right = solve(row,col + 1,n,m,obstacleGrid);        // move right
        int down = solve(row + 1,col,n,m,obstacleGrid);         // move down

        // Total paths from this cell = paths from right + paths from down
        return (right + down);
    }
    
    // Main function to be called with the obstacle grid
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // number of rows
        int n = obstacleGrid.size();  

        // number of columns       
        int m = obstacleGrid[0].size();   

        // If the starting cell (top-left) or the destination cell (bottom-right) has an obstacle,
        // then there is no valid path from start to finish, so return 0 immediately.
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1)
        {
            return 0;
        }   

        // Start the recursion from top-left corner (0,0)
        return solve(0,0,n,m,obstacleGrid);
    }
};


*********************************************APPROACH 2nd(USING MEMOIZATION)***********************************

class Solution {// TC--->O(N * M)                              SC--->O(N * M)
public:
    // Recursive helper function to count unique paths from (row, col) to destination
    int solve(int row, int col, int n, int m, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp)
    {
        // Base case: If out of bounds or on an obstacle, return 0 (no path)
        if(row < 0 || col < 0 || row >= n || col >= m || obstacleGrid[row][col] == 1)
        {
            return 0;
        }

        // Base case: If reached the destination cell (bottom-right), return 1
        if(row == n - 1 && col == m - 1)
        {
            return 1;
        }

        // If the result is already computed for this cell, return it (memoization)
        if(dp[row][col] != -1)
        {
            return dp[row][col];
        }

        // Recursive calls:
        // Move to the right cell
        int right = solve(row, col + 1, n, m, obstacleGrid, dp);

        // Move to the cell below
        int down = solve(row + 1, col, n, m, obstacleGrid, dp);

        // Store the result in dp array and return it
        return dp[row][col] = (right + down);
    }

    // Main function
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // Number of rows
        int n = obstacleGrid.size();   

        // Number of columns     
        int m = obstacleGrid[0].size();     

        // Initialize a dp array with -1 (means unvisited)
        vector<vector<int>> dp(n, vector<int>(m, -1));

        // If the starting or ending cell is an obstacle, no path is possible
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1)
        {
            return 0;
        }

        // Start the recursive function from the top-left cell (0,0)
        return solve(0, 0, n, m, obstacleGrid, dp);
    }
};


***************************************APPROACH 3rd(USING TABULATION)****************************************

class Solution {// TC--->O(N * M)                         SC--->O(N * M)
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // Number of rows
        int n = obstacleGrid.size();

        // Number of columns
        int m = obstacleGrid[0].size();

        // If the starting or ending cell has an obstacle, no path is possible
        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1)
        {
            return 0;
        }

        // Initialize a 2D dp table of size n x m
        vector<vector<int>>dp(n,vector<int>(m));

        // Start point is always 1 if there's no obstacle (already checked above)
        dp[0][0] = 1;

        // Fill the first row
        for(int col=1;col<m;col++)
        {
            if(obstacleGrid[0][col] == 1)
            {
                // If there's an obstacle, no path through this cell
                dp[0][col] = 0;
            }
            else
            {
                // Else, carry forward the path count
                dp[0][col] = dp[0][col-1];
            }
        }

        // Fill the first column
        for(int row=1;row<n;row++)
        {
            if(obstacleGrid[row][0] == 1)
            {
                // If there's an obstacle, no path through this cell
                dp[row][0] = 0;
            }
            else
            {
                // Else, carry forward the path count
                dp[row][0] = dp[row-1][0];
            }
        }

        // Fill the rest of the dp table
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(obstacleGrid[i][j] == 1)
                {
                    // If obstacle, no path can go through here
                    dp[i][j] = 0;
                }
                else
                {
                    // 🔁 State Definition:
                    // dp[i][j] = total number of unique paths to reach cell (i, j)
                    // from the top-left corner (0, 0), avoiding obstacles.
                    // It is the sum of paths coming from the top (i-1, j) and from the left (i, j-1)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        // The answer is the number of paths to bottom-right cell
        return dp[n-1][m-1];
    }
};
