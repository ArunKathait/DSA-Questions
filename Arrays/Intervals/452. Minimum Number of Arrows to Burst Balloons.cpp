
class Solution {// TC ---> O(n log n)                                           SC ---> O(1)
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        // Number of balloons
        int n = points.size();

        // Sort balloons by starting point first,
        // and then by ending point if starts are equal.
        //
        // Example:
        // [10,16], [2,8], [1,6]
        //
        // After sorting:
        // [1,6], [2,8], [10,16]
        sort(points.begin(), points.end());


        // 'prev' represents the current overlapping range
        // where one arrow can burst all balloons considered
        // so far.
        //
        // Initially, take the first balloon.
        vector<int> prev = points[0];

        // At least one arrow is required for the first balloon.
        int count = 1;


        // Start checking from the second balloon.
        for(int i = 1; i < n; i++)
        {
            // Current balloon's starting and ending position
            int currentStartPoint = points[i][0];
            int currentEndPoint = points[i][1];


            // Current overlapping range stored in 'prev'
            int prevStartPoint = prev[0];
            int prevEndPoint = prev[1];


            // ------------------------------------------------
            // CASE 1: NO OVERLAP
            // ------------------------------------------------
            //
            // If the current balloon starts AFTER the end
            // of the previous overlapping range,
            // there is no common point.
            //
            // Therefore, the current balloon cannot be
            // burst by the same arrow.
            if(currentStartPoint > prevEndPoint)
            {
                // We need another arrow.
                count++;

                // Start a new overlapping range
                // with the current balloon.
                prev = points[i];
            }


            // ------------------------------------------------
            // CASE 2: OVERLAP
            // ------------------------------------------------
            //
            // Current balloon overlaps with 'prev'.
            //
            // Therefore, one arrow can burst both.
            //
            // But we need to find the COMMON overlapping range.
            else
            {
                // The new starting point is the maximum
                // of the two starting points.
                //
                // Example:
                // prev     = [1,6]
                // current  = [2,8]
                //
                // Common range starts at max(1,2) = 2
                prev[0] = max(prevStartPoint, currentStartPoint);


                // The new ending point is the minimum
                // of the two ending points.
                //
                // prev     = [1,6]
                // current  = [2,8]
                //
                // Common range ends at min(6,8) = 6
                //
                // So common range = [2,6]
                prev[1] = min(prevEndPoint, currentEndPoint);
            }
        }


        // Return the minimum number of arrows required.
        return count;
    }
};
