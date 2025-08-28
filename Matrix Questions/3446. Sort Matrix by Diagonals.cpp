**********************************************APPROACH 1st(USING SIMULATION)***************************************

class Solution {// Time Complexity = O(n² log n)                        Space Complexity = O(n)
public:
    // Function to sort a diagonal starting at (row, col)
    // "ascending = true" means sort diagonal in increasing order
    // "ascending = false" means sort diagonal in decreasing order
    void sortDiagonal(int row, int col, vector<vector<int>>& grid, int n, bool ascending) {
        int i = row;
        int j = col;

        vector<int> vec;

        // Step 1: Collect all elements of this diagonal
        while (i < n && j < n) {
            vec.push_back(grid[i][j]);
            i++;
            j++;
        }

        // Step 2: Sort the diagonal values
        if (ascending) 
        {
            // sort in ascending order
            sort(vec.begin(), vec.end());          
        } 
        else 
        {
            // sort in descending order
            sort(vec.rbegin(), vec.rend());        
        }

        // Step 3: Put the sorted values back into the diagonal
        i = row;
        j = col;
        for (auto &val : vec) 
        {
            grid[i][j] = val;
            i++;
            j++;
        }
    }

    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Step A: Sort diagonals starting from the first column (col = 0)
        // For these diagonals, sorting is done in descending order
        for (int row = 0; row < n; row++) 
        {
            sortDiagonal(row, 0, grid, n, false);
        }

        // Step B: Sort diagonals starting from the first row (row = 0)
        // For these diagonals, sorting is done in ascending order
        // Start from col=1 to avoid double-sorting the main diagonal
        for (int col = 1; col < n; col++) 
        {
            sortDiagonal(0, col, grid, n, true);
        }

        return grid;
    }
};

***********************************************APPROACH 2nd(USING MAP)**********************************************

class Solution {// Time ---> O(n × m × log(min(n, m)))                            Space ---> O(n × m)
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        // number of rows
        int n = grid.size(); 

        // number of columns         
        int m = grid[0].size();       

        // Map to store all diagonals: key = (i - j), value = vector of elements in that diagonal
        unordered_map<int,vector<int>> ump;

        // Step 1: Group elements by diagonals
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // diagonal index (same for all cells in a diagonal)
                int diagonal = i - j;   

                // store element in its diagonal bucket
                ump[diagonal].push_back(grid[i][j]);  
            }
        }

        // Step 2: Sort diagonals
        for(auto &it:ump)
        {
            if(it.first >= 0)
            {
                // For diagonals starting from first column (or main diagonal),
                // sort in ascending order
                sort(it.second.begin(), it.second.end());
            }
            else
            {
                // For diagonals starting from first row (except main diagonal),
                // sort in descending order
                sort(it.second.rbegin(), it.second.rend());
            }
        }

        // Step 3: Place sorted elements back into the grid
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // find which diagonal this cell belongs to
                int diagonal = i - j; 

                // take the last element from the sorted diagonal        
                grid[i][j] = ump[diagonal].back(); 

                // remove it to maintain correct order for next cell
                ump[diagonal].pop_back();          
            }
        }

        // Step 4: Return the modified grid
        return grid;
    }
};
