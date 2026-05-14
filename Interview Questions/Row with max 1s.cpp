*********************************************APPROACH 1st(BINARY SEARCH)*********************************************

class Solution {// TC ---> O(MlogN)                                          SC ---> O(1)
public:

    // Binary search to find first 1
    int firstOne(vector<int>& row)
    {
        int low = 0;
        int high = row.size() - 1;

        int ans = -1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            // Found 1
            if(row[mid] == 1)
            {
                ans = mid;

                // Search left side
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }

    int rowWithMax1s(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int maxCount = 0;
        int ans = -1;

        // Traverse every row
        for(int i = 0; i < m; i++)
        {
            // Find first 1
            int index = firstOne(matrix[i]);

            // If row contains 1
            if(index != -1)
            {
                int count = n - index;

                // Update maximum row
                if(count > maxCount)
                {
                    maxCount = count;
                    ans = i;
                }
            }
        }

        return ans;
    }
};

********************************************APPROACH 2nd(OPTIMAL)***************************************************

class Solution {
public:

    // TC ---> O(M + N)
    // SC ---> O(1)

    int rowWithMax1s(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        // Start from top-right corner
        int row = 0;
        int col = n - 1;

        // Stores answer row index
        int ans = -1;

        while(row < m && col >= 0)
        {
            // If current cell is 1
            if(matrix[row][col] == 1)
            {
                // Update answer
                ans = row;

                // Move left
                col--;
            }
            else
            {
                // Move down
                row++;
            }
        }

        return ans;
    }
};
