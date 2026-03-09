
class Solution {// TC ---> O(1)                                    SC ---> O(1)
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2,int bx1, int by1, int bx2, int by2) {

        // ---------------------------------------------------
        // Rectangle A
        // Bottom-left corner  -> (ax1, ay1)
        // Top-right corner    -> (ax2, ay2)
        // ---------------------------------------------------

        // width of rectangle A
        int widthA = ax2 - ax1;

        // height of rectangle A
        int heightA = ay2 - ay1;

        // area of rectangle A
        int areaA = widthA * heightA;


        // ---------------------------------------------------
        // Rectangle B
        // Bottom-left corner  -> (bx1, by1)
        // Top-right corner    -> (bx2, by2)
        // ---------------------------------------------------

        // width of rectangle B
        int widthB = bx2 - bx1;

        // height of rectangle B
        int heightB = by2 - by1;

        // area of rectangle B
        int areaB = widthB * heightB;


        // ---------------------------------------------------
        // Now we find the overlapping rectangle (if it exists)
        // ---------------------------------------------------

        // The overlapping rectangle's left boundary
        // will be the maximum of both left edges
        int overlapLeft = max(ax1, bx1);

        // The overlapping rectangle's bottom boundary
        // will be the maximum of both bottom edges
        int overlapBottom = max(ay1, by1);

        // The overlapping rectangle's right boundary
        // will be the minimum of both right edges
        int overlapRight = min(ax2, bx2);

        // The overlapping rectangle's top boundary
        // will be the minimum of both top edges
        int overlapTop = min(ay2, by2);


        // ---------------------------------------------------
        // Calculate width and height of overlapping area
        // ---------------------------------------------------

        // If rectangles do not overlap, these values can become negative.
        // So we take max(0, value) to ensure overlap area becomes 0.

        int overlapWidth = max(0, overlapRight - overlapLeft);
        int overlapHeight = max(0, overlapTop - overlapBottom);


        // overlapping area
        int overlapArea = overlapWidth * overlapHeight;


        // ---------------------------------------------------
        // Total area covered by both rectangles
        // ---------------------------------------------------

        // We subtract overlapArea because it was counted twice
        int totalArea = areaA + areaB - overlapArea;

        return totalArea;
    }
};
