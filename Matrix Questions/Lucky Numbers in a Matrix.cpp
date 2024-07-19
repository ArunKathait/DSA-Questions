*************************************************APPROACH 1st*****************************************************
  
class Solution {// TC--->O(n*m)           SC--->O(n+m)
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        // Vectors to store the minimum value of each row and the maximum value of each column
        vector<int>minRow;
        vector<int>maxCol;
        
        // Finding the minimum element in each row
        for(int i=0;i<matrix.size();i++)
        {
            // Initialize minimum value as the maximum possible integer
            int mini = INT_MAX;
            for(int j=0;j<matrix[0].size();j++)
            {
                // Update mini if a smaller element is found
                mini = min(mini,matrix[i][j]);
            }
            // Store the minimum value of the current row
            minRow.push_back(mini);
        }
        
        // Finding the maximum element in each column
        for(int j=0;j<matrix[0].size();j++)
        {
            // Initialize maximum value as the minimum possible integer
            int maxi = INT_MIN;
            for(int i=0;i<matrix.size();i++)
            {
                // Update maxi if a larger element is found
                maxi = max(maxi,matrix[i][j]);
            }
            // Store the maximum value of the current column
            maxCol.push_back(maxi);
        }
        
        // Finding the lucky numbers
        // Vector to store the lucky numbers
        vector<int>ans;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                // Check if the current element is the minimum in its row and the maximum in its column
                if(minRow[i] == matrix[i][j] && maxCol[j] == matrix[i][j])
                {
                    // Add the element to the result vector if it is a lucky number
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        // Return the vector of lucky numbers
        return ans;
    }
};


*******************************************APPROACH 2nd(BETTER APPROACH)**************************************

class Solution {// TC--->O(N*M)              SC--->O(1)
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        // Number of rows in the matrix
        int n = matrix.size();
        
        // Number of columns in the matrix
        int m = matrix[0].size();
        
        // Variable to track the maximum of row minimums
        int rowMinMax = INT_MIN;
        
        // Iterate over each row
        for(int i=0;i<n;i++)
        {
            // Initialize the minimum value in the current row as the maximum possible integer
            int rowMin = INT_MAX;
            
            // Iterate over each element in the current row
            for(int j=0;j<m;j++)
            {
                // Update rowMin if a smaller element is found
                rowMin = min(rowMin,matrix[i][j]);
            }
            
            // Update rowMinMax to the maximum of the current row minimums
            rowMinMax = max(rowMinMax,rowMin);
        }
        
         // Variable to track the minimum of column maximums
        int colMaxMin = INT_MAX;
        
        // Iterate over each column
        for(int j=0;j<m;j++)
        {
            // Initialize the maximum value in the current column as the minimum possible integer
            int colMax = INT_MIN;
            
            // Iterate over each element in the current column
            for(int i=0;i<n;i++)
            {
                // Update colMax if a larger element is found
                colMax = max(colMax,matrix[i][j]);
            }
            
            // Update colMaxMin to the minimum of the current column maximums
            colMaxMin = min(colMaxMin,colMax);
        }
        
        // Check if the maximum of row minimums is equal to the minimum of column maximums
        if(rowMinMax == colMaxMin)
        {
            // Return the common element as the lucky number
            return {rowMinMax};
        }
       
        // Return an empty vector if no lucky number is found
        return {};
    }
};
