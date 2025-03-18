
class Solution {// TC--->O(N*M)                                   SC--->O(N*M)
public:
    // Recursive DFS function to mark reachable ocean cells
    void solve(vector<vector<int>>&heights,int row,int col,int prev,vector<vector<int>>&ocean,int n,int m)
    {
        // Base condition to stop recursion
        if(row < 0 || col < 0 || row >= n || col >= m || heights[row][col] < prev || ocean[row][col] == 1 )
        {
            // Out of bounds or invalid move
            return ;
        }
        
        // Mark the current cell as reachable
        ocean[row][col] = 1;

        // Directions for moving in 4 possible directions (up, right, down, left)
        int delRow[4] = {-1,0,1,0};
        int delCol[4] = {0,1,0,-1};
 
        // Explore all four directions
        for(int k=0;k<4;k++)
        {
            int newRow = row + delRow[k];
            int newCol = col + delCol[k];

            // Recursively check the next cell
            solve(heights,newRow,newCol,heights[row][col],ocean,n,m);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // Number of rows
        int n = heights.size();

        // Number of columns
        int m = heights[0].size();

        // Matrices to track whether a cell can reach Pacific and Atlantic Oceans
        vector<vector<int>>pacific(n,vector<int>(m,0));
        vector<vector<int>>atlantic(n,vector<int>(m,0));

        // Process all cells on the **top** and **bottom** rows
        for(int col=0;col<m;col++)
        {
            solve(heights,0,col,INT_MIN,pacific,n,m);    // Top row (Pacific)
            solve(heights,n-1,col,INT_MIN,atlantic,n,m); // Bottom row (Atlantic)
        }

        // Process all cells on the **leftmost** and **rightmost** columns
        for(int row=0;row<n;row++)
        {
            solve(heights,row,0,INT_MIN,pacific,n,m);       // Leftmost column (Pacific)
            solve(heights,row,m-1,INT_MIN,atlantic,n,m);    // Rightmost column (Atlantic)
        }
        
        // Find all cells that can reach both oceans
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // If cell can reach both oceans
                if(pacific[i][j] == 1 && atlantic[i][j] == 1)
                {
                    // Temporary vector to store coordinates
                    vector<int>temp(2,0);
                    temp[0] = i;
                    temp[1] = j;

                    // Add to result list
                    ans.push_back(temp);
                }
            }
        }
        // Return all valid coordinates
        return ans;

    }
};
