
class Solution {// Time Complexity ---> O(n*m * log(n+m))              Space Complexity ---> O(n*m)
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        // number of rows
        int n = mat.size(); 

        // number of columns      
        int m = mat[0].size();    

        // map to group elements by their diagonal index (i + j)
        // map<int, vector<int>> automatically keeps keys sorted (0,1,2,...)
        map<int, vector<int>> ump;
        
        // Group all matrix elements into diagonals
        // Each cell (i,j) goes into bucket (i+j)
        // Traverse the matrix
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                // diagonal index
                int index = i + j;  

                // put element in that diagonal group           
                ump[index].push_back(mat[i][j]); 
            }
        }
        
        // this flag tells us: reverse current diagonal or not
        bool flip = true;   

        // final result
        vector<int> ans;    

        // Iterate diagonals in order (map ensures 0 → n+m-2)
        // Traverse diagonals in increasing order of index
        // map guarantees sorted order of diagonals
        for (auto &it : ump) 
        {
            if (flip) 
            {
                // reverse the diagonal when flip = true
                reverse(it.second.begin(), it.second.end());
            }
            
            // add all elements of this diagonal to answer
            for (auto &val : it.second) 
            {
                ans.push_back(val);
            }

            // toggle flip for the next diagonal
            flip = !flip;
        }
        
        // final zigzag diagonal traversal
        return ans;   
    }
};
