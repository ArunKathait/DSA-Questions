
class Solution {// TC--->O(N*M)                   SC--->O(1)
public:
    int minimumArea(vector<vector<int>>& grid) {
        // Number of rows in the grid
        int n = grid.size();
        // Number of columns in the grid
        int m = grid[0].size();

        // Initialize boundaries for the rectangle:
        // minRow, minCol = very large values (so they can shrink when we find 1s)
        // maxRow, maxCol = very small values (so they can expand when we find 1s)
        int minRow = n;    
        int maxRow = -1;   
        int minCol = m;    
        int maxCol = -1;   

        // Traverse the entire grid
        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j < m; j++) 
            {
                // If we find a '1' in the grid
                if(grid[i][j] == 1) 
                {
                    // Update the smallest row index containing '1'
                    minRow = min(minRow, i);
                    // Update the largest row index containing '1'
                    maxRow = max(maxRow, i);

                    // Update the smallest column index containing '1'
                    minCol = min(minCol, j);
                    // Update the largest column index containing '1'
                    maxCol = max(maxCol, j);
                }
            }
        }

        // After scanning the grid:
        // Rectangle boundaries are from (minRow, minCol) to (maxRow, maxCol)
        // Height of rectangle = (maxRow - minRow + 1)
        // Width  of rectangle = (maxCol - minCol + 1)
        // Area = height * width
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};
