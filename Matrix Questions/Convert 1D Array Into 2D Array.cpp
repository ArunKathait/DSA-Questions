*****************************************************APPROACH 1st*******************************************************

class Solution {// TC--->O(m * n)                       SC--->O(m * n)
public: 
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // Check if the size of the original 1D vector matches the total number of elements required in the 2D array
        if(original.size() != m * n)
        {
            // Return an empty 2D vector if the sizes do not match
            return {};
        }
        
        // Initialize a 2D vector 'ans' with 'm' rows and 'm' columns (should be 'n' columns)
        vector<vector<int>>ans(m,vector<int>(n));
        
        // Initialize an index to track the position in the original 1D array
        int index = 0;
        
        // Fill the 2D vector 'ans' with elements from the 1D 'original' vector
        for(int i=0;i<m;i++)// Loop through each row
        {
            for(int j=0;j<n;j++)// Loop through each column in the current row
            {
                // Assign the element from 'original' to the current position in 'ans'
                ans[i][j] = original[index];
                
                // Increment the index to move to the next element in 'original'
                index++;
            }
        }
        
        // Return the constructed 2D vector
        return ans;
    }
};

****************************************************APPROACH 2nd********************************************************

class Solution {// TC--->O(m * n)                       SC--->O(m * n)
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // Check if the total number of elements in 'original' matches the required number of elements (m * n) in the 2D array
        if(original.size() != m * n)
        {
            // Return an empty 2D vector if sizes don't match
            return {};
        }
        
        // Initialize a 2D vector 'ans' with 'm' rows and 'n' columns
        vector<vector<int>>ans(m,vector<int>(n));
        
        // Loop through each element in the 'original' vector
        for(int i=0;i<original.size();i++)
        {
            // Calculate the row index for the current element
            int row = i/n;
            
            // Calculate the column index for the current element
            int col = i%n;
            
            // Assign the element from 'original' to the calculated position in 'ans'
            ans[row][col] = original[i];
        }

        // Return the constructed 2D vector
        return ans;
    }
};

/*
  NOTE:
       If we want to convert 1D Array to 2D Array then we just do below steps:
       For Row-----> i/col;
       For Col-----> i%col;
       where i is index of 1D Array and col is column which is given (i.e col we have to make in new 2D Array)

*/

