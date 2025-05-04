*********************************************APPROACH 1st***************************************************

// Here we are converting char to int and then storing into unordered_set

class Solution {// TC--->O(1)                              SC--->O(1)
public:

    // Helper function to check if a 3x3 subgrid (box) is valid
    bool validBox(int startRow, int endRow, int startCol, int endCol, vector<vector<char>>& board)
    {
        // Set to track unique digits
        unordered_set<int> set;  

        // Loop through each cell in the 3x3 subgrid
        // ✅ should include endRow
        for(int i = startRow; i <= endRow; i++) 
        {
            // ✅ should include endCol
            for(int j = startCol; j <= endCol; j++) 
            {
                // Skip empty cells
                if(board[i][j] == '.') 
                {
                    continue;
                } 
                
                // Convert char to int
                int num = board[i][j] - '0'; 

                if(set.find(num) != set.end())
                {
                    // Duplicate found in the subgrid
                    return false;
                }

                // Add digit to the set
                set.insert(num); 
            }
        }
        // Subgrid is valid
        return true; 
    }

    // Main function to check if the entire Sudoku board is valid
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();     // Typically 9
        int m = board[0].size();  // Typically 9

        // ✅ 1. Check each row
        for(int row = 0; row < n; row++)
        {
            // Set for digits in the row
            unordered_set<int> set; 
            for(int col = 0; col < m; col++)
            {
                if(board[row][col] == '.') 
                {
                    // Skip empty cells
                    continue; 
                }

                int num = board[row][col] - '0';

                if(set.find(num) != set.end())
                {
                    // Duplicate in the row
                    return false;
                }
                
                // Add to the row's set
                set.insert(num); 
            }
        }

        // ✅ 2. Check each column
        for(int col = 0; col < m; col++)
        {
            // Set for digits in the column
            unordered_set<int> set; 

            for(int row = 0; row < n; row++)
            {
                if(board[row][col] == '.') 
                {
                    // Skip empty cells
                    continue; 
                }

                int num = board[row][col] - '0';

                if(set.find(num) != set.end())
                {
                    // Duplicate in the column
                    return false; 
                }
                
                // Add to the column's set
                set.insert(num); 
            }
        }

        // ✅ 3. Check each 3x3 subgrid
        for(int startRow = 0; startRow < n; startRow += 3)
        {
            int endRow = startRow + 2;

            for(int startCol = 0; startCol < m; startCol += 3)
            {
                int endCol = startCol + 2;

                if(validBox(startRow, endRow, startCol, endCol, board) == false)
                {
                    // One of the subgrids is invalid
                    return false; 
                }
            }
        }
 
        // All rows, columns, and subgrids are valid
        return true; 
    }
};

*******************************************APPROACH 2nd********************************************************
// Here we do not convert char to int because we will use unordered_set of char here.

class Solution {// TC--->O(1)                       SC--->O(1)
public:

    // Helper function to validate a 3x3 subgrid
    bool validBox(int startRow, int endRow, int startCol, int endCol, vector<vector<char>>& board)
    {
        // 🔸 Stores digits '1' to '9' (as chars), max size = 9 → O(1) space
        unordered_set<char> set; 
        
        // Loop over rows of the 3x3 box
        for(int i = startRow; i <= endRow; i++)  
        {
            // Loop over columns of the box
            for(int j = startCol; j <= endCol; j++)  
            {
                if(board[i][j] == '.') 
                {
                    // Skip empty cells
                    continue; 
                } 

                if(set.find(board[i][j]) != set.end())
                {
                    // Duplicate found in box
                    return false;  
                }
                
                // Add digit to set
                set.insert(board[i][j]);  
            }
        }
        // No duplicates in the 3x3 box
        return true;  
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();     // Usually 9
        int m = board[0].size();  // Usually 9

        // 🔹 Check each row
        for(int row = 0; row < n; row++)
        {
            // 🔸 Max 9 digits per row → O(1) space
            unordered_set<char> set;  

            for(int col = 0; col < m; col++)
            {
                if(board[row][col] == '.') 
                {
                    continue;
                }

                if(set.find(board[row][col]) != set.end())
                {
                    // Duplicate in row
                    return false;  
                }
                    

                set.insert(board[row][col]);
            }
        }

        // 🔹 Check each column
        for(int col = 0; col < m; col++)
        {
            // 🔸 Max 9 digits per column → O(1) space
            unordered_set<char> set;  

            for(int row = 0; row < n; row++)
            {
                if(board[row][col] == '.') 
                {
                    continue;
                }

                if(set.find(board[row][col]) != set.end())
                {
                    // Duplicate in column
                    return false;  
                }
                   

                set.insert(board[row][col]);
            }
        }

        // 🔹 Check each 3x3 subgrid
        for(int startRow = 0; startRow < n; startRow += 3)
        {
            int endRow = startRow + 2;

            for(int startCol = 0; startCol < m; startCol += 3)
            {
                int endCol = startCol + 2;

                if(!validBox(startRow, endRow, startCol, endCol, board))
                {
                    // Duplicate in 3x3 subgrid
                    return false;  
                }
            }
        }
        // All rows, columns, and boxes are valid
        return true;  
    }
};

****************************************APPROACH 3rd*******************************************************

class Solution {// TC--->O(1)                                     SC--->O(1)
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Get the number of rows and columns of the board
        int n = board.size();
        int m = board[0].size();

        // Use a single unordered_set to track seen values in rows, columns, and boxes
        unordered_set<string> set;

        // Iterate over every cell in the board
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                // Skip empty cells (denoted by '.')
                if (board[i][j] == '.') 
                {
                    continue;
                }

                // Construct unique string keys for the current digit in row, column, and box
                string row = string(1, board[i][j]) + "_ROW_" + to_string(i);               // e.g., "5_ROW_0"
                string col = string(1, board[i][j]) + "_COL_" + to_string(j);               // e.g., "5_COL_1"
                string box = string(1, board[i][j]) + "_BOX_" + to_string(i/3) + "_" + to_string(j/3); // e.g., "5_BOX_0_0"

                // If any of the keys already exist in the set, the board is invalid
                if (set.find(row) != set.end() || set.find(col) != set.end() || set.find(box) != set.end()) 
                {
                    return false;
                }

                // Insert the keys into the set to mark the digit as seen in that row, column, and box
                set.insert(row);
                set.insert(col);
                set.insert(box);
            }
        }

        // If no duplicates found, the board is valid
        return true;
    }
};

/*  
      Summary of the Logic:
                    We track each number's occurrence in:
                    its row (e.g., "5_ROW_0")
                    its column (e.g., "5_COL_1")
                    its 3×3 box (e.g., "5_BOX_0_0")
                    If any of these keys already exist in the set, it means the number has already been seen → invalid Sudoku.

*/
