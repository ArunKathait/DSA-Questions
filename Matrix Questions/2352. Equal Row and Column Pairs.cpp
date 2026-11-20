*************************************************APPROACH 1st(BRUTE FORCE)*********************************************

class Solution {// Time Complexity:  O(n³)                                Space Complexity: O(1)
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();

        // Stores the total number of equal row-column pairs.
        int ans = 0;

        // Iterate through every row.
        for(int row = 0; row < n; row++)
        {
            // Iterate through every column.
            // Each (row, col) combination represents one pair.
            for(int col = 0; col < n; col++)
            {
                // Assume the current row and column are equal.
                bool isEqual = true;

                // Compare corresponding elements of the row and column.
                for(int k = 0; k < n; k++)
                {
                    // grid[row][k] represents the kth element of the row.
                    // grid[k][col] represents the kth element of the column.
                    if(grid[row][k] != grid[k][col])
                    {
                        // If any element differs, they are not equal.
                        isEqual = false;

                        // No need to check further elements.
                        break;
                    }
                }

                // If all elements match, increment the answer.
                if(isEqual)
                {
                    ans++;
                }
            }
        }

        // Return the total number of equal row-column pairs.
        return ans;
    }
};

/*

┌──────────────────────────────────────────────┐
│ Equal Row and Column Pairs                   │
├──────────────────────────────────────────────┤
│ Approach: Brute Force (3 Nested Loops)       │
│                                              │
│ Key Idea:                                    │
│ Compare every possible row-column pair.      │
│ Check corresponding elements one by one.     │
│ If any element differs, stop comparison.     │
│ If all elements match, increment ans.        │
│                                              │
│ Comparison:                                  │
│ grid[row][k] == grid[k][col]                 │
│                                              │
│ Time Complexity:  O(n³)                      │
│ Space Complexity: O(1)                       │
│ Extra Space:      O(1)                       │
└──────────────────────────────────────────────┘

*/

***********************************************APPROACH 2nd(OPTIMAL)****************************************************

class Solution {// Time Complexity:  O(n²)                             Space Complexity: O(n²)
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();

        // Stores each row as a string along with its frequency.
        unordered_map<string, int> ump;

        // Traverse every row.
        for(int row = 0; row < n; row++)
        {
            // Create a unique string representation of the current row.
            string key;

            for(int col = 0; col < n; col++)
            {
                // Convert each element into a string and append a delimiter.
                // '#' prevents collisions between different integer sequences.
                key += to_string(grid[row][col]) + "#";
            }

            // Increase the frequency of this row in the HashMap.
            ump[key]++;
        }

        // Stores the total number of equal row-column pairs.
        int ans = 0;

        // Traverse every column.
        for(int col = 0; col < n; col++)
        {
            // Create a string representation of the current column.
            string key;

            for(int row = 0; row < n; row++)
            {
                // Extract elements from top to bottom.
                // Append them in the same order as row elements.
                key += to_string(grid[row][col]) + "#";
            }

            // Check whether this column matches any stored row.
            // Add the frequency because multiple identical rows may exist.
            ans += ump[key];
        }

        // Return the total number of equal row-column pairs.
        return ans;
    }
};

/*

┌──────────────────────────────────────────────┐
│ Equal Row and Column Pairs                   │
├──────────────────────────────────────────────┤
│ Approach: HashMap (Frequency Counting)       │
│                                              │
│ Key Idea:                                    │
│ Convert each row into a string and store its │
│ frequency in an unordered_map.               │
│                                              │
│ Convert each column into a string and check  │
│ its frequency in the HashMap.                │
│ Add the frequency to ans to handle duplicate │
│ rows and columns.                            │
│                                              │
│ Delimiter (#): Avoids string key collisions. │
│                                              │
│ Time Complexity:  O(n²) Average              │
│ Space Complexity: O(n²)                      │
│ Extra Space:      O(n²)                      │
└──────────────────────────────────────────────┘

*/
