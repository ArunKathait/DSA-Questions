*****************************************APPROACH 1st(BRUTE FORCE)********************************************

class Solution {// TC--->O(N*M*(N + M))                   SC--->O(N*M)
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();        // Number of rows in the matrix
        int m = matrix[0].size();     // Number of columns in the matrix
        
        // Create a temporary matrix (copy of original)
        vector<vector<int>> temp = matrix;  

        // Traverse each cell in the matrix
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {     
                // If the current cell contains 0
                if (matrix[i][j] == 0) 
                {

                    // Set the entire i-th row to 0 in the temp matrix
                    for (int k = 0; k < m; k++)
                    {
                        temp[i][k] = 0;
                    }

                    // Set the entire j-th column to 0 in the temp matrix
                    for (int k = 0; k < n; k++) 
                    {
                        temp[k][j] = 0;
                    }
                }
            }
        }

        // Copy the modified temp matrix back to the original matrix
        matrix = temp;
    }
};

*********************************************APPROACH 2nd(BETTER APPROACH)**********************************

class Solution {// TC--->O(N*M)                        SC--->O(N+M)
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();        // Number of rows in the matrix
        int m = matrix[0].size();     // Number of columns in the matrix

        vector<int> row(n);           // Array to mark which rows should be zero
        vector<int> col(m);           // Array to mark which columns should be zero

        // First pass: Identify rows and columns that contain at least one zero
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                if (matrix[i][j] == 0) 
                {
                    row[i] = 1;       // Mark i-th row for zeroing
                    col[j] = 1;       // Mark j-th column for zeroing
                }
            }
        }

        // Second pass: Set matrix elements to zero based on marked rows and columns
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                // If either the row or the column is marked, set element to zero
                if (row[i] == 1 || col[j] == 1) 
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

****************************************APPROACH 3rd(OPTIMISED APPROACH)****************************************

class Solution {// TC--->O(N*M)                     SC--->O(1)
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();        // Number of rows
        int m = matrix[0].size();     // Number of columns

        bool firstRowImpacted = false;  // Flag to check if first row needs to be zeroed
        bool firstColImpacted = false;  // Flag to check if first column needs to be zeroed

        // Check if any cell in the first column is 0
        for(int i = 0; i < n; i++) 
        {
            if(matrix[i][0] == 0) 
            {
                firstColImpacted = true;
                break;
            } 
        }

        // Check if any cell in the first row is 0
        for(int j = 0; j < m; j++) 
        {
            if(matrix[0][j] == 0) 
            {
                firstRowImpacted = true;
                break;
            }
        }

        // Use first row and first column as markers
        // If matrix[i][j] == 0, mark matrix[i][0] and matrix[0][j] as 0
        for(int i = 1; i < n; i++) 
        {
            for(int j = 1; j < m; j++) 
            {
                if(matrix[i][j] == 0) 
                {
                    matrix[i][0] = 0;  // Mark the row
                    matrix[0][j] = 0;  // Mark the column
                }
            }
        }

        // Update the cells based on markers in the first row and first column
        for(int i = 1; i < n; i++) 
        {
            for(int j = 1; j < m; j++) 
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) 
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero out the first row if needed
        if(firstRowImpacted) 
        {
            for(int j = 0; j < m; j++) 
            {
                matrix[0][j] = 0;
            }
        }

        // Zero out the first column if needed
        if(firstColImpacted) 
        {
            for(int i = 0; i < n; i++) 
            {
                matrix[i][0] = 0;
            }
        }
    }
};
