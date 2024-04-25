******************************************APPROACH 1st****************************************************
class Solution {// TC--->O(n*m)             SC--->O(1)
  public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
         // Check if the dimensions of the matrix are less than 3
        if(n < 3 || m < 3)
        {
            // If so, the operation cannot be performed, return -1
            return -1;
        }
        
        // Initialize the maximum sum to the minimum integer value
        int ans = INT_MIN;
        
        // Iterate through the rows of the matrix starting from the third row
        for(int i=2;i<n;i++)
        {
            // Initialize the sum for the current row to 0
            int sum = 0;
            // Iterate through the columns of the matrix starting from the second column and ending at the second-to-last column
            for(int j=1;j<m-1;j++)
            {
              // Calculate the sum of the current cell and its surrounding cells
                sum = mat[i][j] +     // Current cell
                 mat[i-1][j] +        // Cell one row above
                 mat[i-2][j] +        // Cell two rows above
                 mat[i-2][j-1] +      // Cell two rows above and one column to the left
                 mat[i-2][j+1] +      // Cell two rows above and one column to the right
                 mat[i][j-1] +        // Cell to the left
                 mat[i][j+1];         // Cell to the right
                      
                       // Update the maximum sum if the current sum is greater
                ans = max(ans,sum);
            }
        }// Return the maximum sum
        return ans;
    }
};

// NOTE: Start from row number 2 and eliminate column 1 and column last(i.e m-1).

******************************************APPROACH 2nd****************************************************

class Solution {// TC--->O(n*m)          SC--->O(1)
  public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
        // Check if the matrix dimensions are valid for the operation
        if(n < 3 || m < 3)
        {
            // If dimensions are not valid, return -1
            return -1;
        }
        
        // Initialize the maximum sum to the minimum integer value
        int ans = INT_MIN;
        
        // Loop through the rows of the matrix (excluding the first and last rows)
        for(int i=1;i<n-1;i++)
        {
            int sum = 0;
          
            // Loop through the columns of the matrix (excluding the first and last columns)
            for(int j=1;j<m-1;j++)
            {
                // Calculate the sum of the current 3x3 submatrix
                sum = mat[i][j] + mat[i-1][j] + mat[i+1][j] + mat[i-1][j-1] + mat[i-1][j+1]
                       + mat[i+1][j-1] + mat[i+1][j+1];
                       
                       // Update the maximum sum
                 ans = max(ans,sum);      
            }
        }
        // Return the maximum sum
        return ans;
    }
};

// NOTE: Here we are starting from row number 1 and go upto second last row (i.e row - 1) .
//       For coloumn we start from 1 column and go upto second last column(i.e m - 1)
