
class Solution {// Time Complexity ---> O(n)                         Space Complexity ---> O(1)
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();   // number of rectangles given
        int maxDiagonal = 0;         // stores the maximum diagonal^2 found so far
        int maxArea = 0;             // stores the area of the rectangle with the max diagonal

        // iterate through each rectangle in the list
        for(auto &x:dimensions)
        {
            int length = x[0];       // rectangle length
            int width = x[1];        // rectangle width
            
            // instead of using sqrt, store the square of diagonal length
            // diagonal^2 = length^2 + width^2
            int diagonalLength = (length * length) + (width * width);

            // area of current rectangle
            int area = length * width;

            // Case 1: found a strictly larger diagonal
            if(maxDiagonal < diagonalLength)
            {
                maxDiagonal = diagonalLength;  // update max diagonal^2
                maxArea = area;                // update area of this rectangle
            }
            // Case 2: diagonals are equal → choose rectangle with larger area
            else if(maxDiagonal == diagonalLength)
            {
                maxArea = max(maxArea, area);
            }
        }
        // return the area of the rectangle with the longest diagonal
        // (and if tie, the one with the largest area)
        return maxArea;
    }
};
