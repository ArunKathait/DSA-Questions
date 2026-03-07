*******************************************************************APPROACH 1st***********************************************************************

class Solution {// TC ---> O(4^(n×m))                                                 SC ---> O(n×m)
public:

    // DFS function that tries to find the longest increasing path
    // starting from (row, col)
    int solve(int row,int col,int n,int m,vector<vector<int>>&matrix,int prev)
    {
        // Base Case:
        // 1. If we go outside the matrix
        // 2. If the current value is not strictly greater than previous value
        // then this path cannot continue
        if(row < 0 || col < 0 || row >= n || col >= m || matrix[row][col] <= prev)
        {
            return 0;
        }

        // path will store the longest path length from this cell
        int path = 0;

        // 4 possible directions: up, right, down, left
        vector<int>delRow = {-1,0,1,0};
        vector<int>delCol = {0,1,0,-1};

        // explore all 4 neighbours
        for(int k=0;k<4;k++)
        {
            int newRow = row + delRow[k];
            int newCol = col + delCol[k];

            // recursively ask neighbour:
            // "If I move to you, what is the longest path you can give me?"
            // add 1 because we are making one move to that neighbour
            path = max(path,1 + solve(newRow,newCol,n,m,matrix,matrix[row][col]));
        }

        // return the best path found from this cell
        return path;

    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        // ans will store the longest path in the whole matrix
        int ans = 0;

        // try starting DFS from every cell
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // compute longest path starting from (i,j)
                ans = max(ans,solve(i,j,n,m,matrix,INT_MIN));
            }
        }

        return ans;
    }
};

***********************************************************************APPROACH 2nd(MEMOIZATION)*************************************************************

class Solution {// TC ---> O(n × m)                               SC ---> O(n × m)
public:

    // DFS function that calculates the longest increasing path
    // starting from cell (row, col)
    int solve(int row,int col,int n,int m,vector<vector<int>>&matrix,int prev,vector<vector<int>>&dp)
    {
        // Base condition:
        // 1. If we move outside the matrix
        // 2. If the current cell value is not strictly greater than the previous value
        // then this path cannot continue
        if(row < 0 || col < 0 || row >= n || col >= m || matrix[row][col] <= prev)
        {
            return 0;
        }

        // If we have already computed the longest path from this cell,
        // return the stored result (DP memoization)
        if(dp[row][col] != -1)
        {
            return dp[row][col];
        }

        // path stores the longest path length starting from this cell
        int path = 0;

        // Direction vectors to move in 4 directions:
        // up, right, down, left
        vector<int>delRow = {-1,0,1,0};
        vector<int>delCol = {0,1,0,-1};

        // Explore all 4 neighbours
        for(int k=0;k<4;k++)
        {
            int newRow = row + delRow[k];
            int newCol = col + delCol[k];

            // Recursively ask neighbour:
            // "If I move to you, what is the longest increasing path you can give me?"
            // Add 1 because we are making one move from current cell to neighbour
            path = max(path,1 + solve(newRow,newCol,n,m,matrix,matrix[row][col],dp));
        }

        // Store the result in DP so that future calls reuse it
        return dp[row][col] = path;

    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        // This DP array stores the longest increasing path starting from each cell
        vector<vector<int>>dp(n,vector<int>(m,-1));

        int ans = 0;

        // Try starting the path from every cell
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // Compute longest path starting from (i,j)
                ans = max(ans,solve(i,j,n,m,matrix,INT_MIN,dp));
            }
        }

        // Return the maximum path found in the matrix
        return ans;
    }
};

// NOTE : current cell + neighbour's longest path    i.e 1 + neighbour_path
