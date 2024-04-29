*****************************************APPROACH 1st(USING RECURSION)**********************************

class Solution {
public:
    
    // Recursive function to find the minimum falling path sum starting from the specified position(row, col)
    int solve(vector<vector<int>>&grid,int row,int col,int n,int m)
    {
        // If we have reached the last row, return the value of the cell at the current position
        if(row == n-1)
        {
            return grid[row][col];
        }
        
        // Initialize a variable to store the minimum sum for the current position
        int minSum = INT_MAX;
        
        // Iterate through all possible next column positions in the next row
        for(int nextCol=0;nextCol<m;nextCol++)
        {
            // Skip the column if it is the same as the current column
            if(nextCol != col)
            {
                // Recursively find the minimum falling path sum starting from the next position
                minSum = min(minSum,solve(grid,row+1,nextCol,n,m));   
            }
        }
        
         // Return the minimum sum for the current position plus the value of the current cell
        return minSum + grid[row][col];
    }
    
    // Function to find the minimum falling path sum for the entire grid
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        // Get the number of rows and columns in the grid
        int n = grid.size();
        int m = grid[0].size();
        
        // Initialize a variable to store the overall minimum falling path sum
        int ans = INT_MAX;
        
        // Iterate through all possible starting positions in the first row
        for(int col=0;col<n;col++)
        {
            // Find the minimum falling path sum starting from the current position
            ans = min(ans,solve(grid,0,col,n,m));
        }
        
        // Return the overall minimum falling path sum
        return ans;
    }
};

// NOTE: This will give Time Limit Exceed.

*******************************************APPROACH 2nd(USING MEMOIZATION)**********************************

class Solution {// TC--->O(n^3)        SC--->O(n^2)
public:
    
    // Recursive function to find the minimum falling path sum starting from the specified position(row, col)
    int solve(vector<vector<int>>&dp,vector<vector<int>>&grid,int row,int col,int n,int m)
    {
        // If we have reached the last row, return the value of the cell at the current position
        if(row == n-1)
        {
            return grid[row][col];
        }
        
        // If the value for the current position (row, col) is already calculated and stored in dp, return it
        if(dp[row][col] != -1)
        {
            return dp[row][col];
        }
        
        // Initialize a variable to store the minimum sum for the current position
        int minSum = INT_MAX;
        
        // Iterate through all possible next column positions in the next row
        for(int nextCol=0;nextCol<m;nextCol++)
        {
            // Skip the column if it is the same as the current column
            if(nextCol != col)
            {
                // Recursively find the minimum falling path sum starting from the next position
                minSum = min(minSum,solve(dp,grid,row+1,nextCol,n,m));   
            }
        }
        
         // Return the minimum sum for the current position plus the value of the current cell
        return dp[row][col] = minSum + grid[row][col];
    }
    
    // Function to find the minimum falling path sum for the entire grid
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        // Get the number of rows and columns in the grid
        int n = grid.size();
        int m = grid[0].size();
        
        // Initialize a 2D vector dp to store the calculated minimum falling path sums for each cell
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        // Initialize a variable to store the overall minimum falling path sum
        int ans = INT_MAX;
        
        // Iterate through all possible starting positions in the first row
        for(int col=0;col<n;col++)
        {
            // Find the minimum falling path sum starting from the current position
            ans = min(ans,solve(dp,grid,0,col,n,m));
        }
        
        // Return the overall minimum falling path sum
        return ans;
    }
};


***************************************APPROACH 3rd(USING TABULATION)***********************************

class Solution {// TC--->O(n^3)          SC--->O(n^2)
public:
    // Function to find the minimum falling path sum
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        // Get the size of the grid (number of rows)
        int n =grid.size();
        
        // Create a 2D vector 'dp' to store the minimum falling path sums
        vector<vector<int>>dp(n,vector<int>(n,0));
        
        // Initialize the first row of 'dp' with the values from the first row of 'grid'
        for(int col=0;col<n;col++)
        {
            dp[0][col] = grid[0][col];
        }
        
        // Iterate over each row starting from the second row
        for(int row=1;row<n;row++)
        {
            // Iterate over each column in the current row
            for(int col=0;col<n;col++)
            {
                // Initialize 'ans' to store the minimum value from the previous row
                int ans = INT_MAX;
                
                // Iterate over each column in the previous row
                for(int prevCol=0;prevCol<n;prevCol++)
                {
                    // Exclude the current column
                    if(col != prevCol)
                    {
                        // Update 'ans' with the minimum value from the previous row
                        ans = min(ans,dp[row-1][prevCol]);
                    }
                    
                }
                // Calculate the minimum falling path sum for the current cell
                dp[row][col] = ans + grid[row][col];
            }   
        }
        
        // Return the minimum value from the last row of 'dp'
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};
