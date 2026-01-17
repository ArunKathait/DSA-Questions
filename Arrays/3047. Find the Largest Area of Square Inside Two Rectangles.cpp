
class Solution {// TC ---> O(N^2)                              SC ---> O(1)
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,vector<vector<int>>& topRight) {
        // Number of rectangles
        int n = bottomLeft.size();

        // Stores the maximum possible side length of a square
        int maxSide = 0;

        // Compare every pair of rectangles
        for (int i = 0; i < n; i++) 
        {
            for (int j = i + 1; j < n; j++) 
            {

                // ----------- X-axis overlap -----------
                // Right boundary of overlap
                int topRightX = min(topRight[i][0], topRight[j][0]);

                // Left boundary of overlap
                int bottomLeftX = max(bottomLeft[i][0], bottomLeft[j][0]);

                // Width of overlapping region
                int width = topRightX - bottomLeftX;

                // ----------- Y-axis overlap -----------
                // Upper boundary of overlap
                int topRightY = min(topRight[i][1], topRight[j][1]);

                // Lower boundary of overlap
                int bottomLeftY = max(bottomLeft[i][1], bottomLeft[j][1]);

                // Height of overlapping region
                int height = topRightY - bottomLeftY;

                // Largest square that can fit in the overlap
                int side = min(width, height);

                // Update maximum square side
                maxSide = max(maxSide, side);
            }
        }

        // Return area of the largest square
        return 1LL * maxSide * maxSide;
    }
};
