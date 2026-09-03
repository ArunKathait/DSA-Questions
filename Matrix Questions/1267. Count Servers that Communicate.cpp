
class Solution {// Time  → O(n × m)                        Space → O(n + m) 
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();              // Number of rows
        int m = grid[0].size();           // Number of columns

        // rowCount[i] = number of servers in row i
        vector<int> rowCount(n, 0);

        // colCount[j] = number of servers in column j
        vector<int> colCount(m, 0);

        // First pass:
        // Count how many servers are present in every row and every column.
        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j < m; j++) 
            {
                // grid[i][j] == 1 means there is a server at (i, j)
                if(grid[i][j] == 1) 
                {
                    rowCount[i]++;       // Increase server count of this row
                    colCount[j]++;       // Increase server count of this column
                }
            }
        }

        int ans = 0;

        // Second pass:
        // Check every server and determine whether it can communicate
        // with at least one other server.
        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j < m; j++) 
            {
                // Only consider cells containing a server
                if(grid[i][j] == 1) 
                {
                    // A server can communicate if:
                    // 1. There is another server in the same row
                    // OR
                    // 2. There is another server in the same column
                    //
                    // rowCount[i] > 1 means there is at least one
                    // other server in this row.
                    //
                    // colCount[j] > 1 means there is at least one
                    // other server in this column.
                    if(rowCount[i] > 1 || colCount[j] > 1) 
                    {
                        ans++;            // This server can communicate
                    }
                }
            }
        }

        // Return total number of servers that can communicate
        return ans;
    }
};

/*  

┌──────────────────────────────────────────┐
│          COUNT SERVERS — CHEAT BOX       │
├──────────────────────────────────────────┤
│ Server = 1                               │
│                                          │
│ STEP 1:                                  │
│ Count servers in every row and column.   │
│                                          │
│ rowCount[i] = servers in row i           │
│ colCount[j] = servers in column j        │
│                                          │
│ STEP 2:                                  │
│ For every server:                        │
│                                          │
│ rowCount[i] > 1  OR  colCount[j] > 1     │
│              ↓                           │
│ Server can communicate                   │
│                                          │
│ Otherwise → isolated server → don't count│
├──────────────────────────────────────────┤
│ TIME  : O(n × m)                         │
│ SPACE : O(n + m)                         │
└──────────────────────────────────────────┘

*/
