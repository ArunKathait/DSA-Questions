************************************************APPROACH 1st*********************************************************

class Solution {// Time Complexity: O(m × n)               Auxiliary Space: O(m × n)
public:
    vector<string> createGrid(int m, int n) {

        // Create an m x n grid filled entirely with '#'.
        // m = number of rows, n = number of columns.
        vector<vector<char>> ans(m, vector<char>(n, '#'));

        // Make every cell in the first row '.'.
        // Row index 0 represents the first row.
        for (int j = 0; j < n; j++) 
        {
            ans[0][j] = '.';
        }

        // Make every cell in the last column '.'.
        // Column index n - 1 represents the last column.
        for (int i = 0; i < m; i++) 
        {
            ans[i][n - 1] = '.';
        }

        // Create a vector of strings to store the final grid.
        vector<string> res;

        // Convert each row of characters into a string.
        for (int i = 0; i < m; i++) 
        {
            // Store the current row as a string.
            string current;

            for (int j = 0; j < n; j++) 
            {
                // Append the current grid character to the string.
                current += ans[i][j];
            }

            // Add the completed row to the result.
            res.push_back(current);
        }

        // Return the grid as a vector of strings.
        return res;
    }
};


*************************************************APPROACH 2nd*********************************************************

class Solution {// Time Complexity: O(m × n)            Auxiliary Space: O(m × n)
public:
    vector<string> createGrid(int m, int n) {

        // Create the first row containing n dots.
        // Example: if n = 4, topRow = "...."
        string topRow(n, '.');

        // Create the remaining rows:
        // Add n - 1 '#' characters followed by one '.'.
        // Example: if n = 4, remainingRow = "###."
        string remainingRow = string(n - 1, '#') + '.';

        // Store all rows of the grid as strings.
        vector<string> ans;

        // The first row contains only dots.
        ans.push_back(topRow);

        // Create the remaining m - 1 rows.
        // Each of these rows is identical to remainingRow.
        for (int i = 1; i < m; i++) 
        {
            ans.push_back(remainingRow);
        }

        // Return the completed grid.
        return ans;
    }
};

/*

┌──────────────────────────────────────┐
│ Create Grid                          │
├──────────────────────────────────────┤
│ 1. Create top row of n dots ('.').   │
│ 2. Create remaining row:             │
│    (n - 1) '#' + one '.'.            │
│ 3. Add top row to the result.        │
│ 4. Repeat remaining row m - 1 times. │
│ 5. Return the grid.                  │
├──────────────────────────────────────┤
│ Key Trick:                           │
│ Create two row patterns and reuse    │
│ them to build the grid.              │
├──────────────────────────────────────┤
│ Time Complexity:       O(m × n)      │
│ Auxiliary Space:       O(m × n)      │
│ Extra Space:           O(1)          │
└──────────────────────────────────────┘

*/
