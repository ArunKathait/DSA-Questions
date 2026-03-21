
class Solution {// TC ---> O(n * m)                             SC ---> O(n * m)
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {

        // Get dimensions of grid
        int n = grid.size();
        int m = grid[0].size();

        // Prefix sum matrix for counting 'X'
        vector<vector<int>> cumulativeSumX(n, vector<int>(m));

        // Prefix sum matrix for counting 'Y'
        vector<vector<int>> cumulativeSumY(n, vector<int>(m));

        int ans = 0; // To store count of valid submatrices

        // Traverse the grid
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                // Initialize current cell:
                // If current cell is 'X', mark 1 else 0
                cumulativeSumX[i][j] = (grid[i][j] == 'X');

                // If current cell is 'Y', mark 1 else 0
                cumulativeSumY[i][j] = (grid[i][j] == 'Y');

                // Add value from top cell (building prefix sum vertically)
                if(i - 1 >= 0)
                {
                    cumulativeSumX[i][j] += cumulativeSumX[i - 1][j];
                    cumulativeSumY[i][j] += cumulativeSumY[i - 1][j];
                }

                // Add value from left cell (building prefix sum horizontally)
                if(j - 1 >= 0)
                {
                    cumulativeSumX[i][j] += cumulativeSumX[i][j - 1];
                    cumulativeSumY[i][j] += cumulativeSumY[i][j - 1];
                }

                // Subtract top-left diagonal (to avoid double counting)
                if(i - 1 >= 0 && j - 1 >= 0)
                {
                    cumulativeSumX[i][j] -= cumulativeSumX[i - 1][j - 1];
                    cumulativeSumY[i][j] -= cumulativeSumY[i - 1][j - 1];
                }

                // Now cumulativeSumX[i][j] = number of 'X' in rectangle (0,0) → (i,j)
                // Now cumulativeSumY[i][j] = number of 'Y' in rectangle (0,0) → (i,j)

                // Check condition:
                // If number of X == number of Y AND at least one exists
                if(cumulativeSumX[i][j] == cumulativeSumY[i][j] && cumulativeSumX[i][j] > 0)
                {
                    ans++; // Count this submatrix
                }
            }
        }

        return ans;
    }
};
