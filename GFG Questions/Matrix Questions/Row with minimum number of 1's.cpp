class Solution {// TC--->O(n*m)          SC--->O(1)
  public:
  // Function to find the row index containing the minimum number of ones
    int minRow(int n, int m, vector<vector<int>> a) {
        
        // Initialize rows to maximum integer value to track the minimum number of ones in a row
        int rows = INT_MAX;
        
        // Initialize minimum_index to maximum integer value to track the row index with the minimum number of ones
        int minimum_index = INT_MAX;
        
        // Loop through each row
        for(int i=0;i<n;i++)
        {
            // Initialize ones count for the current row
            int ones = 0;
            
            // Loop through each column in the current row
            for(int j=0;j<m;j++)
            {
                // If the element at (i, j) is equal to 1, increment ones count
                if(a[i][j] == 1)
                {
                    ones++;
                }
            }
            
            // If the number of ones in the current row is less than the current minimum
            if(rows > ones)
            {
                // Update the minimum number of ones
                rows = ones;
                
                // Update the index of the row with the minimum number of ones
                minimum_index = i + 1;// Adding 1 to convert from 0-based index to 1-based index
            }
        }
        // Return the index of the row with the minimum number of ones
        return minimum_index;
    }
};
