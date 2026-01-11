
class Solution {// TC ---> O(n × m)                               SC ---> O(m)
public:

    // ----------------- Nearest Smaller to Left -----------------
    // For each bar, find the index of the nearest bar to the left
    // having strictly smaller height
    vector<int> getNSL(vector<int>& heights)
    {
        int n = heights.size();
        stack<int> st;              // stack stores indices
        vector<int> NSL(n);         // result array

        for(int i = 0; i < n; i++)
        {
            // Remove all bars which are >= current bar
            // because they cannot be NSL for current bar
            while(!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }

            // If stack becomes empty → no smaller bar on left
            NSL[i] = st.empty() ? -1 : st.top();

            // Push current index for future elements
            st.push(i);
        }
        return NSL;
    }

    // ----------------- Nearest Smaller to Right -----------------
    // For each bar, find the index of the nearest bar to the right
    // having strictly smaller height
    vector<int> getNSR(vector<int>& heights)
    {
        int n = heights.size();
        stack<int> st;
        vector<int> NSR(n);

        for(int i = n - 1; i >= 0; i--)
        {
            // Remove all bars which are >= current bar
            while(!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }

            // If stack is empty → no smaller bar on right
            NSR[i] = st.empty() ? n : st.top();

            // Push current index
            st.push(i);
        }
        return NSR;
    }

    // ----------------- Largest Rectangle in Histogram -----------------
    int findMaxArea(vector<int>& heights)
    {
        int n = heights.size();

        // Get nearest smaller elements
        vector<int> NSL = getNSL(heights);
        vector<int> NSR = getNSR(heights);

        int maxArea = 0;

        for(int i = 0; i < n; i++)
        {
            // Width of rectangle using heights[i] as minimum height
            // left boundary = NSL[i]
            // right boundary = NSR[i]
            int width = NSR[i] - NSL[i] - 1;

            // Area = height × width
            int area = width * heights[i];

            maxArea = max(maxArea, area);
        }
        return maxArea;
    }

    // ----------------- Maximal Rectangle in Binary Matrix -----------------
    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size();          // rows
        int m = matrix[0].size();       // columns

        vector<int> heights(m, 0);      // histogram heights
        int maxArea = 0;

        // Build histogram row by row
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == '1')
                {
                    // Increase height if consecutive '1'
                    heights[j] += 1;
                }
                else
                {
                    // Reset height if '0' appears
                    heights[j] = 0;
                }
            }

            // Calculate max rectangle area for current histogram
            maxArea = max(maxArea, findMaxArea(heights));
        }
        return maxArea;
    }
};
