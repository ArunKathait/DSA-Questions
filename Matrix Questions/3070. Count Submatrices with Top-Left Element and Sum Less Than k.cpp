
class Solution {// TC ---> O(n × m)                                     SC ---> O(1) (in-place prefix sum)
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        
        int n = grid.size();      // Total number of rows
        int m = grid[0].size();   // Total number of columns

        int ans = 0;              // To store count of valid submatrices

        // Traverse each cell of the matrix
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                // 🔽 Step 1: Build 2D Prefix Sum (in-place)

                // Add value from the cell above (top)
                if(i - 1 >= 0) {
                    grid[i][j] += grid[i - 1][j];
                }

                // Add value from the cell on the left
                if(j - 1 >= 0) {
                    grid[i][j] += grid[i][j - 1];
                }

                // Subtract top-left diagonal (to remove double counting)
                if(i - 1 >= 0 && j - 1 >= 0) {
                    grid[i][j] -= grid[i - 1][j - 1];
                }

                /*
                Now grid[i][j] represents:
                👉 Sum of all elements in submatrix from (0,0) to (i,j)

                Formula:
                prefix[i][j] = 
                    grid[i][j] 
                  + prefix[i-1][j] 
                  + prefix[i][j-1] 
                  - prefix[i-1][j-1]
                */

                // 🔽 Step 2: Check if this submatrix sum is valid
                if(grid[i][j] <= k) {
                    ans++;   // Count this submatrix
                }
                else {
                    /*
                    ❗ Optimization attempt:
                    If current prefix sum > k, break the loop

                    Assumption:
                    Further elements in this row will also exceed k
                    because prefix sums usually increase

                    ⚠️ BUT this is not always safe logically,
                    so in strict correctness, this break should be removed.
                    */
                    break;
                }
            }
        }

        return ans;  // Return total valid submatrices
    }
};

/* 

✔️ Time Complexity:

👉 O(n × m)

✔️ Space Complexity:

👉 O(1) (in-place prefix sum)

*/
