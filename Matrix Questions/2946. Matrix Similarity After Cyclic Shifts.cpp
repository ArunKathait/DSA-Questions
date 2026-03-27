
class Solution {// TC ---> O(N * M)                                    SC ---> O(1)
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {

        // n = number of rows, m = number of columns
        int n = mat.size();
        int m = mat[0].size();

        // Traverse each row
        for(int i = 0; i < n; i++)
        {
            // Traverse each column
            for(int j = 0; j < m; j++)
            {
                // CASE 1: Even indexed row (0,2,4...)
                if(i % 2 == 0)
                {
                    // LEFT SHIFT by k
                    // Instead of actually shifting, we check:
                    // "After left shift, which index should supply value to j?"
                    // That index = (j + k) % m

                    if(mat[i][j] != mat[i][(j + k) % m])
                    {
                        // If any element doesn't match → not similar
                        return false;
                    }
                }
                else
                {
                    // CASE 2: Odd indexed row (1,3,5...)
                    // RIGHT SHIFT by k

                    // For right shift, we move backwards:
                    // index = (j - k % m + m) % m

                    // Explanation:
                    // j - k → may become negative
                    // +m → make it positive
                    // %m → keep within bounds [0, m-1]

                    if(mat[i][j] != mat[i][(j - k % m + m) % m])
                    {
                        return false;
                    }
                }
            }
        }

        // If all elements match expected shifted positions
        return true;
    }
};
