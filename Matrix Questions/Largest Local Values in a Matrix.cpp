class Solution {// TC--->O(N^2)               SC--->O(N^2)
public:
    
    // Function to find the maximum value in a 3x3 subgrid starting from (i,j)
    int findLocalMax(vector<vector<int>>&grid,int i,int j)
    {
        // Initialize maxValue to the smallest possible integer value
        int maxValue = INT_MIN;
        
        // Loop through the 3x3 subgrid starting from (i,j)
        for(int row=i;row<=i+2;row++)
        {
            for(int col=j;col<=j+2;col++)
            {
                // Update maxValue if the current element in the subgrid is greater
                maxValue = max(maxValue,grid[row][col]);
            }
        }
        // Return the maximum value found in the subgrid
        return maxValue;
    }
    
    // Function to find the largest local maximum values for each 3x3 subgrid in the grid
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        
        // Get the size of the grid
        int n = grid.size();
        
        // Initialize a 2D vector to store the results with size (n-2)x(n-2) initialized with 0s
        vector<vector<int>>ans(n-2,vector<int>(n-2,0));
        
        // Loop through each (i,j) position in the grid where a 3x3 subgrid can fit
        for(int i=0;i<n-2;i++)
        {
            for(int j=0;j<n-2;j++)
            {
                // Call findLocalMax to find the maximum value in the current 3x3 subgrid
                ans[i][j] = findLocalMax(grid,i,j);
            }
        }
        
        // Return the resulting 2D vector containing the largest local maximum values
        return ans;
    }
};
