*****************************************APPROACH 1st********************************************************

class Solution {// TC--->O(n*m)          SC--->O(n*m)
public:
     // Recursive function to find the minimum falling path sum from a given cell (row, col)
    int solve(vector<vector<int>>&dp,vector<vector<int>>&matrix,int row,int col,int n)
    {
        // Base case: If we reach the last row, return the value of the current cell
        if(row == n-1)
        {
            return matrix[row][col];
        }
        
        // If the value for the current cell is already computed, return it
        if(dp[row][col] != -1)
        {
            return dp[row][col];
        }
        
        // Current value in the matrix
        int sum = matrix[row][col];
        
        // Initialize minimum sum to maximum possible value
        int minSum = INT_MAX;
        
       // Explore adjacent cells in the next row: one to the left, one in the same column, and one to the right
        for(int shift = -1;shift <= 1;shift++)
        {
            // Check if the next row and column are within bounds
            if(row+1<n && col+shift < n && col+shift >= 0)
                
            // Update the minimum sum by recursively calling solve for the next cell
            minSum = min(minSum,sum + solve(dp,matrix,row+1 ,col+shift,n));
        }
        
        // Memoize the minimum sum for the current cell
        return dp[row][col] = minSum;
        
    }
    
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // Size of the matrix
        int n = matrix.size();
        
        // DP table to memoize the minimum falling path sum for each cell
        // Initialize with -1
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        // Start from the first row
        int row = 0;
        
        // Initialize the answer to maximum possible value
        int ans = INT_MAX;
        
        // Iterate through each column in the first row to find the minimum falling path sum
        for(int col=0;col<n;col++)
        {
               // Update the answer by finding the minimum falling path sum for the current starting column
               ans = min(ans,solve(dp,matrix,row,col,n));
        }
        
        // Return the minimum falling path sum
        return ans;
        }
};

// NOTE:This is giving time limit exceed.

*****************************************APPROACH 2nd********************************************************

class Solution {// TC--->O(n*m)             SC--->O(n*m)
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // Get the size of the matrix (number of rows)
        int n = matrix.size();
        
        // Create a 2D vector to store the intermediate results
        vector<vector<int>>ans(n,vector<int>(n));
        
        // Initialize the first row of the answer with the values from the first row of the matrix
        for(int i=0;i<n;i++)
        {
            ans[0][i] = matrix[0][i];
        }
        
        // Starting from the second row, calculate the minimum falling path sum
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                // Initialize mini with the value from the current cell in the previous row of ans
                int mini = ans[i-1][j];
                
                // Check if there is a cell to the left of the current cell
                if(j-1 >= 0)
                {
                    // Update mini with the minimum value between its current value and the value from the cell to the left
                    mini = min(mini,ans[i-1][j-1]);
                }
                // Check if there is a cell to the right of the current cell
                if(j+1 <= n-1)
                {
                    // Update mini with the minimum value between its current value and the value from the cell to the right
                    mini = min(mini,ans[i-1][j+1]);
                }
                
                // Update the current cell in ans with the sum of the current cell's value and mini
                ans[i][j] = matrix[i][j] + mini;
            }
        }
        
        // Return the minimum value from the last row of ans
        return *min_element(ans[n-1].begin(),ans[n-1].end());
    }
};


*****************************************APPROACH 3rd********************************************************

class Solution {//TC--->O(n*m)             SC--->O(1) --->Because we are modifying the same matrix
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // Get the number of rows in the matrix
        int n = matrix.size();
        
        // Get the number of columns in the matrix (assuming it's consistent across rows)
        int m = matrix[0].size();
        
        // Initialize the variable ans to store the minimum falling path sum,starting with maximum possible value
        int ans = INT_MAX;
        
        // Traverse the matrix starting from the second row
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // Initialize x with the value from the previous row at the same column
                int x = matrix[i-1][j];
                
                // Update x with the minimum value from the adjacent cells in the previous row
                if(j+1<m)
                {
                    // Right adjacent cell
                    x = min(x,matrix[i-1][j+1]);
                }
                if(j-1>=0) 
                {
                    // Left adjacent cell
                    x = min(x,matrix[i-1][j-1]);
                }
                
                // Update the current cell in the matrix with the sum of its value and x
                matrix[i][j] += x;
            }
        }
        
        // After updating all cells, find the minimum value from the last row of the matrix
        for(int i=0;i<m;i++) 
        {
            ans = min(ans,matrix[n-1][i]);
        }
        
        // Return the minimum falling path sum
        return ans;
    }
};
