
class Solution {// TC--->O(N*M)log(N*M))                   SC--->O(N*M)
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        // Get the dimensions of the grid
        int n = grid.size();         // Number of rows
        int m = grid[0].size();      // Number of columns

        // Flattened 1D array to store all grid elements
        vector<int>vec;
        
        // Convert the 2D grid into a 1D vector
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // Store each element in vec
                vec.push_back(grid[i][j]);
            }
        }
 
        // Sort the vector to easily find the median
        sort(vec.begin(),vec.end());

        // Total number of elements in the grid
        int vecSize = vec.size();

        // The optimal target value is the median of the sorted list
        int target = vec[vecSize/2];

         // Variable to count the total operations
        int ans = 0;

        // Iterate through each element in the sorted list
        for(auto &num : vec)
        {
            // If any element in the grid has a remainder different from target % x, 
            // it's impossible to make all elements equal using steps of x.
            if(num%x != target%x)
            {
                // Not possible
                return -1;
            }

            // Calculate the number of operations needed to make num equal to target
            ans += abs(target - num)/x;
        }
        
        // Return the total number of operations
        return ans;
    }
};
