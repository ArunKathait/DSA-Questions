
class Solution {// TC ---> O(n∗m) + O(n∗m) + O(n∗m) = O(n∗m)                            SC ---> O(1)
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();      // Number of rows in the grid
        int m = grid[0].size();   // Number of columns in the grid

        long long totalSum = 0;         // To store the sum of all elements in the grid

        // Step 1: Calculate the total sum of the grid
        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j < m; j++) 
            {
                totalSum += grid[i][j];
            }
        }

        // Step 2: If the total sum is odd, it's impossible to split into two equal parts
        if(totalSum % 2 != 0) 
        {
            return false;
        }

        // Step 3: Check if there exists a horizontal partition that divides the grid into equal sums
        long long rowSum = 0;  // Sum of elements row-wise
        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j < m; j++) 
            {
                rowSum += grid[i][j];
            }

            if(rowSum == totalSum / 2) 
            {
                // Found a horizontal split where top half sum = bottom half sum
                return true;
            }
        }

        // Step 4: Check if there exists a vertical partition that divides the grid into equal sums
        long long colSum = 0;  // Sum of elements column-wise
        for(int j = 0; j < m; j++) 
        {
            for(int i = 0; i < n; i++) 
            {
                colSum += grid[i][j];
            }

            if(colSum == totalSum / 2) 
            {
                // Found a vertical split where left half sum = right half sum
                return true;
            }
        }

        // Step 5: If neither horizontal nor vertical partition found, return false
        return false;
    }
};
