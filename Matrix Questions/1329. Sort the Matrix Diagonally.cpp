
class Solution {// TC ---> O(n × m log(min(n,m)))                          SC ---> O(n × m)
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {

        // n = number of rows
        int n = mat.size();

        // m = number of columns
        int m = mat[0].size();

        // HashMap to store elements of each diagonal
        // key = (i - j) identifies a diagonal
        // value = all elements belonging to that diagonal
        unordered_map<int,vector<int>> ump;

        // STEP 1: Traverse matrix and store diagonal elements
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                // Elements with same (i - j) lie on same diagonal
                int key = (i - j);

                // Store matrix value in that diagonal group
                ump[key].push_back(mat[i][j]);
            }
        }

        // STEP 2: Sort every diagonal
        for(auto &it : ump)
        {
            // Sort the vector of elements for that diagonal
            sort(it.second.begin(), it.second.end());
        }

        // STEP 3: Put sorted values back into matrix
        // Traverse from bottom-right
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = m-1; j >= 0; j--)
            {
                int key = (i - j);

                // Take last element from sorted vector
                // (since we filled from reverse direction)
                mat[i][j] = ump[key].back();

                // Remove that element after using it
                ump[key].pop_back();
            }
        }

        // Return the sorted matrix
        return mat;
    }
};
