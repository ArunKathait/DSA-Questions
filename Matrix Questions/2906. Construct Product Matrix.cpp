
class Solution {// TC ---> O(n × m) + O(n × m) = O(n × m)                                 SC ---> O(1) auxiliary space (excluding output matrix)
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        
        int M = 12345;  // modulo value
        int n = grid.size();
        int m = grid[0].size();

        // This matrix will store the final result
        // Initially we will use it to store suffix products
        vector<vector<int>> p(n, vector<int>(m, 1));
        
        // -------------------------------
        // STEP 1: Compute SUFFIX product
        // -------------------------------
        // suffix = product of all elements AFTER current cell
        long long suffix = 1;

        // Traverse from bottom-right → top-left
        for(int i = n - 1; i >= 0; i--) 
        {
            for(int j = m - 1; j >= 0; j--) 
            {

                // Store suffix product for current cell
                // (product of all elements to the right + below in flattened order)
                p[i][j] = suffix;

                // Update suffix by multiplying current element
                suffix = (suffix * grid[i][j]) % M;
            }
        }

        // -------------------------------
        // STEP 2: Compute PREFIX product
        // -------------------------------
        // prefix = product of all elements BEFORE current cell
        long long prefix = 1;

        // Traverse from top-left → bottom-right
        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j < m; j++) 
            {

                // Multiply prefix (left side) with suffix (already stored in p)
                // This gives product of all elements except current
                p[i][j] = (prefix * p[i][j]) % M;

                // Update prefix by multiplying current element
                prefix = (prefix * grid[i][j]) % M;
            }
        }

        // Final result matrix
        return p;
    }
};
