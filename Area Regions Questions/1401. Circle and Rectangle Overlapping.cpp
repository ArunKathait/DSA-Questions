
class Solution {// Time:  O(1)                         Space: O(1) 
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {

        // xi and yi will represent the closest point
        // on the rectangle to the circle's center
        int xi;
        int yi;

        // Find the closest x-coordinate on the rectangle

        // If circle center is to the left of the rectangle,
        // the closest x-coordinate is x1
        if(xCenter < x1)
        {
            xi = x1;
        }

        // If circle center is to the right of the rectangle,
        // the closest x-coordinate is x2
        else if(x2 < xCenter)
        {
            xi = x2;
        }

        // Otherwise, circle center is horizontally inside
        // the rectangle, so xCenter itself is the closest x
        else
        {
            xi = xCenter;
        }

        // Find the closest y-coordinate on the rectangle

        // If circle center is below the rectangle,
        // the closest y-coordinate is y1
        if(yCenter < y1)
        {
            yi = y1;
        }

        // If circle center is above the rectangle,
        // the closest y-coordinate is y2
        else if(y2 < yCenter)
        {
            yi = y2;
        }

        // Otherwise, circle center is vertically inside
        // the rectangle, so yCenter itself is the closest y
        else
        {
            yi = yCenter;
        }

        // Calculate the horizontal distance
        // between the circle center and closest point
        int dx = xi - xCenter;

        // Calculate the vertical distance
        // between the circle center and closest point
        int dy = yi - yCenter;

        // Using the distance formula:
        // distance² = dx² + dy²
        //
        // We compare squared distance with radius²
        // to avoid calculating sqrt().
        //
        // If distance² <= radius²,
        // the circle and rectangle overlap.
        return (dx * dx) + (dy * dy) <= radius * radius;
    }
};

/*

Simple intuition

Think of it as:

Circle center
      ●
      |
      | shortest distance
      |
      ■  ← closest point on rectangle

*/

********************************************APPROACH 2nd(USING CLAMP)*************************************************

class Solution {// Time  : O(1)                             Space : O(1)
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Find the closest point on the rectangle
        // to the circle's center
        int xi = clamp(xCenter, x1, x2);
        int yi = clamp(yCenter, y1, y2);

        // Calculate horizontal and vertical distance
        int dx = xi - xCenter;
        int dy = yi - yCenter;

        // Compare squared distance with squared radius
        return (dx * dx) + (dy * dy) <= radius * radius;
    }
};

/*

┌────────────────────────────────────────────┐
│       Circle + Rectangle Overlap           │
├────────────────────────────────────────────┤
│ KEY IDEA:                                  │
│ Find the closest point on rectangle to     │
│ the circle's center.                       │
│                                            │
│ clamp(value, low, high):                   │
│   value < low  → low                       │
│   value > high → high                      │
│   otherwise    → value                     │
│                                            │
│ xi = clamp(xCenter, x1, x2)                │
│ yi = clamp(yCenter, y1, y2)                │
│                                            │
│ dx = xi - xCenter                          │
│ dy = yi - yCenter                          │
│                                            │
│ distance² = dx² + dy²                      │
│                                            │
│ distance² <= radius² → OVERLAP ✅          │
│ distance² >  radius² → NO OVERLAP ❌       │
│                                            │
│ TC: O(1)                                   │
│ SC: O(1)                                   │
└────────────────────────────────────────────┘

*/
