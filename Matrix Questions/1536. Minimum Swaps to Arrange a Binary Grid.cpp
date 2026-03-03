
class Solution {// TC ---> O(N^2)                                SC ---> O(N)
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();

        // This will store how many trailing zeros each row has
        vector<int> trailingZeros(n, 0);

        // Step 1: Count trailing zeros for each row
        for(int i = 0; i < n; i++) 
        {
            int zeros = 0;
            int j = n - 1;

            // Move from right to left
            // Count consecutive zeros at the end
            while(j >= 0 && grid[i][j] == 0) 
            {
                zeros++;
                j--;
            }

            trailingZeros[i] = zeros;
        }
        
        int swaps = 0;

        // Step 2: Try to place correct row at each index i
        for(int i = 0; i < n; i++) 
        {
            // Required trailing zeros for row i
            int need = n - i - 1;

            int j = i;

            // Find a row below i that satisfies requirement
            while(j < n && trailingZeros[j] < need) 
            {
                j++;
            }

            // If no such row found → impossible
            if(j == n) 
            {
                return -1;
            }
            
            // Add number of swaps needed to bring row j to row i
            swaps += (j - i);

            // Bubble the row upward (simulate adjacent swaps)
            while(j > i) 
            {
                swap(trailingZeros[j], trailingZeros[j - 1]);
                j--;
            }
        }

        return swaps;
    }
};
