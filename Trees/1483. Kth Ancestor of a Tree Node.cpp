
class TreeAncestor { //  Preprocessing: O(n log n)    Query: O(log n)       Space: O(n log n)
public:

    // ancestorTable[node][j] =
    // the 2^j-th ancestor of 'node'
    //
    // Example:
    // j = 0 → 1st ancestor
    // j = 1 → 2nd ancestor
    // j = 2 → 4th ancestor
    // j = 3 → 8th ancestor
    vector<vector<int>> ancestorTable;

    // Number of nodes
    int rows;

    // Number of columns needed for binary lifting
    int cols;


    TreeAncestor(int n, vector<int>& parent) {

        rows = n;

        // We need columns for:
        // 2^0, 2^1, 2^2, ... up to n
        //
        // log2(n) gives the highest power of 2 we need.
        // +1 because we also need column 0.
        //
        // Example:
        // n = 8
        // log2(8) = 3
        // cols = 4
        //
        // Columns represent:
        // 1, 2, 4, 8 ancestors
        cols = log2(n) + 1;


        // Create n rows and cols columns.
        //
        // Initially every ancestor is -1,
        // meaning that ancestor doesn't exist.
        ancestorTable.resize(rows, vector<int>(cols, -1));


        // Fill the first column.
        //
        // ancestorTable[node][0] represents
        // the 2^0 = 1st ancestor of node.
        //
        // parent[node] is exactly the 1st ancestor.
        for (int node = 0; node < n; node++) 
        {
            ancestorTable[node][0] = parent[node];
        }


        // Build the remaining columns using
        // previously calculated ancestors.
        //
        // j represents 2^j-th ancestor.
        for (int j = 1; j < cols; j++) 
        {
            for (int node = 0; node < n; node++) 
            {
                // If the 2^(j-1)-th ancestor exists,
                // we can find the 2^j-th ancestor.
                if (ancestorTable[node][j - 1] != -1) 
                {
                    // Suppose we want the 8th ancestor.
                    //
                    // 8 = 4 + 4
                    //
                    // First go 4 ancestors up:
                    // ancestorTable[node][2]
                    //
                    // Then go another 4 ancestors up:
                    // ancestorTable[thatNode][2]
                    //
                    // Therefore:
                    //
                    // 2^j ancestor
                    // =
                    // 2^(j-1) ancestor
                    // +
                    // another 2^(j-1) ancestor

                    ancestorTable[node][j] = ancestorTable[ ancestorTable[node][j - 1] ][j - 1];
                }
            }
        }
    }


    int getKthAncestor(int node, int k) {

        // We use the binary representation of k.
        //
        // Example:
        // k = 13
        //
        // Binary:
        // 1101
        //
        // 13 = 8 + 4 + 1
        //
        // So instead of moving 13 times,
        // we can move:
        //
        // 8 ancestors
        // + 4 ancestors
        // + 1 ancestor
        //
        // This is the main advantage of Binary Lifting.

        for (int j = 0; j < cols; j++) 
        {
            // Check whether the j-th bit of k is 1.
            //
            // (1 << j) means 2^j.
            //
            // If this bit is set, we need to move
            // 2^j ancestors upward.
            if (k & (1 << j)) 
            {
                // Move node to its 2^j-th ancestor.
                node = ancestorTable[node][j];


                // If there is no such ancestor,
                // return -1.
                if (node == -1) 
                {
                    return -1;
                }
            }
        }

        // We have moved exactly k ancestors upward.
        return node;
    }
};

/*

┌─────────────────────────────────────────┐
│           Kth ANCESTOR                  │
├─────────────────────────────────────────┤
│ Pattern: Binary Lifting / Jump Table    │
│                                         │
│ State:                                  │
│ ancestor[node][j] = 2^j-th ancestor     │
│                                         │
│ Base:                                   │
│ ancestor[node][0] = parent[node]        │
│                                         │
│ Formula:                                │
│ ancestor[node][j] =                     │
│ ancestor[ancestor[node][j-1]][j-1]      │
│                                         │
│ Query:                                  │
│ Convert k into binary.                  │
│ If (k & (1 << j)) → make 2^j jump       │
│                                         │
│ Preprocessing: O(n log n)               │
│ Query:        O(log n)                  │
│ Space:        O(n log n)                │
└─────────────────────────────────────────┘

*/
