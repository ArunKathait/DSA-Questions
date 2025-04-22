***********************************************APPROACH 1st(USING RECURSION)************************************

class Solution {// TC--->O(N*M*3^min(N,M))                       SC--->O(N+M)
public:
    // Recursive function to calculate the size of the largest square 
    // submatrix of 1s starting from cell (row, col)
    int solve(int row,int col,int n,int m,vector<vector<int>>&matrix)
    {
        // Base case: if the indices go out of bounds, return 0
        if(row >= n || col >= m)
        {
            return 0;
        }

        // If the current cell is 0, it can't be part of any square
        if(matrix[row][col] == 0)
        {
            return 0;
        }

        // Recursively compute the size of the square submatrices in:
        // - right cell (same row, next column)
        // - diagonal cell (next row, next column)
        // - down cell (next row, same column)
        int right = solve(row,col + 1,n,m,matrix);
        int diagonal = solve(row + 1,col + 1,n,m,matrix);
        int down = solve(row + 1,col,n,m,matrix);

        // The current cell contributes to a square of size:
        // 1 (itself) + minimum of the 3 directions
        return 1 + min({right,diagonal,down});
    }

    // Main function to count all square submatrices with all 1s
    int countSquares(vector<vector<int>>& matrix) {
        // number of rows
        int n = matrix.size();

        // number of columns
        int m = matrix[0].size();

        // variable to store the final answer
        int ans = 0;

        // Iterate through each cell in the matrix
        for(int i=0;i<n;i++)
        {
             for(int j=0;j<m;j++)
             {
                  // For each cell, call the solve function to find how many
                  // square submatrices with all 1s start from (i, j)
                  ans += solve(i,j,n,m,matrix);
             }
        }

        // Return the total count of square submatrices with all 1s
        return ans;
    }
};

****************************************APPROACH 2nd(USING RECURSION + MEMOIZATION)***************************

class Solution {// TC--->O(N*M)                              SC--->O(N*M)
public:

    // Recursive function to find the size of the largest square starting at (row, col)
    // Uses memoization to avoid redundant calculations
    int solve(int row, int col, int n, int m, vector<vector<int>>& matrix, vector<vector<int>>& dp)
    {
        // Base case: if out of matrix bounds
        if (row >= n || col >= m)
        {
            return 0;
        }

        // If the current cell is 0, it can't be part of any square
        if (matrix[row][col] == 0)
        {
            return 0;
        }

        // If already computed, return the stored value
        if (dp[row][col] != -1)
        {
            return dp[row][col];
        }

        // Recursively compute right, diagonal, and down neighbors
        int right = solve(row, col + 1, n, m, matrix, dp);
        int diagonal = solve(row + 1, col + 1, n, m, matrix, dp);
        int down = solve(row + 1, col, n, m, matrix, dp);

        // Current cell can be part of a square if all three neighbors can extend the square
        // Store and return result: 1 (current cell) + minimum of the three directions
        return dp[row][col] = 1 + min({right, diagonal, down});
    }

    // Main function to count all square submatrices with all 1s
    int countSquares(vector<vector<int>>& matrix) {
        // Number of rows
        int n = matrix.size(); 

        // Number of columns      
        int m = matrix[0].size();    

        // Initialize DP table with -1 (uncomputed)
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        // To store the final count of square submatrices
        int ans = 0; 

        // Iterate over all cells of the matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // Accumulate the number of squares starting from cell (i, j)
                ans += solve(i, j, n, m, matrix, dp);
            }
        }
        
          // Return total number of square submatrices
        return ans;
    }
};


**************************************APPROACH 3rd(USING TABULATION)***************************************

class Solution {// TC--->O(N*M)                                SC--->O(N*M)
public:
    int countSquares(vector<vector<int>>& matrix) {
        // Number of rows in the matrix
        int n = matrix.size();

        // Number of columns in the matrix
        int m = matrix[0].size();

        // Create a DP matrix to store size of largest square ending at each cell
        vector<vector<int>>dp(n,vector<int>(m,0));

         // Initialize the DP cell at (0, 0) with the value from the input matrix
        dp[0][0] = matrix[0][0];

        // This will store the final count of all square submatrices with all 1s
        int ans = 0;

        // Initialize the first column of dp
        for(int row=1;row<n;row++)
        {
             // Copy values from the matrix
            dp[row][0] = matrix[row][0];

             // Add to answer if it's 1 (a 1x1 square exists)
            ans += dp[row][0];
        }

        // Initialize the first row of dp
        for(int col=0;col<m;col++)
        {
            // Copy values from the matrix
            dp[0][col] = matrix[0][col];

            // Add to answer if it's 1
            ans += dp[0][col];
        }

        // Fill the dp matrix for the rest of the cells
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                // If matrix[i][j] == 0, it can't be part of any square, so dp[i][j] remains 0
                // If the current cell in matrix is 1
                if(matrix[i][j] == 1)
                {
                    // Check the minimum square size among top, left, and top-left (diagonal) neighbors
                    int top = dp[i-1][j];
                    int diagonal = dp[i-1][j-1];
                    int left = dp[i][j-1];

                    // Current dp[i][j] will be 1 + minimum of the three neighbors
                    dp[i][j] = 1 + min({top,diagonal,left});

                    // Add the number of squares ending at (i, j) to the answer
                    ans += dp[i][j];
                }
            }
        }

        // Return the total number of square submatrices with all 1s
        return ans;
    }
};
