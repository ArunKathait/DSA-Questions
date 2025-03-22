
class Solution {
public:
    // Recursive function to perform DFS to find the word in the board
    bool solve(vector<vector<char>>& board, string &word, int row, int col, int n, int m, int index, vector<vector<bool>>& visited) 
    {
        // If all characters of the word are found, return true
        if (index == word.length()) 
        {
            return true;
        }

        // Boundary and validity checks:
        // 1. row < 0 || col < 0 || row >= n || col >= m → Out of bounds
        // 2. visited[row][col] → The cell has already been visited in the current path
        // 3. board[row][col] != word[index] → Current cell does not match the required character
        if (row < 0 || col < 0 || row >= n || col >= m || visited[row][col] || board[row][col] != word[index]) {
            return false;
        }

        // Mark the current cell as visited
        visited[row][col] = true;

        // Define movement directions (Up, Right, Down, Left)
        static int delRow[] = {-1, 0, 1, 0};
        static int delCol[] = {0, 1, 0, -1};

        // Explore all four possible directions
        for (int k = 0; k < 4; k++) 
        {
            int newRow = row + delRow[k];
            int newCol = col + delCol[k];

            // Recursively check if the next character in the word can be found
            if (solve(board, word, newRow, newCol, n, m, index + 1, visited))
            {
                return true;
            }
        }

        // Backtrack: Unmark the cell before returning false
        visited[row][col] = false;
        return false;
    }

    // Main function to check if the word exists in the board
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();  // Number of rows
        int m = board[0].size(); // Number of columns

        // Create a visited matrix to track used cells in the current path
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Early termination: If word length is greater than total cells, return false
        if (word.length() > n * m) 
        {
            return false;
        }

        // Iterate through each cell in the board to find the first character of the word
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                // If the first character of the word matches, start DFS search
                if (board[i][j] == word[0] && solve(board, word, i, j, n, m, 0, visited)) 
                {
                    return true;  // If found, return true
                }
            }
        }

        // If no match found, return false
        return false;
    }
};
