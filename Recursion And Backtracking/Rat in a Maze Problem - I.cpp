******************************************************APPROACH 1st********************************************************

class Solution {
public:

    // Function to check if the current cell (row, col) is a valid and safe move
    bool isSafe(int row, int col, vector<vector<int>>& visited, vector<vector<int>>& mat) {
        // Check if the cell is within bounds, is not visited yet, and has a value of 1
        return (row >= 0 && row < mat.size() && col >= 0 && col < mat.size() && mat[row][col] == 1 && visited[row][col] == 0);
    }

    // Recursive function to explore all possible paths from the current cell
    void solve(int row, int col, vector<vector<int>>& visited, vector<vector<int>>& mat, string path, vector<string>& ans) {
        // If the current cell is not safe, return and backtrack
        if (!isSafe(row, col, visited, mat)) 
        {
            return;
        }

        // If the destination (bottom-right corner) is reached, add the current path to the answer list
        if (row == mat.size() - 1 && col == mat.size() - 1) 
        {
            ans.push_back(path);
            return;
        }

        // Mark the current cell as visited to prevent revisiting
        visited[row][col] = 1;

        // Explore the Up direction
        path.push_back('U'); // Add 'U' to the path for the Up move
        solve(row - 1, col, visited, mat, path, ans); // Recursively explore the cell above
        path.pop_back(); // Backtrack: Remove 'U' from the path string

        // Explore the Left direction
        path.push_back('L'); // Add 'L' to the path for the Left move
        solve(row, col - 1, visited, mat, path, ans); // Recursively explore the cell to the left
        path.pop_back(); // Backtrack: Remove 'L' from the path string

        // Explore the Down direction
        path.push_back('D'); // Add 'D' to the path for the Down move
        solve(row + 1, col, visited, mat, path, ans); // Recursively explore the cell below
        path.pop_back(); // Backtrack: Remove 'D' from the path string

        // Explore the Right direction
        path.push_back('R'); // Add 'R' to the path for the Right move
        solve(row, col + 1, visited, mat, path, ans); // Recursively explore the cell to the right
        path.pop_back(); // Backtrack: Remove 'R' from the path string

        // Backtrack: Mark the current cell as unvisited to allow other paths to use it
        visited[row][col] = 0;
    }

    // Function to find all possible paths from the top-left to the bottom-right corner of the matrix
    vector<string> findPath(vector<vector<int>>& mat) {
        int n = mat.size(); // Get the size of the matrix (assuming it's n x n)

        // Create a visited matrix initialized to 0 (all cells are unvisited initially)
        vector<vector<int>> visited(n, vector<int>(n, 0));

        vector<string> ans; // Vector to store all valid paths
        string path = ""; // String to store the current path

        // Start exploring from the top-left corner (0, 0)
        solve(0, 0, visited, mat, path, ans);

        return ans; // Return the vector of all valid paths
    }
};

******************************************************APPROACH 2nd********************************************************

class Solution {// TC--->O(4^N * N)              SC--->O(N^2 + 4^N * N)
  public:
  // Function to check if the current cell (row, col) is a valid and safe move
  bool isSafe(int row,int col,vector<vector<int>>&visited,vector<vector<int>>&mat)
  {
       // Check if the cell is within bounds, is not visited yet, and has a value of 1
      if(row >= 0 && row < mat.size() && col >= 0 && col < mat.size() && mat[row][col] == 1
      && visited[row][col] == 0)
      {
          return true;
      }
      return false;
  }
  
  // Recursive function to explore all possible paths from the current cell
  void solve(int row,int col,vector<vector<int>>&visited,vector<vector<int>
  >&mat,string path,vector<string>&ans)
  {
          // If the current cell is not safe, return and backtrack
          if(!isSafe(row,col,visited,mat))
          {
              return ;
          }
          
          // If the destination (bottom-right corner) is reached, add the current path to the answer list
          if(row == mat.size()-1 && col == mat.size()-1)
          {
              ans.push_back(path);
              return ;
          }
          
     
          // Mark the current cell as visited to prevent revisiting
          visited[row][col] = 1;
          
          // Arrays to move in the 4 possible directions: Down, Left, Right, Up
          int delRow[4] = {1,0,0,-1};// Changes in row number for each direction
          int delCol[4] = {0,-1,1,0};// Changes in column number for each direction
          char direction[4] = {'D','L','R','U'};// Corresponding characters for the directions
          
          // Explore all 4 possible directions
          for(int k=0;k<4;k++)
          {
              // Calculate the new row index
              int newRow = row + delRow[k];
              
              // Calculate the new column index
              int newCol = col + delCol[k];
              
              // Append the current direction to the path and recursively explore the new cell
              path.push_back(direction[k]);
              solve(newRow,newCol,visited,mat,path,ans);
              
              // Backtrack: Remove the last direction from the path string
              path.pop_back();
              
          }
          
          // Backtrack: Mark the current cell as unvisited to allow other paths to use it
          visited[row][col] = 0;
     
  }
  
  // Function to find all possible paths from the top-left to the bottom-right corner of the matrix
    vector<string> findPath(vector<vector<int>> &mat) {
        
        // Get the size of the matrix (assuming it's n x n)
        int n = mat.size();
        
        // Create a visited matrix initialized to 0 (all cells are unvisited initially)
        vector<vector<int>>visited(n,vector<int>(n,0));
        
        // Vector to store all valid paths
        vector<string>ans;
        
        // String to store the current path
        string path = "";
        
        // Start exploring from the top-left corner (0, 0)
        solve(0,0,visited,mat,path,ans);
        
        // Return the vector of all valid paths
        return ans;
    }
};
