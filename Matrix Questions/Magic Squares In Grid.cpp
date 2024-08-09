
class Solution {// TC--->O(N*M)                      SC--->O(1)
public:
    
    // Function to check if a 3x3 grid starting at (row, col) is a magic square
    bool isMagicGrid(vector<vector<int>>&grid,int row,int col)
    {
        // Use an unordered_set to check if all numbers in the 3x3 grid are unique and in the range [1, 9]
        unordered_set<int>set;
        
        // Traverse the 3x3 grid
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                int number = grid[row+i][col+j];
                
                // If the number is out of the range [1, 9] or if it's already in the set, return false
                if(number < 1 || number > 9 || set.count(number))
                {
                    return false;
                }
                else
                {
                    // Otherwise, add the number to the set
                    set.insert(number);
                }
            }
        }
        
        // Calculate the sum of the first row in the 3x3 grid
        int Sum = grid[row][col] + grid[row][col+1] + grid[row][col+2];
        
        
        // Check if all rows and columns have the same sum
        for(int i=0;i<3;i++)
        {
            // Check the i-th row
            if((grid[row+i][col] + grid[row+i][col+1] + grid[row+i][col+2]) != Sum)
            {
                return false;
            }
                
            // Check the i-th column
            if((grid[row][col+i] + grid[row+1][col+i] + grid[row+2][col+i]) != Sum)
            {
                return false;
            }
        }
        
        // Check if the sum of the main diagonal is equal to Sum
        int diagonalSum = grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2];
        if(diagonalSum != Sum)
        {
            return false;
        }
        
        // Check if the sum of the anti-diagonal is equal to Sum
        int antiDiagonalSum = grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col];
        if(antiDiagonalSum != Sum)
        {
            return false;
        }
        
        // If all checks passed, return true
        return true;
    }
    
    // Function to count the number of 3x3 magic squares inside the grid
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        // Number of rows in the grid
        int n = grid.size();
        
        // Number of columns in the grid
        int m = grid[0].size();
        
        // Initialize a counter for the number of magic squares
        int count = 0;
        
        // Iterate over all possible 3x3 subgrids
        for(int i=0;i<=n-3;i++)
        {
            for(int j=0;j<=m-3;j++)
            {
                // Check if the subgrid starting at (i, j) is a magic square
                if(isMagicGrid(grid,i,j))
                {
                    // If it is, increment the counter
                    count++;
                }
            }
        }
        
        // Return the total count of magic squares found
        return count;
    }
};
