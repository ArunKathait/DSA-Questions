
class Solution {// TC ---> O(N^2)                                    SC ---> O(1)
public:

    // Function to rotate matrix by 90 degrees clockwise
    void rotateMatrix(vector<vector<int>>& mat)
    {
        int n = mat.size();      // number of rows
        int m = mat[0].size();   // number of columns (same as n since square matrix)

        // STEP 1: Transpose the matrix (convert rows → columns)
        // Swap mat[i][j] with mat[j][i]
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < m; j++)   // start from i to avoid double swapping
            {
                swap(mat[i][j], mat[j][i]);
            }
        }

        // STEP 2: Reverse each row
        // This converts transpose into 90° clockwise rotation
        for(int i = 0; i < n; i++)
        {
            reverse(mat[i].begin(), mat[i].end());
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        int m = mat[0].size();

        // Try all 4 possible rotations: 0°, 90°, 180°, 270°
        for(int k = 0; k <= 4; k++)
        {
            bool equal = true;   // assume matrices are equal initially

            // Compare mat with target
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(mat[i][j] != target[i][j])
                    {
                        equal = false;   // mismatch found
                        break;
                    }
                }
                if(!equal)
                {
                    break;  // stop checking further rows
                }
            }

            // If matrices match → return true
            if(equal == true)
            {
                return true;
            }

            // Rotate matrix by 90° for next check
            rotateMatrix(mat);
        }

        // If no rotation matches target
        return false;
    }
};

/*     

⏱️ Time Complexity
1. rotateMatrix(mat)
Transpose loop → O(n²)
Reverse each row → O(n²)
👉 Total = O(n²)
2. findRotation(mat, target)
Outer loop runs 4 times (for 0°, 90°, 180°, 270°)
Each time:
Compare matrices → O(n²)
Rotate matrix → O(n²)

👉 Per iteration = O(n²)
👉 Total = 4 × O(n²) = O(n²)

✅ Final Time Complexity

👉 O(n²)


📦 Space Complexity
No extra data structures used
Rotation is done in-place
Only a few variables (i, j, equal)

👉 O(1) (constant space)

*/
