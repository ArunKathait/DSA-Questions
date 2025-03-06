
class Solution {// TC--->O(N^2)                  SC--->O(N^2)
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        // Get the size of the grid (n x n)
        int n = grid.size();
        
        // The maximum possible value in the grid (1 to n^2)
        int max_val = n*n;

        // Hash map to store the frequency of each number
        unordered_map<int,int>ump;

        // Traverse the entire grid and count the frequency of each number
        // Iterate through rows
        for(int i=0;i<n;i++)
        {
            // Iterate through columns
            for(int j=0;j<n;j++)
            {
                // Increment the count of the number in the hash map
                ump[grid[i][j]]++;
            }
        }
        
        // Variable to store the repeated number
        int repeated = -1;

        // Variable to store the missing number
        int missing = -1;

        // Iterate through all numbers from 1 to n^2 to find missing and repeated numbers
        for(int val=1;val<=max_val;val++)
        {
            // If a number appears twice, it's the repeated number
            if(ump[val] == 2)
            {
                repeated = val;
            }

            // If a number is missing from the hash map, it's the missing number
            if(ump[val] == 0)
            {
                missing = val;
            }
        }

        // Return the repeated and missing numbers as a vector
        return {repeated,missing};
    }
};
