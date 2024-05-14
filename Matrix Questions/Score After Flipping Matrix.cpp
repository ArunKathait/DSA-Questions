**********************************************APPROACH 1st(MODIFYING THE MATRIX)************************************

class Solution {// TC--->O(N*M)             SC--->O(1)--->Here we are modifying the matrix.
public:
    int matrixScore(vector<vector<int>>& grid) {

        // Get the number of rows and columns in the grid
        // Number of rows
        int n = grid.size();
        
        // Number of columns
        int m = grid[0].size();
        
        //Ensure that each row starts with a 1
        for(int i=0;i<n;i++)
        {
            // Check if the first element of the current row is 0
            if(grid[i][0] == 0)
            {
                // If it's 0, flip all elements in the row
                for(int j=0;j<m;j++)
                {
                     // Flip the current element (0 to 1 or 1 to 0)
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        
        //Ensure that each column has more 1s than 0s
        for(int j=1;j<m;j++)
        {
            // Initialize counts for 0s and 1s in the current column
            int countZero = 0,countOne = 0;
            
            // Count the number of 0s and 1s in the current column
            for(int i=0;i<n;i++)
            {
                if(grid[i][j] == 1)
                {
                    // Increment count if the element is 1
                    countOne++;
                }
                else
                {
                    // Increment count if the element is 0
                    countZero++;
                }
            }
            
            // If there are more 0s than 1s in the column, flip the column
            if(countZero > countOne)
            {
                for(int i=0;i<n;i++)
                {
                    // Flip the current element (0 to 1 or 1 to 0)
                    grid[i][j] = 1 - grid[i][j];
                }     
            }
        }
        
        // Calculate the final score of the grid
        // Initialize the final score
        int ans = 0;
        
        // Iterate through each cell in the grid
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // Calculate the score for the current cell
                // The score is the value of the cell multiplied by 2 raised to the power of its position from the rightmost side(i.e from rightmost column)
                // Score of the cell
                int score = grid[i][j] * pow(2,m-j-1);// we can also do this grid[i][j] << (m-j-1);
                
                // Add the score to the total score
                ans += score;
            }
        }
        
        // Return the final score of the grid
        return ans;
    }
};

***********************************************APPROACH 2nd(WITHOUT MODIFYING THE MATRIX)***************************

class Solution {// TC--->O(N*M)              SC--->O(1)--->Here we are not modifying the matrix
public:
    int matrixScore(vector<vector<int>>& grid) {
        
        // Get the number of rows and columns in the grid
        // Number of rows
        int n = grid.size();
        
        // Number of columns
        int m = grid[0].size();
        
        // Initialize the final score
        int ans = 0;
        
        // Calculate the score contributed by the first column
        // Score contributed by the first column
        ans = n * pow(2,m-1);
        
        // Calculate the score contributed by the remaining columns
        for(int j=1;j<m;j++)
        {
            // Initialize count of elements with the same bit value as the first element in the column
            int countSameBits = 0;
            
            // Count the number of elements with the same bit value as the first element in the column
            for(int i=0;i<n;i++)
            {
                if(grid[i][j] == grid[i][0])
                {
                    // Increment count if the element has the same bit value as the first element in the column
                    countSameBits++;
                }
            }
            
            // Count of elements with bit value 1 in the column
            int countOnes = countSameBits;
            
            // Count of elements with bit value 0 in the column
            int countZeros = n - countOnes;
            
            // Choose the maximum count (either countOnes or countZeros) to contribute to the score
            if(countOnes > countZeros)
            {
                // Add the score contributed by countOnes to the total score
                ans += countOnes * pow(2,m-j-1);
            }
            else
            {
                // Add the score contributed by countZeros to the total score
                ans += countZeros * pow(2,m-j-1);
            }
        }
        
        // Return the final score of the grid
        return ans;
    }
};
