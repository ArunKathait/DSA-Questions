
class Solution {// TC ---> O(rows*cols)                           SC ---> O(rows)
public:
    int minDeletionSize(vector<string>& strs) {

        // Number of strings (rows)
        int rows = strs.size();

        // Length of each string (columns)
        int cols = strs[0].size();

        // Stores how many columns we delete
        int deletions = 0;

        /*
         alreadySorted[i] = true means:
         strs[i] and strs[i+1] are already in correct order
         due to some previous column, so we don't need to
         compare them again.
        */
        vector<bool> alreadySorted(rows, false);

        // Traverse column by column (left to right)
        for (int col = 0; col < cols; col++) 
        {

            bool deleted = false; // tells whether current column is deleted

            // Check if this column breaks lexicographic order
            for (int row = 0; row < rows - 1; row++) 
            {

                /*
                 If this pair is NOT already sorted
                 and current column makes strs[row] > strs[row+1],
                 then this column must be deleted.
                */
                if (!alreadySorted[row] && strs[row][col] > strs[row + 1][col]) 
                    {

                    deletions++;   // delete this column
                    deleted = true;
                    break;         // stop checking further rows
                }
            }

            // If column is deleted, skip updating sorted pairs
            if (deleted) 
            {
                continue;
            }

            // Update alreadySorted for pairs that become sorted
            for (int i = 0; i < rows - 1; i++) 
            {

                /*
                 If character in upper string is smaller,
                 this pair is now permanently sorted.
                */
                alreadySorted[i] = alreadySorted[i] || (strs[i][col] < strs[i + 1][col]);
            }
        }

        // Return minimum number of deletions
        return deletions;
    }
};
