
class Solution {// TC = O(1)                          SC = O(1)
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {

        /*
            Rectangle format:

            rec = [x1, y1, x2, y2]

            x1 = left
            y1 = bottom
            x2 = right
            y2 = top
        */


        /*
            CASE 1: rec1 is completely to the LEFT of rec2

            rec1's right edge <= rec2's left edge

                  rec1          rec2
                ┌─────┐       ┌─────┐
                │     │       │     │
                └─────┘       └─────┘
                   ↑             ↑
                rec1[2]       rec2[0]

            If rec1[2] <= rec2[0],
            there is no overlap.
        */
        bool leftOf = rec1[2] <= rec2[0];


        /*
            CASE 2: rec1 is completely BELOW rec2

            rec1's top edge <= rec2's bottom edge

                rec2
              ┌─────┐
              │     │
              └─────┘
                  ↑
              rec2[1]

              rec1
              ┌─────┐
              │     │
              └─────┘

            If rec1[3] <= rec2[1],
            there is no overlap.
        */
        bool below = rec1[3] <= rec2[1];


        /*
            CASE 3: rec1 is completely to the RIGHT of rec2

            rec1's left edge >= rec2's right edge

                rec2          rec1
              ┌─────┐       ┌─────┐
              │     │       │     │
              └─────┘       └─────┘

            If rec1[0] >= rec2[2],
            there is no overlap.
        */
        bool rightOf = rec1[0] >= rec2[2];


        /*
            CASE 4: rec1 is completely ABOVE rec2

            rec1's bottom edge >= rec2's top edge

                rec1
              ┌─────┐
              │     │
              └─────┘
                  ↑
              rec1[1]

                rec2
              ┌─────┐
              │     │
              └─────┘

            If rec1[1] >= rec2[3],
            there is no overlap.
        */
        bool above = rec1[1] >= rec2[3];


        /*
            If ANY of the four conditions is true,
            the rectangles do NOT overlap.

            So:

            noOverlap =
                leftOf OR
                below OR
                rightOf OR
                above

            But the question asks:
            "Do they overlap?"

            Therefore we use ! to reverse the result.

            !true  → false
            !false → true
        */

        return !(leftOf || below || rightOf || above);
    }
};

/*

Rectangle = [left, bottom, right, top]

NO OVERLAP if:

R1 right  <= R2 left
R1 top    <= R2 bottom
R1 left   >= R2 right
R1 bottom >= R2 top

If ANY is true:
    NO overlap

Otherwise:
    OVERLAP

Code:
return !(four_no_overlap_conditions);

TC = O(1)
SC = O(1)

╔════════════════════════════════════╗
║ 836 — RECTANGLE OVERLAP            ║
╠════════════════════════════════════╣
║ Check NO OVERLAP first:            ║
║                                    ║
║ 1. rec1 right <= rec2 left         ║
║ 2. rec1 top <= rec2 bottom         ║
║ 3. rec1 left >= rec2 right         ║
║ 4. rec1 bottom >= rec2 top         ║
║                                    ║
║ If ANY is true → NO overlap        ║
║                                    ║
║ Therefore:                         ║
║ return !(any_no_overlap);          ║
║                                    ║
║ TC: O(1)                           ║
║ SC: O(1)                           ║
╚════════════════════════════════════╝

*/
