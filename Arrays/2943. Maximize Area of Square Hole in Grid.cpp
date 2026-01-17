
class Solution {// TC ---> O(h log h + v log v)                        SC ---> O(1)
public:
    int maximizeSquareHoleArea(int n, int m,vector<int>& hBars,vector<int>& vBars) {

        // Sort the removed horizontal bars
        sort(hBars.begin(), hBars.end());

        // Sort the removed vertical bars
        sort(vBars.begin(), vBars.end());

        // These will store the maximum number of
        // consecutive removed bars in each direction
        int maxLength = 1;
        int maxWidth  = 1;

        // ----------------- HORIZONTAL BARS -----------------
        int length = 1; // current consecutive horizontal bars count

        for (int i = 1; i < hBars.size(); i++) 
        {
            // If current bar is consecutive to previous bar
            if (hBars[i] - hBars[i - 1] == 1) 
            {
                length++;   // extend the consecutive sequence
            } 
            else 
            {
                length = 1; // reset if not consecutive
            }
            // Update maximum horizontal sequence
            maxLength = max(maxLength, length);
        }

        // ----------------- VERTICAL BARS -----------------
        int width = 1; // current consecutive vertical bars count

        for (int j = 1; j < vBars.size(); j++) 
        {
            // If current bar is consecutive to previous bar
            if (vBars[j] - vBars[j - 1] == 1) 
            {
                width++;    // extend the consecutive sequence
            } 
            else 
            {
                width = 1;  // reset if not consecutive
            }
            // Update maximum vertical sequence
            maxWidth = max(maxWidth, width);
        }

        // The side of the largest square hole will be:
        // min(horizontal gaps, vertical gaps) + 1
        int side = min(maxLength, maxWidth) + 1;

        // Area of square = side * side
        return side * side;
    }
};
