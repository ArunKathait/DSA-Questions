class Solution {// TC--->O(n*m)           SC--->O(n+m)
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        // Get the dimensions of the grid
        // Number of rows
        int n = grid.size();
        
        // Number of columns
        int m = grid[0].size();
        
        // Initialize vectors to store the count of ones in each row and column
        // Vector to store row-wise count of ones
        vector<int>rowCountOne(n,0);
        
        // Vector to store column-wise count of ones
        vector<int>colCountOne(m,0);
        
        
        // Iterate through the grid to count ones in each row and column
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    // Increment the count of ones in row i
                    rowCountOne[i]++;
                    
                    // Increment the count of ones in column j
                    colCountOne[j]++;
                }
            }
        }
        
        // Initialize the answer variable to store the total number of right triangles
        long long ans = 0;
        
        // Iterate through the grid again to calculate the number of right triangles
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    
                    // Calculate the number of right triangles with the current cell as the right-angle vertex
                    // Subtract 1 from the count of ones in the row and column to exclude the current cell
                    ans += (rowCountOne[i] - 1) * (colCountOne[j] - 1);
                }
            }
        }
        
        // Return the total number of right triangles
        return ans;
    }
};
